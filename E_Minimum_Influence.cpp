#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
 
using namespace std;
 
const int INF = 2e9 + 7;
 
struct NewsItem {
    int p, c;
};
 
struct User {
    int tp, tc, d, id;
};
 
// K-D Tree Node for 2D Spatial Range Minimum queries
struct Node {
    int min_p, max_p;
    int min_c, max_c;
    int left, right;
    NewsItem point;
};
 
vector<NewsItem> items;
vector<Node> tree;
 
bool compareX(const NewsItem& a, const NewsItem& b) { return a.p < b.p; }
bool compareY(const NewsItem& a, const NewsItem& b) { return a.c < b.c; }
 
int buildTree(int l, int r, bool depth) {
    if (l > r) return 0;
    
    int mid = l + (r - l) / 2;
    if (depth) {
        nth_element(items.begin() + l, items.begin() + mid, items.begin() + r + 1, compareX);
    } else {
        nth_element(items.begin() + l, items.begin() + mid, items.begin() + r + 1, compareY);
    }
 
    int nodeIdx = tree.size();
    tree.push_back(Node());
    
    tree[nodeIdx].point = items[mid];
    tree[nodeIdx].min_p = tree[nodeIdx].max_p = items[mid].p;
    tree[nodeIdx].min_c = tree[nodeIdx].max_c = items[mid].c;
    
    int leftChild = buildTree(l, mid - 1, !depth);
    int rightChild = buildTree(mid + 1, r, !depth);
    
    tree[nodeIdx].left = leftChild;
    tree[nodeIdx].right = rightChild;
    
    if (leftChild) {
        tree[nodeIdx].min_p = min(tree[nodeIdx].min_p, tree[leftChild].min_p);
        tree[nodeIdx].max_p = max(tree[nodeIdx].max_p, tree[leftChild].max_p);
        tree[nodeIdx].min_c = min(tree[nodeIdx].min_c, tree[leftChild].min_c);
        tree[nodeIdx].max_c = max(tree[nodeIdx].max_c, tree[leftChild].max_c);
    }
    if (rightChild) {
        tree[nodeIdx].min_p = min(tree[nodeIdx].min_p, tree[rightChild].min_p);
        tree[nodeIdx].max_p = max(tree[nodeIdx].max_p, tree[rightChild].max_p);
        tree[nodeIdx].min_c = min(tree[nodeIdx].min_c, tree[rightChild].min_c);
        tree[nodeIdx].max_c = max(tree[nodeIdx].max_c, tree[rightChild].max_c);
    }
    
    return nodeIdx;
}
 
// Calculate precise influence of a single item on a user
inline int get_influence(const NewsItem& item, int tp, int tc, int d) {
    int ip = 0;
    if (item.p < tp) ip = 0;
    else if (item.p >= tp + d) ip = tp + d;
    else ip = item.p;
 
    int ic = 0;
    if (item.c < tc) ic = 0;
    else if (item.c >= tc + d) ic = tc + d;
    else ic = item.c;
 
    return ip + ic;
}
 
// Estimate the absolute theoretical minimum possible influence in a bounding box region
inline int get_min_possible(int nodeIdx, int tp, int tc, int d) {
    int min_ip = 0;
    if (tree[nodeIdx].min_p < tp) {
        min_ip = 0; // At least one item can achieve 0
    } else {
        min_ip = min(tree[nodeIdx].min_p, tp + d);
    }
 
    int min_ic = 0;
    if (tree[nodeIdx].min_c < tc) {
        min_ic = 0;
    } else {
        min_ic = min(tree[nodeIdx].min_c, tc + d);
    }
    return min_ip + min_ic;
}
 
int best_ans;
 
void query(int nodeIdx, int tp, int tc, int d) {
    if (!nodeIdx) return;
 
    // Pruning branch if this bounding box cannot possibly yield a better answer
    if (get_min_possible(nodeIdx, tp, tc, d) >= best_ans) return;
 
    // Evaluate current node point
    best_ans = min(best_ans, get_influence(tree[nodeIdx].point, tp, tc, d));
 
    // Guess which branch is more promising to explore first to accelerate pruning
    int left_est = tree[nodeIdx].left ? get_min_possible(tree[nodeIdx].left, tp, tc, d) : INF;
    int right_est = tree[nodeIdx].right ? get_min_possible(tree[nodeIdx].right, tp, tc, d) : INF;
 
    if (left_est < right_est) {
        query(tree[nodeIdx].left, tp, tc, d);
        query(tree[nodeIdx].right, tp, tc, d);
    } else {
        query(tree[nodeIdx].right, tp, tc, d);
        query(tree[nodeIdx].left, tp, tc, d);
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    if (!(cin >> n)) return 0;
 
    items.resize(n);
    for (int i = 0; i < n; i++) cin >> items[i].p;
    for (int i = 0; i < n; i++) cin >> items[i].c;
 
    // Dummy node at index 0
    tree.push_back(Node());
    int root = buildTree(0, n - 1, true);
 
    int m;
    cin >> m;
    vector<User> users(m);
    for (int i = 0; i < m; i++) cin >> users[i].tp;
    for (int i = 0; i < m; i++) cin >> users[i].tc;
    for (int i = 0; i < m; i++) cin >> users[i].d;
 
    for (int i = 0; i < m; i++) {
        best_ans = INF;
        query(root, users[i].tp, users[i].tc, users[i].d);
        cout << best_ans << "\n";
    }
 
    return 0;
}
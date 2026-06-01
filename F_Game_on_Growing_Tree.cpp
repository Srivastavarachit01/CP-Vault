#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
const int INF = 1e9;
 
struct Node {
    int mat[2][2];
    Node() {
        mat[0][0] = mat[0][1] = mat[1][0] = mat[1][1] = -INF;
    }
};
 
Node merge(const Node& a, const Node& b) {
    Node c;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                if (a.mat[i][k] > -INF && b.mat[k][j] > -INF) {
                    c.mat[i][j] = max(c.mat[i][j], a.mat[i][k] + b.mat[k][j]);
                }
            }
        }
    }
    return c;
}
 
int q;
vector<int> parent_node;
vector<vector<int>> adj;
vector<int> sz, heavy, head, pos, id_at_pos;
int cur_pos;
 
vector<int> g0, g1; 
vector<int> f0, f1;
vector<bool> active;
vector<Node> tree;
 
void dfs_sz(int v) {
    sz[v] = 1;
    for (int u : adj[v]) {
        dfs_sz(u);
        sz[v] += sz[u];
        if (heavy[v] == 0 || sz[u] > sz[heavy[v]]) {
            heavy[v] = u;
        }
    }
}
 
void decompose(int v, int h) {
    head[v] = h;
    pos[v] = ++cur_pos;
    id_at_pos[cur_pos] = v;
    if (heavy[v] != 0) {
        decompose(heavy[v], h);
    }
    for (int u : adj[v]) {
        if (u != heavy[v]) {
            decompose(u, u);
        }
    }
}
 
Node get_matrix(int v) {
    Node M;
    if (!active[v]) {
        M.mat[0][0] = 0;
        return M;
    }
    M.mat[0][0] = g0[v];
    M.mat[0][1] = g0[v];
    M.mat[1][0] = g0[v] + 1;
    if (g1[v] > -INF) {
        M.mat[0][0] = max(M.mat[0][0], g0[v] + g1[v]);
        M.mat[0][1] = max(M.mat[0][1], g0[v] + g1[v]);
    }
    return M;
}
 
void update_seg(int node, int start, int end, int idx) {
    if (start == end) {
        tree[node] = get_matrix(id_at_pos[idx]);
        return;
    }
    int mid = (start + end) / 2;
    if (idx <= mid) update_seg(2 * node, start, mid, idx);
    else update_seg(2 * node + 1, mid + 1, end, idx);
    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
}
 
Node query_seg(int node, int start, int end, int l, int r) {
    if (l <= start && end <= r) return tree[node];
    int mid = (start + end) / 2;
    if (r <= mid) return query_seg(2 * node, start, mid, l, r);
    if (l > mid) return query_seg(2 * node + 1, mid + 1, end, l, r);
    return merge(query_seg(2 * node, start, mid, l, r), query_seg(2 * node + 1, mid + 1, end, l, r));
}
 
void activate_vertex(int v) {
    active[v] = true;
    while (v != 0) {
        int h = head[v];
        int p = parent_node[h];
        
        update_seg(1, 1, q + 1, pos[v]);
        
        Node chain_mat = query_seg(1, 1, q + 1, pos[h], pos[v]);
        int next_f0 = max(chain_mat.mat[0][0], chain_mat.mat[0][1]);
        int next_f1 = max(chain_mat.mat[1][0], chain_mat.mat[1][1]);
        
        if (p != 0) {
            g0[p] -= max(f0[h], f1[h]);
        }
        
        f0[h] = next_f0;
        f1[h] = next_f1;
        
        if (p != 0) {
            g0[p] += max(f0[h], f1[h]);
            g1[p] = max(g1[p], f0[h] + 1 - max(f0[h], f1[h]));
        }
        v = p;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    if (!(cin >> q)) return 0;
 
    parent_node.resize(q + 2, 0);
    adj.resize(q + 2);
 
    for (int i = 1; i <= q; i++) {
        cin >> parent_node[i + 1];
        adj[parent_node[i + 1]].push_back(i + 1);
    }
 
    sz.resize(q + 2, 0);
    heavy.resize(q + 2, 0);
    head.resize(q + 2, 0);
    pos.resize(q + 2, 0);
    id_at_pos.resize(q + 2, 0);
    g0.resize(q + 2, 0);
    g1.resize(q + 2, -INF);
    f0.resize(q + 2, 0);
    f1.resize(q + 2, -INF);
    active.resize(q + 2, false);
 
    cur_pos = 0;
    dfs_sz(1);
    decompose(1, 1);
 
    tree.resize(4 * (q + 2));
    
    activate_vertex(1);
 
    for (int i = 1; i <= q; i++) {
        activate_vertex(i + 1);
        int ans = max(f0[1], f1[1]);
        cout << ans << (i == q ? "" : " ");
    }
    cout << "\n";
 
    return 0;
}
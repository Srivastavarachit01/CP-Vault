#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
 
using namespace std;
 
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    
    // Count the size of each block of identical elements
    map<int, int> block_counts;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        block_counts[a[i]]++;
    }
 
    // Extract all block sizes
    vector<int> sizes;
    for (auto const& [val, count] : block_counts) {
        sizes.push_back(count);
    }
 
    // Find all unique sizes sorted
    vector<int> u = sizes;
    sort(u.begin(), u.end());
    u.erase(unique(u.begin(), u.end()), u.end());
    u.insert(u.begin(), 0); // Include u_0 = 0
 
    int g = u.size() - 1;
    int ans = 0;
 
    // Iterate through all possible thresholds j
    for (int j = 0; j < g; j++) {
        int threshold = u[j + 1];
        long long C_j = 0;
        long long Sum_j = 0;
 
        for (int s : sizes) {
            if (s >= threshold) {
                C_j++;
                Sum_j += s;
            }
        }
 
        // C_j will always be > 0 because j < g guarantees at least the largest block survives
        if ((k - Sum_j) % C_j == 0) {
            long long F = (k - Sum_j) / C_j;
            if (F >= 1 - threshold) {
                ans++;
            }
        }
    }
 
    cout << ans << "\n";
}
 
int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}

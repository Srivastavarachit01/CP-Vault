#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    // B[i] tracks the prefix balance for the middle condition: (1 or 2) adds 1, 3 subtracts 1
    vector<int> B(n, 0);
    int current_balance = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 3) current_balance--;
        else current_balance++;
        B[i] = current_balance;
    }
 
    // suffix_max_B[i] stores the maximum value of B[j] for j in range [i, n-2]
    vector<int> suffix_max_B(n, -1e9);
    int max_so_far = -1e9;
    
    // The middle section can end at most at index n-2
    for (int i = n - 2; i >= 0; i--) {
        max_so_far = max(max_so_far, B[i]);
        suffix_max_B[i] = max_so_far;
    }
 
    int l_1 = 0, l_23 = 0;
    bool possible = false;
 
    // Iterate through all possible endings for the Left section
    // Left section can end anywhere from index 0 to n-3
    for (int left_end = 0; left_end <= n - 3; left_end++) {
        if (a[left_end] == 1) l_1++;
        else l_23++;
 
        // If the Left section condition is satisfied
        if (l_1 >= l_23) {
            // The middle section starts at left_end + 1
            // We need max(B[j]) for j in [left_end + 1, n - 2] to be >= B[left_end]
            if (suffix_max_B[left_end + 1] >= B[left_end]) {
                possible = true;
                break;
            }
        }
    }
 
    if (possible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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
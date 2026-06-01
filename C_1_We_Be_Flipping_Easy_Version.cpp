#include <iostream>
#include <vector>
 
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    vector<int> operations;
    int ops_count = 0;
 
    // Traverse the array from right to left
    for (int i = n - 1; i >= 0; i--) {
        long long current_val = a[i];
        
        // If the number of operations performed to the right is odd, 
        // the current element's sign is inverted.
        if (ops_count % 2 != 0) {
            current_val = -current_val;
        }
 
        // We want to minimize the sum, so if the element is positive, flip it.
        if (current_val > 0) {
            operations.push_back(i + 1); // 1-based indexing
            ops_count++;
        }
    }
 
    // Output results
    cout << operations.size() << "\n";
    for (int i = 0; i < operations.size(); i++) {
        cout << operations[i] << (i == operations.size() - 1 ? "" : " ");
    }
    cout << "\n";
}
 
int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
 
    return 0;
}

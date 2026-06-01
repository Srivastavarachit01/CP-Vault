#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
const long long INF = 4e18; // Safe infinity for calculations
 
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    vector<long long> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    vector<long long> c(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
 
    // condition check: c must be non-decreasing
    for (int i = 2; i <= n; i++) {
        if (c[i] < c[i - 1]) {
            cout << "No\n";
            return;
        }
    }
 
    vector<long long> L(n + 1, -INF);
    vector<long long> R(n + 1, INF);
 
    // Base constraints from the prefix maximum definition
    L[0] = 0;
    R[0] = 0;
    for (int i = 1; i <= n; i++) {
        R[i] = c[i];
        if (i == 1 || c[i] > c[i - 1]) {
            L[i] = c[i];
        }
    }
 
    // Backward propagation pass
    for (int i = n; i >= 1; i--) {
        if (s[i - 1] == '1') {
            // b_i = b_{i-1} + a_i => b_{i-1} = b_i - a_i
            if (R[i] != INF) {
                R[i - 1] = min(R[i - 1], R[i] - a[i]);
            }
            if (L[i] != -INF) {
                L[i - 1] = max(L[i - 1], L[i] - a[i]);
            }
        }
    }
 
    // Forward propagation pass
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '1') {
            // b_i = b_{i-1} + a_i
            if (R[i - 1] != INF) {
                R[i] = min(R[i], R[i - 1] + a[i]);
            }
            if (L[i - 1] != -INF) {
                L[i] = max(L[i], L[i - 1] + a[i]);
            }
        }
    }
 
    // Construct the prefix sum array b greedily using the upper bounds
    vector<long long> b(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (L[i] > R[i]) {
            cout << "No\n";
            return;
        }
        b[i] = R[i]; 
        if (s[i - 1] == '1') {
            b[i] = b[i - 1] + a[i];
        }
    }
 
    // Reconstruct the array a
    for (int i = 1; i <= n; i++) {
        a[i] = b[i] - b[i - 1];
    }
 
    // Final Validation Loop
    long long current_max = b[1];
    if (current_max != c[1]) {
        cout << "No\n";
        return;
    }
 
    for (int i = 2; i <= n; i++) {
        current_max = max(current_max, b[i]);
        if (current_max != c[i]) {
            cout << "No\n";
            return;
        }
    }
 
    cout << "Yes\n";
    for (int i = 1; i <= n; i++) {
        cout << a[i] << (i == n ? "" : " ");
    }
    cout << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
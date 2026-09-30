#include <iostream>
#include <vector>
 
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
 
    if (n == 1) {
        if (a[0] == b[0]) {
            cout << 0 << "\n";
        } else {
            cout << -1 << "\n";
        }
        return;
    }
 
    long long total_carries = 0;
    long long c_prev = 0; // Stores c_{i-1}
 
    
    const long long INF = 2e18; 
 
    for (int i = 0; i < n - 1; ++i) {
        
        if (c_prev > INF / 2) {
            cout << -1 << "\n";
            return;
        }
 
        long long c_i = a[i] + 2 * c_prev - b[i];
        
        
        if (c_i < 0) {
            cout << -1 << "\n";
            return;
        }
 
        
        if (INF - total_carries < c_i) {
            cout << -1 << "\n";
            return;
        }
 
        total_carries += c_i;
        c_prev = c_i;
    }
 
    
    if (c_prev > INF / 2 || a[n - 1] + 2 * c_prev != b[n - 1]) {
        cout << -1 << "\n";
    } else {
        cout << total_carries << "\n";
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
 
    return 0;
}

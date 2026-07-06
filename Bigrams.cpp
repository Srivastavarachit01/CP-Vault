#include <iostream>
#include <vector>
#include <numeric>
 
using namespace std;
 
void solve() {
    int k;
    cin >> k;
    vector<long long> c(k);
    
    int count_ge_3 = 0;
    int count_ge_2 = 0;
    
    for (int i = 0; i < k; ++i) {
        cin >> c[i];
        if (c[i] >= 3) {
            count_ge_3++;
        }
        if (c[i] >= 2) {
            count_ge_2++;
        }
    }
    
    // Condition 1: At least one character appears 3 or more times
    // Condition 2: At least two different characters appear 2 or more times
    if (count_ge_3 > 0 || count_ge_2 >= 2) {
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

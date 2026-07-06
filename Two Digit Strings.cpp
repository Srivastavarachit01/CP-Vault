#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
 
using namespace std;
 
void solve() {
    string a, b;
    cin >> a >> b;
    
    int n = a.length();
    int m = b.length();
    
    // Compute prefix sums modulo 10
    vector<int> prefA(n + 1, 0), prefB(m + 1, 0);
    for (int i = 0; i < n; i++) prefA[i + 1] = (prefA[i] + (a[i] - '0')) % 10;
    for (int j = 0; j < m; j++) prefB[j + 1] = (prefB[j] + (b[j] - '0')) % 10;
    
    // If the total sums of both strings modulo 10 do not match, it's impossible
    if (prefA[n] != prefB[m]) {
        cout << -1 << "\n";
        return;
    }
    
    // dp[i][j] stores the length of the longest common sequence of valid split points
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // Standard LCS transition
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            
            // If the prefix sums match, it means a valid block ending here can be formed
            if (prefA[i] == prefB[j]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }
    
    cout << dp[n][m] << "\n";
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

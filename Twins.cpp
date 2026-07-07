#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> coins(n);
    int total_sum = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
        total_sum += coins[i];
    }

    // Sort coins in descending order to greedily pick the largest ones first
    sort(coins.rbegin(), coins.rend());

    int my_sum = 0;
    int coin_count = 0;

    for (int i = 0; i < n; ++i) {
        my_sum += coins[i];
        coin_count++;
        
        // Check if my sum is strictly greater than the remaining sum
        if (my_sum > total_sum - my_sum) {
            break;
        }
    }

    cout << coin_count << "\n";

    return 0;
}
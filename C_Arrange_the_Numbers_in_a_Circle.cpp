#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
 
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    vector<long long> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
 
    // Since the input frequencies are already sorted: c[0] <= c[1] <= ... <= c[n-1]
    long long ans = 0;
 
    // Option 1: Use only the single most frequent card type
    if (c[n - 1] >= 3) {
        ans = max(ans, c[n - 1]);
    }
 
    // Option 2: Use exactly the two most frequent card types
    if (n >= 2) {
        long long two_types = c[n - 1] + c[n - 2];
        if (two_types >= 3) {
            ans = max(ans, two_types);
        }
    }
 
    // Option 3: Use a prefix/suffix of the largest elements to see 
    // if mixing 3 or more distinct elements can yield a larger total circle.
    if (n >= 3) {
        long long current_sum = 0;
        // We evaluate selecting the top k largest card types greedily
        for (int i = n - 1; i >= 0; i--) {
            current_sum += c[i];
            int elements_chosen = n - i;
            
            if (elements_chosen >= 3) {
                long long max_element_in_set = c[n - 1];
                long long sum_of_remaining_in_set = current_sum - max_element_in_set;
                
                long long valid_mixed_size = 0;
                if (max_element_in_set > sum_of_remaining_in_set + 2) {
                    // Capped by the maximum sandwich capability of the remaining elements
                    valid_mixed_size = 2 * sum_of_remaining_in_set + 2;
                } else {
                    // The elements are balanced enough to use the full sum of this subset
                    valid_mixed_size = current_sum;
                }
                
                if (valid_mixed_size >= 3) {
                    ans = max(ans, valid_mixed_size);
                }
            }
        }
    }
 
    cout << ans << "\n";
}
 
int main() {
    // Optimize standard input/output operations for execution speed
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
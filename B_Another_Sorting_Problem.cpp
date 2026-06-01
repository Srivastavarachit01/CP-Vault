#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    // Step 1: Check if already sorted
    bool already_sorted = true;
    long long max_drop = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            already_sorted = false;
            max_drop = max(max_drop, a[i] - a[i + 1]);
        }
    }
 
    if (already_sorted) {
        cout << "YES\n";
        return;
    }
 
    // Step 2: Our single mandatory candidate for k
    long long k = max_drop;
 
    // Step 3: Greedy simulation to see if this k can successfully sort the array
    vector<long long> modified_a(n);
    modified_a[0] = a[0]; // First element can start without adding k to keep it minimal
 
    for (int i = 1; i < n; i++) {
        // If the base value satisfies the non-decreasing condition, keep it minimal
        if (a[i] >= modified_a[i - 1]) {
            modified_a[i] = a[i];
        } 
        // Otherwise, we are forced to apply the +k operation
        else {
            modified_a[i] = a[i] + k;
        }
 
        // If even adding k doesn't fix the sorting violation, this k fails
        if (modified_a[i] < modified_a[i - 1]) {
            cout << "NO\n";
            return;
        }
    }
 
    // Step 4: Final verification pass
    for (int i = 0; i < n - 1; i++) {
        if (modified_a[i] > modified_a[i + 1]) {
            cout << "NO\n";
            return;
        }
    }
 
    cout << "YES\n";
}
 
int main() {
    // Maximize standard I/O speed for competitive programming
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
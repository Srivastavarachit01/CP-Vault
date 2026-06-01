#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
 
using namespace std;
 
struct State {
    long long value;
    int steps;
 
    bool operator<(const State& other) const {
        if (value != other.value) return value < other.value;
        return steps < other.steps;
    }
};
 
void solve() {
    int n;
    if (!(cin >> n)) return;
 
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    vector<State> all_states;
    // Estimated max states per element is small
    all_states.reserve(n * 70); 
 
    for (int i = 0; i < n; i++) {
        long long curr = a[i];
        int steps = 0;
 
        // Use a local map or sorted vector to keep track of what THIS specific 
        // element has already visited, ensuring we don't double-count loops.
        // Since the chain is small, a simple small vector + binary search is extremely fast.
        vector<long long> visited_by_this_element;
 
        while (true) {
            // Check if we've already seen this value for the current element
            if (binary_search(visited_by_this_element.begin(), visited_by_this_element.end(), curr)) {
                break; 
            }
 
            // Insert into local visited tracking (keep it sorted)
            visited_by_this_element.insert(
                lower_bound(visited_by_this_element.begin(), visited_by_this_element.end(), curr), 
                curr
            );
 
            // Record this valid state
            all_states.push_back({curr, steps});
 
            // Problem transition logic
            if (curr % 2 == 0) {
                curr /= 2;
            } else {
                curr += 1;
            }
            steps++;
        }
    }
 
    // Sort globally to group matching target values together
    sort(all_states.begin(), all_states.end());
 
    long long min_total_ops = -1;
    int i = 0;
    int total_elements = all_states.size();
 
    while (i < total_elements) {
        int j = i;
        long long current_value = all_states[i].value;
        long long current_sum_ops = 0;
        int count = 0;
 
        while (j < total_elements && all_states[j].value == current_value) {
            current_sum_ops += all_states[j].steps;
            count++;
            j++;
        }
 
        // Now 'count == n' strictly means exactly 'n' DISTINCT elements reached this value
        if (count == n) {
            if (min_total_ops == -1 || current_sum_ops < min_total_ops) {
                min_total_ops = current_sum_ops;
            }
        }
 
        i = j;
    }
 
    cout << min_total_ops << "\n";
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
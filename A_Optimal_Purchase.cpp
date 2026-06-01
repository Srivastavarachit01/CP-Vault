#include <iostream>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        long long n, a, b;
        cin >> n >> a >> b;
        
        long long groups = n / 3;
        long long rem = n % 3;
        
        long long cost = 0;
        
        // For each full group of 3: pick cheaper option
        cost += groups * min(3 * a, b);
        
        // For remainder (1 or 2 students): individual keys or group key
        if (rem > 0) {
            cost += min(rem * a, b);
        }
        
        cout << cost << "\n";
    }
    
    return 0;
}
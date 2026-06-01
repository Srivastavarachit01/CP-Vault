#include <iostream>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        
        // Count non-4 characters: only 1,2,3 can be kept
        // Kept string must be: [any 2s] then [any 1s and 3s]
        // i.e., no '2' can appear after a '1' or '3'
        
        // Try every split point i (0..n):
        // Left part [0..i-1]: keep all 2s
        // Right part [i..n-1]: keep all 1s and 3s
        // Total kept = (2s in left) + (1s+3s in right)
        // Answer = n - max_kept
        
        // Precompute suffix count of (1s+3s)
        vector<int> suf13(n+1, 0);
        for(int i = n-1; i >= 0; i--){
            suf13[i] = suf13[i+1] + (s[i]=='1' || s[i]=='3' ? 1 : 0);
        }
        
        int max_keep = 0;
        int twos = 0;
        for(int i = 0; i <= n; i++){
            max_keep = max(max_keep, twos + suf13[i]);
            if(i < n && s[i] == '2') twos++;
        }
        
        cout << n - max_keep << "\n";
    }
    
    return 0;
}
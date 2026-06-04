#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(auto &x : a) cin >> x;
        
        if(k >= 2){
            cout << "YES\n";
        } else {
            bool sorted = true;
            for(int i = 0; i < n-1; i++)
                if(a[i] > a[i+1]){ sorted = false; break; }
            cout << (sorted ? "YES" : "NO") << "\n";
        }
    }
    return 0;
}
→
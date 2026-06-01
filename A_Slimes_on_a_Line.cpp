#include<iostream>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        int mn = INT_MAX, mx = INT_MIN;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            mn = min(mn, a);
            mx = max(mx, a);
        }
        
        cout << (mx - mn + 1) / 2 << "\n";
    }
    
    return 0;
}
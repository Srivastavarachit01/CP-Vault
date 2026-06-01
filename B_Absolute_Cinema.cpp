#include <iostream>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        vector<long long> a(n), b(n);
        for(auto &x : a) cin >> x;
        for(auto &x : b) cin >> x;
        
        vector<long long> mn(n), mx(n);
        long long total = 0, S = 0;
        
        for(int i = 0; i < n; i++){
            mn[i] = min(a[i], b[i]);
            mx[i] = max(a[i], b[i]);
            total += a[i] + b[i];
            S += mn[i];
        }
        
        // prefix max and suffix max of mn[]
        vector<long long> pre(n, 0), suf(n, 0);
        pre[0] = mn[0];
        for(int i = 1; i < n; i++) 
            pre[i] = max(pre[i-1], mn[i]);
        suf[n-1] = mn[n-1];
        for(int i = n-2; i >= 0; i--) 
            suf[i] = max(suf[i+1], mn[i]);
        
        long long ans = LLONG_MIN;
        
        for(int j = 0; j < n; j++){
            long long max_mn_excl = 0;
            
            if(j == 0 && j == n-1){
                max_mn_excl = 0; // only one element
            } else if(j == 0){
                max_mn_excl = suf[1];
            } else if(j == n-1){
                max_mn_excl = pre[n-2];
            } else {
                max_mn_excl = max(pre[j-1], suf[j+1]);
            }
            
            long long diff = mx[j] - mn[j];
            long long cur_max_a = max(mx[j], max_mn_excl);
            long long cur_ans = cur_max_a + (total - S - diff);
            ans = max(ans, cur_ans);
        }
        
        // Base case: no flip
        long long base = pre[n-1] + (total - S);
        ans = max(ans, base);
        
        cout << ans << "\n";
    }
    
    return 0;
}
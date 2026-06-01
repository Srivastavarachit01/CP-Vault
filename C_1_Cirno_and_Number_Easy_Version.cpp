#include<iostrem>
using namespace std;
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    
    while(t--){
        ll a; int n;
        cin>>a>>n;
        ll d0,d1;
        cin>>d0>>d1;
        // d0 < d1 guaranteed (strictly increasing)
        
        ll ans = LLONG_MAX;
        string sa = to_string(a);
        int la = sa.size();
        
        for(int L=1; L<=18; L++){
            
            if(L != la){
                // All numbers of length L are either all < a or all > a
                // Just check smallest and largest of length L
                
                // Smallest of length L
                ll small;
                if(L==1){
                    small = d0;
                } else {
                    small = (d0>0 ? d0 : d1);
                    for(int i=1;i<L;i++) small = small*10 + d0;
                }
                
                // Largest of length L
                ll large = 0;
                for(int i=0;i<L;i++) large = large*10 + d1;
                
                ans = min(ans, abs(small - a));
                ans = min(ans, abs(large - a));
                continue;
            }
            
            // L == la: find floor (largest<=a) and ceil (smallest>=a)
            
            // --- CEIL ---
            {
                vector<ll> digits(L);
                bool tight=true, ok=true;
                
                for(int i=0;i<L;i++){
                    int need = sa[i]-'0';
                    if(!tight){
                        digits[i]=d0;
                        continue;
                    }
                    // find smallest digit >= need
                    ll chosen=-1;
                    if(d0>=need) chosen=d0;
                    else if(d1>=need) chosen=d1;
                    
                    if(chosen==-1){
                        // backtrack: find rightmost pos where we used d0->upgrade to d1
                        ok=false;
                        for(int j=i-1;j>=0;j--){
                            if(digits[j]==d0){
                                digits[j]=d1;
                                for(int k=j+1;k<L;k++) digits[k]=d0;
                                ok=true;
                                break;
                            }
                        }
                        break;
                    }
                    
                    digits[i]=chosen;
                    if(chosen>need) {
                        tight=false;
                        for(int k=i+1;k<L;k++) digits[k]=d0;
                        break;
                    }
                }
                
                if(ok){
                    if(L==1 || digits[0]!=0){
                        ll v=0;
                        for(int i=0;i<L;i++) v=v*10+digits[i];
                        ans=min(ans,abs(v-a));
                    }
                }
            }
            
            // --- FLOOR ---
            {
                vector<ll> digits(L);
                bool tight=true, ok=true;
                
                for(int i=0;i<L;i++){
                    int need = sa[i]-'0';
                    if(!tight){
                        digits[i]=d1;
                        continue;
                    }
                    // find largest digit <= need
                    ll chosen=-1;
                    if(d1<=need) chosen=d1;
                    else if(d0<=need) chosen=d0;
                    
                    if(chosen==-1){
                        // backtrack: find rightmost pos where we used d1->downgrade to d0
                        ok=false;
                        for(int j=i-1;j>=0;j--){
                            if(digits[j]==d1){
                                digits[j]=d0;
                                for(int k=j+1;k<L;k++) digits[k]=d1;
                                ok=true;
                                break;
                            }
                        }
                        break;
                    }
                    
                    digits[i]=chosen;
                    if(chosen<need){
                        tight=false;
                        for(int k=i+1;k<L;k++) digits[k]=d1;
                        break;
                    }
                }
                
                if(ok){
                    if(L==1 || digits[0]!=0){
                        ll v=0;
                        for(int i=0;i<L;i++) v=v*10+digits[i];
                        ans=min(ans,abs(v-a));
                    }
                }
            }
        }
        
        cout<<ans<<"\n";
    }
    return 0;
}

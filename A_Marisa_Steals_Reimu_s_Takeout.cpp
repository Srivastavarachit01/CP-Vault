#include<iostreamt>
using namespace std;
 
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int c0=0,c1=0,c2=0;
        for(int i=0;i<n;i++){
            int x;
            scanf("%d",&x);
            if(x==0) c0++;
            else if(x==1) c1++;
            else c2++;
        }
        int ans = c0;
        int p = min(c1,c2);
        ans += p;
        c1 -= p; c2 -= p;
        ans += c1/3;
        ans += c2/3;
        printf("%d\n",ans);
    }
    return 0;
}
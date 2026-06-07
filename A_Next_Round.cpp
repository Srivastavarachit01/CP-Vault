#include<iostream>>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(auto&x:a) cin>>x;
    int threshold=a[k-1];
    int ans=0;
    for(auto x:a) if(x>=threshold && x>0) ans++;
    cout<<ans;
}
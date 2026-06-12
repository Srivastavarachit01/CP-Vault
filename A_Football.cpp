#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int cnt0=0,cnt1=0,mx0=0,mx1=0;
    for(char c:s){
        if(c=='0'){cnt0++;cnt1=0;}
        else{cnt1++;cnt0=0;}
        mx0=max(mx0,cnt0);
        mx1=max(mx1,cnt1);
    }
    cout<<(mx0>=7||mx1>=7?"YES":"NO");
}

#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int c1=0,c2=0,c3=0;
    for(char c:s) if(c=='1')c1++; else if(c=='2')c2++; else if(c=='3')c3++;
    string res="";
    while(c1--) res+=(res.empty()?"1":"+1");
    while(c2--) res+=(res.empty()?"2":"+2");
    while(c3--) res+=(res.empty()?"3":"+3");
    cout<<res<<"\n";
}
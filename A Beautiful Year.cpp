#include<iostream>
using namespace std;

int main(){
    int y; cin>>y;
    for(int x=y+1;;x++){
        int a=x/1000, b=x/100%10, c=x/10%10, d=x%10;
        if(a!=b && a!=c && a!=d && b!=c && b!=d && c!=d){
            cout<<x; return 0;
        }
    }
}
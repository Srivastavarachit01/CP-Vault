#include<iostream>
using namespace std;
 
int main() {
int n,m;
 
cin>>n>>m;
 
int days =n;
 
while(n>=m);
days+=n/m;
 
n=(n/m) + (n%m) ;
 
cout << days << endl;
 
return 0;
}
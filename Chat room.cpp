#include<iostream>
using namespace std;
int main(){
    string s, t = "hello";
    cin >> s;
    int j = 0;
    for(int i = 0; i < s.size() && j < 5; i++)
        if(s[i] == t[j]) j++;
    cout << (j == 5 ? "YES" : "NO");
}
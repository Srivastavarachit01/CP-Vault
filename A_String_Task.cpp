#include <iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    string vowels = "aoueyui";
    string res = "";
    for(char c : s){
        c = tolower(c);
        if(vowels.find(c) == string::npos){
            res += '.';
            res += c;
        }
    }
    cout << res << endl;
}
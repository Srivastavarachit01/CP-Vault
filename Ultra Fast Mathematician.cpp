#include <iostream>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    string res = "";
    for (int i = 0; i < a.size(); i++) {
        res += (a[i] != b[i]) ? '1' : '0';
    }
    cout << res << endl;
}
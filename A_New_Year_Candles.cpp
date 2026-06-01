#include <iostream>
using namespace std;
 
int main() {
    int n, m;
    cin >> n >> m;
 
    int total = n;
    int stubs = n;
 
    while(stubs >= m) {
        int newCandles = stubs / m;
        total += newCandles;
        stubs = newCandles + (stubs % m);
    }
 
    cout << total << endl;
 
    return 0;
}
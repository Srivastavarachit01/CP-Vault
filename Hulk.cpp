#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << (i % 2 == 1 ? "I hate" : "I love") << " ";
        cout << (i == n ? "it" : "that ");
    }
    cout << "\n";
    return 0;
}
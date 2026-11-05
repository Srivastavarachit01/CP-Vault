#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, p, q, x;
    cin >> n;
    set<int> s;
    cin >> p;
    while (p--) { cin >> x; s.insert(x); }
    cin >> q;
    while (q--) { cin >> x; s.insert(x); }
    if ((int)s.size() == n)
        cout << "I become the guy.";
    else
        cout << "Oh, my keyboard!";
    return 0;
}
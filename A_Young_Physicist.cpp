#include<iostream>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    long long sx = 0, sy = 0, sz = 0;
    for (int i = 0; i < n; i++) {
        long long x, y, z;
        cin >> x >> y >> z;
        sx += x;
        sy += y;
        sz += z;
    }

    cout << ((sx == 0 && sy == 0 && sz == 0) ? "YES" : "NO") << endl;

    return 0;
}
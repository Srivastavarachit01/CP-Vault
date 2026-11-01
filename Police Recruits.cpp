#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    int officers = 0;
    int untreated = 0;

    for (int i = 0; i < n; i++) {
        int event;
        cin >> event;
        if (event == -1) {
            if (officers > 0) {
                officers--;
            } else {
                untreated++;
            }
        } else {
            officers += event;
        }
    }

    cout << untreated << "\n";
    return 0;
}
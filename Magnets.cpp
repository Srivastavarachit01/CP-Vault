#include <iostream>
using namespace std;
 
int main() {
    int n;
    scanf("%d", &n);
    string prev, cur;
    int groups = 0;
    for (int i = 0; i < n; i++) {
        cin >> cur;
        if (i == 0 || cur != prev) groups++;
        prev = cur;
    }
    printf("%d\n", groups);
}
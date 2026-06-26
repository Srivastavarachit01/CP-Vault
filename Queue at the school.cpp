#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    
    string s;
    cin >> s;
    
    // Har ek second ke liye loop chalao
    for (int second = 0; second < t; second++) {
        for (int i = 0; i < n - 1; i++) {
            // Agar ladka ladki ke aage hai, toh swap karo
            if (s[i] == 'B' && s[i + 1] == 'G') {
                swap(s[i], s[i + 1]);
                i++; // Taaki yeh same ladka isi second mein firse aage na bade
            }
        }
    }
    
    // Final arrangement print karo
    cout << s << endl;
    
    return 0;
}
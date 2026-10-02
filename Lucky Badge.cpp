#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Function 1: Check if character is vowel
bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

// Function 2: Solve single testcase
void solve() {
    string s;
    cin >> s;

    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }

    int oddCount = 0;
    char oddChar = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 != 0) {
            oddCount++;
            oddChar = 'a' + i;
        }
    }

    if (oddCount > 1) {
        cout << "NO\n";
        return;
    }

    string origVowels = "", origConsonants = "";
    for (char c : s) {
        if (isVowel(c)) origVowels += c;
        else origConsonants += c;
    }

    string left = "";
    vector<int> leftUsed(26, 0);

    for (char c : s) {
        int idx = c - 'a';
        if (leftUsed[idx] < freq[idx] / 2) {
            left += c;
            leftUsed[idx]++;
        }
    }

    string right = left;
    reverse(right.begin(), right.end());

    string p = left;
    if (oddCount == 1) {
        p += oddChar;
    }
    p += right;

    string pVowels = "", pConsonants = "";
    for (char c : p) {
        if (isVowel(c)) pVowels += c;
        else pConsonants += c;
    }

    if (pVowels == origVowels && pConsonants == origConsonants) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

// Function 3: Main function
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
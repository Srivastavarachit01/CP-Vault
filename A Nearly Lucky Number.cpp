#include <iostream>
#include <string>

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string n;
    std::cin >> n;

    int luckyDigitCount = 0;

    // Count occurrences of '4' and '7'
    for (char digit : n) {
        if (digit == '4' || digit == '7') {
            luckyDigitCount++;
        }
    }

    // Since the maximum length of n is 18 digits, 
    // the only lucky numbers the count can match are 4 or 7.
    if (luckyDigitCount == 4 || luckyDigitCount == 7) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }

    return 0;
}
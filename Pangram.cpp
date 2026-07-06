#include <iostream>
#include <string>
#include <unordered_set>
#include <cctype>
 
int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
 
    int n;
    std::cin >> n;
    
    std::string s;
    std::cin >> s;
 
    // A pangram must have at least 26 characters
    if (n < 26) {
        std::cout << "NO\n";
        return 0;
    }
 
    std::unordered_set<char> unique_letters;
    for (char c : s) {
        // Convert to lowercase and insert into the set
        unique_letters.insert(std::tolower(c));
    }
 
    // If we collected all 26 distinct alphabets
    if (unique_letters.size() == 26) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
 
    return 0;
}
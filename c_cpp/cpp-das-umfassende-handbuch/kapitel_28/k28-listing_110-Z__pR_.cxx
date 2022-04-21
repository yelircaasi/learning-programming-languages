#include <regex>
#include <string>
#include <iostream>
using std::regex; using std::regex_match; using std::regex_search;
int main() {
    std::cout << std::boolalpha;
    regex muster {"ello"};
    std::string text = "Hello world";
    auto b1 = regex_match (text.cbegin(), text.cend(), muster); // passt nicht
    std::cout << b1 << "\n"; // Ausgabe: false
    auto b2 = regex_search(text.cbegin(), text.cend(), muster); // gefunden
    std::cout << b2 << "\n"; // Ausgabe: true
}


#include <regex>
#include <string>
#include <iostream>
using std::string;
int main() {
    string text = "Titel;Album;Interpret";
    std::regex muster{";"};
    string neu = std::regex_replace(text, muster, string{","});
    std::cout << neu << "\n"; // Ausgabe: Titel,Album,Interpret
}


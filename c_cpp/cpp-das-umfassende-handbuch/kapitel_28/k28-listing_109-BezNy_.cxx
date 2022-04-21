#include <string>
#include <iostream>
#include <regex>
using std::regex; using std::sregex_iterator; using std::string;
const regex rgxMobile(R"(01[567]\d{6,10})");        // Handy 0151-0179
bool isMobilephone(const string& text) {
  return std::regex_match(text, rgxMobile);         // Passt text ganz?
}
bool containsMobilephone(const string &text) {
  return std::regex_search(text, rgxMobile);        // irgendwo in text?
}
void listMobilephones(const string &text) {
  sregex_iterator begin{ text.cbegin(), text.cend(), rgxMobile };
  sregex_iterator end;
  for(auto it = begin; it != end; ++it)
    std::cout << it->str() << " ";                  // Treffertext
} // "xyz01709999 abc 0161887766 uvw" -> "01709999 161887766"


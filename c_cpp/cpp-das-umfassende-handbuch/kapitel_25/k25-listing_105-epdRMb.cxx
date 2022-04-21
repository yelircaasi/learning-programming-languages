#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using std::string;

auto istPalindrom = [](const auto &s) {
  return std::equal(s.begin(), s.end(), s.rbegin()); };

int main() {
  for(string s : {"regallager", "rentner", "blutwurst" }) {
    std::cout << s << " ist " << (istPalindrom(s)?"ein":"kein") << " Palindrom\n";
  }
}


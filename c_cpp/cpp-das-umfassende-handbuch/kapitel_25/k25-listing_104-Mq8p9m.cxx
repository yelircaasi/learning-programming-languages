#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using std::vector; using std::string; using std::find_if;

vector<string> split(const string& s) {
  vector<string> result{};
  auto it = s.begin();
  while(it != s.end()) {
    it = find_if(it, s.end(), [](char c) { return c!=' '; }); // bis normales Zeichen
    auto jt = find_if(it, s.end(), [](char c) { return c==' '; }); // bis Leerzeichen
    if(it!=s.end())
      result.push_back(string(it, jt)); // Kopie ins Ergebnis
    it = jt;
  }
  return result;
}

int main() {
  auto res = split("Der Text ist kurz");
  std::for_each(res.begin(), res.end(), [](const string &e) {
      std::cout << "[" << e << "] "; });
  std::cout << '\n'; // Ausgabe: [Der] [Text] [ist] [kurz]
}


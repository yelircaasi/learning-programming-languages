#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm> // sort
using std::tuple; using std::get; using std::cout; using std::string;

int main() {
    std::vector<tuple<string,string,int>> armstrongs =
      { {"Armstrong", "Louis", 1901}  // Initialisieren per Initialisierungsliste
      , {"Armstrong", "Lance", 1971}
      , {"Armstrong", "Neil", 1930} };
    std::sort( armstrongs.begin(), armstrongs.end() ); // Lance < Louis < Neil
    for(const auto& a : armstrongs) {
      cout << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a) << "\n";
    }
}


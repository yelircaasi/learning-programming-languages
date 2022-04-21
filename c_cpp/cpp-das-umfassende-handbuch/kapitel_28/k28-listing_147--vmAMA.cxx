#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <functional>

std::map<char,std::function<int(int,int)>> binOps { // zweistellige Operatoren
    {'+', std::plus<int>{} },
    {'-', std::minus<int>{} },
    {'*', std::multiplies<int>{} },
    {'/', std::divides<int>{} },
    {'%', std::modulus<int>{} },
    };

std::map<char,std::function<int(int)>> unOps { };   // einstellige Operatoren

auto val = [](auto n) { return [n](){ return n; };};// Lambda gibt ein Lambda zurück
std::map<char,std::function<int()>> zeroOps {       // nullstellige Operatoren
  {'0', val(0)}, {'1', val(1)}, {'2', val(2)}, {'3', val(3)}, {'4', val(4)},
  {'5', val(5)}, {'6', val(6)}, {'7', val(7)}, {'8', val(8)}, {'9', val(9)},
  };

std::map<char,std::function<void(std::vector<int>&)>> stapelOps { // ganzer Stapel
  { ' ', [](auto &stapel) { } },                    // keine Operation
  { 'c', [](auto &stapel) { stapel.clear(); } },    // Stapel ganz löschen
  { ':', [](auto &stapel) {                   // obersten zwei Elemente vertauschen
            auto top = stapel.back(); stapel.pop_back();
            auto second = stapel.back(); stapel.pop_back();
            stapel.push_back(top);
            stapel.push_back(second);
  } },
  { '=', [](auto &stapel) {                   // ganzen Stapel ausgeben
            for(int elem : stapel) { std::cout << elem; }
            std::cout << "\n";
  } },
};
void rechner(std::string input) {
  std::vector<int> stapel {};
  for(char c : input) {
    int top, second;
    if(auto it = unOps.find(c); it != unOps.end()) {
      // falls einstelliger Operator ...
      auto func = it->second;
      top = stapel.back(); stapel.pop_back(); // ... hole oberstes Element
      stapel.push_back(func(top));            // ... wende func an, Ergebnis auf Stapel
    } else if(auto it = binOps.find(c); it != binOps.end()) {
      // falls zweistelliger Operator ...
      auto func = it->second;
      top = stapel.back(); stapel.pop_back(); // ... hole obersten beiden Elemente
      second = stapel.back(); stapel.pop_back();
      stapel.push_back(func(second, top));    // ... wende func an, Ergebnis auf Stapel
    } else if(auto it = zeroOps.find(c); it !=zeroOps.end()) {
      // falls nullstelliger Operator ...
      auto func = it->second;
      stapel.push_back(func());               // ... Ergebnis von func auf Stapel
    } else if(auto it = stapelOps.find(c); it !=stapelOps.end()) {
      // falls Stapeloperator
      auto func = it->second;
      func(stapel);                           // ... wende func auf Stapel an
    } else {
      std::cout << "\n'" << c << "' verstehe ich nicht.\n";
    }
  } /* for c */
}
int main(int argc, const char* argv[]) {
    if(argc > 1) {
        rechner(argv[1]);
    } else {
        // 3+4*5+6 mit Punkt- vor Strichrechnung ergibt 29
        rechner("345*+6+=");
    }
    rechner("93-=");                     // 9 - 3 = Ausgabe: 6
    rechner("82/=");                     // 8 / 2 = Ausgabe: 4
    rechner("92%=");                     // 9 % 2 = Ausgabe: 1
}


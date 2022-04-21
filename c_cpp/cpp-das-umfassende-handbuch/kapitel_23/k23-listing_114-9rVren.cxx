#include <iostream>                   // cout
using std::cout;
class Inkrement {
   int menge_;
public:
    explicit Inkrement(int menge) : menge_{menge} {}
    int operator()(int wert) const  { // macht Instanzen aufrufbar
        return wert + menge_;
    }
    void clear() {
        menge_ = 0;
    }
};
int main() {
    Inkrement plusVier{4};               // Instanz erzeugen
    Inkrement plusElf{11};               // noch eine Instanz
    cout << plusVier(8) << "\n";         // Ausgabe: 12
    int erg = 2 * plusElf(5) - 7;        // erg ist 25
    cout << plusElf(erg/5) << "\n";      // Ausgabe: 16
    cout << 3 * Inkrement{1}(7) << "\n"; // Ausgabe: 24
    Inkrement plusNix = plusElf;
    plusNix.clear();                     // Zustand ändern
    cout << plusNix(1) << "\n";          // Ausgabe: 1
}


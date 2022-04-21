#include <iostream>              // cout
using std::cout;

class Hinzu {
   int menge_;
public:
    explicit Hinzu(int menge) : menge_{menge} {}
    int hinzu(int wert) const  { // statt operator()
        return wert + menge_;
    }
    void clear() {
        menge_ = 0;
    }
};
int main() {
    Hinzu plusVier{4};                      // Instanz erzeugen
    Hinzu plusElf{11};                      // noch eine Instanz
    cout << plusVier.hinzu(8) << "\n";      // Ausgabe: 12
    int erg = 2 * plusElf.hinzu(5) - 7;     // erg ist 25
    cout << plusElf.hinzu(erg/5) << "\n";   // Ausgabe: 16
    cout << 3 * Hinzu{1}.hinzu(7) << "\n";  // Ausgabe: 24
    Hinzu plusNix = plusElf;
    plusNix.clear();                        // Zustand ändern
    cout << plusNix.hinzu(1) << "\n";       // Ausgabe: 1
}


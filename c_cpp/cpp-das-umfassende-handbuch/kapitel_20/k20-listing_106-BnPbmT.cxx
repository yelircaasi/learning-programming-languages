#include <vector>
#include <numeric>   // iota
#include <iostream>
using std::vector; using std::cout;
struct Zahl {        // stellvertretend für ein großes, teures Objekt
    unsigned long val_;
    Zahl(unsigned long val) : val_{val} {}
    Zahl() : val_{0} {}
};
/* ermittelt anhand bisheriger Primzahlen, ob z eine Primzahl ist */
bool isPrim(const Zahl& z, const vector<Zahl*> prims) {
    for(Zahl* p : prims) {
        if((p->val_*p->val_) > z.val_) return true;   // zu groß
        if(z.val_ % p->val_ == 0) return false;       // ist Teiler
    }
    return true;
}
int main() {
    vector<Zahl> alleZahlen(98);   // 98 mit null initialisierte Elemente
    std::iota(begin(alleZahlen), end(alleZahlen), 3); // 3..100
    /* alleZahlen enthält jetzt {3..100} */
    vector<Zahl*> prims{};         // bekommt ermittelte Primzahlen
    Zahl zwei{2};
    prims.push_back(&zwei);        // die 2 wird gebraucht
    for(Zahl &z : alleZahlen) {    // über alle Zahlen iterieren
        if(isPrim(z, prims)) {
            prims.push_back( &z ); // speichere Adresse
        }
    }
    /* Rest ausgeben */
    for(Zahl* p : prims)
        cout << p->val_ << " ";
    cout << "\n";
}


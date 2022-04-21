#include <iostream>
using std::cout;
class Saeugetier {
public:
    void gebaere() { cout << "Geburt!\n"; }
};
class Fliegend {
public:
    void fliege() { cout << "Flug!\n"; }
};
class Fledermaus: public Saeugetier, public Fliegend {
public:
    void rufe() { cout << "Ultraschall!\n"; }
};
int main() {
    Fledermaus bruce{};
    bruce.gebaere();       // Ausgabe: Geburt!
    bruce.fliege();        // Ausgabe: Flug!
    bruce.rufe();          // Ausgabe: Ultraschall!
}


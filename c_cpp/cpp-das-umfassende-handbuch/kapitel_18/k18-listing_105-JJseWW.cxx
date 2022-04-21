#include <iostream>
using std::cout; using std::ostream;
class Basis {
    public: int daten = 5;
};
class Mitte : private Basis {
protected: void drucke() {
        cout << daten; // 'daten' ist hier privat geerbt
    }
};
class Letztendlich : public Mitte {
    public: void los() {
        // 'daten' ist nicht sichtbar
        drucke(); // 'drucke' ist geschützt sichtbar
    }
};
int main() {
    Letztendlich l {};
    l.los(); // Ausgabe: 5
}


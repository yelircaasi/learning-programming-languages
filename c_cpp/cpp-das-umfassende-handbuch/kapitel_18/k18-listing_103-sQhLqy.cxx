#include <iostream>
using std::cout; using std::ostream;
// ... wie zuvor ...
int main() {
    // öffentlich erben
    DerivedPublic dpu{};
    cout << dpu.xPublic << '\n';    // Ausgabe: 1
    cout << dpu.xProtected << '\n'; // kein Zugriff von außen

    // geschützt erben
    DerivedProtected dpt{};
    cout << dpt.xPublic << '\n';    // kein Zugriff von außen
    cout << dpt.xProtected << '\n'; // kein Zugriff von außen

    // private erben
    DerivedPrivate dpv{};
    cout << dpv.xPublic << '\n';    // kein Zugriff von außen
    cout << dpv.xProtected << '\n'; // kein Zugriff von außen
}


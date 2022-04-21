#include <iostream>

using std::cout; using std::ostream;
struct Widget {
    bool operator<(const Widget&) {            // Methodenschreibweise
        return true;                           // immer true
    }
};
bool operator<(const Widget&, const Widget&) { // Funktionsschreibweise
    return false;                              // immer false
}
int main() {
    Widget x{};
    Widget y{};
    cout << (operator<(x, y)       // ruft Funktionsschreibweise auf
        ? "Methode1\n" : "Funktion1\n");
    cout << (y.operator<(x)        // ruft Methodenschreibweise auf
        ? "Methode2\n" : "Funktion2\n");
    cout << (x < y                 // Infix-Schreibweise, lässt die Wahl, hier Methode
        ? "Methode3\n" : "Funktion3\n");
}


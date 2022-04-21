#include <iostream>
#include <iomanip>                              // fixed, setprecision
using std::cout;                                // abgekürzt cout
int main() {
    cout << std::setprecision(2) << std::fixed; // zwei Nachkommastellen anzeigen
    cout << "1/4: " << 0.25 << "\n";            // Kommaschreibweise für double
    // Ausgabe: 1/4: 0.25

    cout << "2/4: " << 0.5 << "\n";
    // Ausgabe: 2/4: 0.50
    cout << "3/4: " << 0.75 << "\n";
    // Ausgabe: 2/4: 0.75
    cout << "4/4: " << 1 << " oder " << 1.0 << "\n"; // erkennt 1 als int
    // Ausgabe: 1 oder 1.00
    cout << "1e0: " << 1e0 << "\n";             // wissenschaftliche Schreibweise
    // Ausgabe: 1e0: 1.00
    cout << "0x10.1p0: " << 0x10.1p0 << "\n";   // hexadezimale Schreibweise
    // Ausgabe: 0x10.1p0: 16.06
}


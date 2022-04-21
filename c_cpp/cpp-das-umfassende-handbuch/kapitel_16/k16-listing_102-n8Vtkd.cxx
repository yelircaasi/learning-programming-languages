#include <string>
#include <iostream>
#include <iomanip>   // setw
using std::cout; using std::setw; using std::string;
struct MeinWert {
    static int zaehler;              // static: existiert nur einmal für alle Instanzen
    int nummer_;                     // Einrücktiefe dieser Instanz für die Ausgabe
    string name_;                    // Name dieser Instanz für die Ausgabe
    explicit MeinWert(string name)
        : nummer_{++zaehler}         // Zähler für Einrücktiefe pro Instanz hochzählen
        , name_{name}                // Name des Objekts für Ausgabe merken
    {
        cout << setw(nummer_) << " " // nummer_ verwenden für Einrücktiefe
             << "Konstruktor " << name_ << "\n"; // Instanzname ausgeben        }
    ~MeinWert() {                    // Destruktor
        cout << setw(nummer_) << " " << "Destruktor " << name_ << "\n";
    }
};
int MeinWert::zaehler = 0;           // Initialisierung der statischen Klassenvariablen


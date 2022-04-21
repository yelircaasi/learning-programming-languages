#include <vector>
#include <iostream>
using std::vector; using std::cout; using std::ostream;
ostream& printVector(ostream& os, const vector<int> &arg) { // Hilfsfunktion
    for(int w : arg) os << w << " "; return os;
}
int main() {
    vector<int> werte{ };
    werte.reserve(50);                      // Platz für 50 Werte garantieren
    int *groesstes = nullptr;               // mit besonderem Wert initialisieren
    for(int w : { 20, 2, 30, 15, 81, 104, 70, 2, }) {
        werte.push_back(w);
        if(!groesstes || *groesstes < w ) { // dereferenzieren zum Wert
            groesstes = &(werte.back());    // neue Adresse merken; deshalb nicht '*'
        }
    }
    printVector(cout, werte) << "\n";       // Ausgabe: 20 2 30 15 81 104 70 2
    // groesstes enthält nun die Adresse der 104:
    *groesstes = -999;                      // dereferenzieren; also Wert überschreiben
    printVector(cout, werte) << "\n";       // Ausgabe: 20 2 30 15 81 @MINUS@999 70 2
}


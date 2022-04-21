#include <iostream>
int main() {
    unsigned int val;
    std::cout << "Wert eingeben: ";
    std::cin >> val;
    if( std::cin ) { // operator bool()
        /* ... */                               // Eingabe korrekt
    } else {
        std::cout << "Fehler bei std::cin\n";   // Fehler bei der Eingabe
    }
}


#include <fstream>
#include <iostream>
int main() {
    std::ofstream file01("data.db");
    if( file01.fail() ) {
        std::cout << "Konnte data.db nicht öffnen\n";
    } else {
        std::cout << "ok.\n";
    }
    file01 << "Text für die Datei\n";
    if( file01.is_open()) {
        file01.close();
    }
    file01.open("data001.db");
    // Automatisch:
    {
        std::ofstream file02("data002.db");
    } // ab hier wird file02 geschlossen
} // ab hier ist auch file01 geschlossen


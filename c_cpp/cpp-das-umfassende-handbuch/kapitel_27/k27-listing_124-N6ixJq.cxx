#include <sstream>  // istringstream
#include <iostream>

int main() {
    std::istringstream istr;
    std::string sval("3.1415 : 4321");
    std::string none;
    double dval=0.0;
    int ival=0;

    istr.str(sval);   // initialisieren
    istr >> dval >> none >> ival;  // auslesen

    if( ! istr.eof() ) {
        std::cout << "Fehler beim Konvertieren\n"; return 1;
    }
    std::cout << dval << " -- " << none << " -- " << ival << "\n";
    // Ausgabe: 3.1415 -- : -- 4321
}


#include <string>       // string, stoi
#include <iostream>     // cin, cout, ostream
#include <iomanip>      // setfill, setw
using std::setfill; using std::setw; using std::ostream;
class Year {  /* Hilfstypen für sicheres Datum */
    int value_; // z. B. 2014
public:
    Year(int v) : value_{v} {}
    int value() { return value_; }
};
class Month {
    int value_; // 1..12
public:
    Month(int v) : value_{v} {}
    int value() { return value_; }
};

class Day {
    int value_; // 1..31
public:
    Day(int v) : value_{v} {}
    int value() { return value_; }
};
/* typsicher konstruierendes Datum */
class Date {
    Year year_;
    Month month_ = 1;
    Day day_ = 1;
public:
    Date(int y) : year_{y}           // 1-Argument-Konstruktor
        {}                           // setzt 1. Januar des angegebenen Jahres
    Date(Year y, Month m, Day d)     // 3-Argument-Konstruktor
        : year_{y}, month_{m}, day_{d}
        {}
    ostream& print(ostream& os);     // z. B. 2014-04-20
};
ostream& Date::print(ostream& os) {  // z. B. 2014-04-20
    return os << year_.value()
        << "-" << setfill( '0' ) << setw(2) << month_.value()
        << "-" << setfill( '0' ) << setw(2) << day_.value();
}
ostream& operator<<(ostream& os, Date d) {
    return d.print(os);
}

// http://codegolf.stackexchange.com/a/11146/1405,  user Fors, 2014-02-25
Date ostern(Year year) {
    const int y = year.value();
    int a = y/100*1483 - y/400*2225 + 2613;
    int b = (y%19*3510 + a/25*319)/330%29;
    b = 148 - b - (y*5/4 + a - b)%7;
    return Date{Year{y}, Month{b/31}, Day{b%31 + 1}}; // Datum erzeugen
}

int main(int argc, const char *argv[] ) {
    /* Eingabe */
    int zahl {};
    if(argc > 1) {
        zahl = std::stoi(argv[1]);
    } else {
        std::cout << "Jahr? "; std::cin >> zahl;
    }
    /* Berechnung */
    Date date = ostern(zahl);  // implizite Konvertierung nach Year
    /* ausgabe */
    std::cout << "Ostern: " << date << "\n";
}


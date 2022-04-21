#include <iostream>                                  // cout
#include <limits>                                    // numeric_limits

template<typename INT_TYP>                           // Template mit Typargument
void infos(const char* name) {

    using L = typename std::numeric_limits<INT_TYP>; // kürzer umbenennen
    std::cout
        << name
        << " zahlenbits:" << L::digits               // Bits ohne Vorzeichenbit
        << " vorzeichen:" << L::is_signed            // speichert Vorzeichen?
        << " min:"<< (long long)L::min()             // kleinster möglicher Wert
        << " max:"<< (long long)L::max()             // größter möglicher Wert
        << "\n";
}

int main() {
    infos<signed char>("char");                      // kleinster int-Typ
    infos<short>("short");
    infos<int>("int");
    infos<long>("long");
    infos<long long>("long long");                   // größter int-Typ
}


#include <unordered_set> // unordered_multiset
#include <vector>
#include <iostream>
using std::unordered_multiset; using std::cout; using std::ostream;
template<typename Elem>
ostream& operator<<=(ostream&os, const unordered_multiset<Elem>&data) {
    for(auto &e : data) { os << e << ' '; } return os << '\n'; }
int main() {
    // ohne Argumente
    unordered_multiset<int> leer(1000); // anfängliche Größe der Hashtabelle
    cout <<= leer;      // Ausgabe:
    // Initialisierungsliste; doppelte werden übernommen:
    unordered_multiset daten{ 1,1,2,2,3,3,4,4,5,5 };
    cout <<= daten;     // Ausgabe in etwa: 5 5 4 4 3 3 2 2 1 1
    // Kopie
    unordered_multiset kopie(daten);
    cout <<= kopie;     // Ausgabe in etwa: 5 5 4 4 3 3 2 2 1 1
    // Bereich
    std::vector in{1,2,3,10,20,30,10,20,30,1,2,3};
    unordered_multiset bereich(in.begin()+3, in.end()-3);
    cout <<= bereich;   // Ausgabe in etwa: 30 30 20 20 10 10
}


#include <set>
template<typename Key>
std::set<Key> sorted(const unordered_set<Key> &data)
  { return std::set<Key>(data.begin(), data.end()); }
// ...
// ohne Argumente
unordered_set<int> leer{};
cout <<= leer;      // Ausgabe:
// Initialisierungsliste
unordered_set daten{1,1,2,2,3,3,4,4,5,5};// doppelte werden nicht übernommen
cout <<= daten;     // Ausgabe in etwa: 5 4 3 2 1
// Kopie
unordered_set kopie(daten);
cout <<= kopie;     // Ausgabe in etwa: 5 4 3 2 1
// Bereich
auto so1 = sorted(daten);
unordered_set bereich(std::next(so1.begin()), std::prev(so1.end()));
cout <<= bereich;   // Ausgabe in etwa: 2 3 4


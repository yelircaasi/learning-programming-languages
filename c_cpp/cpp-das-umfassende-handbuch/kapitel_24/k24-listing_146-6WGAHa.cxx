// ohne Argumente
set<int> leer{};
cout <<= leer;           // Ausgabe:
// Initialisierungsliste
set liste{ 1,1,2,2,3,3,4,4,5,5 };      // set übernimmt keine doppelten
cout <<= liste;          // Ausgabe: 1 2 3 4 5
// Kopie
set copy(liste);
cout <<= copy;           // Ausgabe: 1 2 3 4 5
// Bereich
set range( std::next(liste.begin()), std::prev(liste.end()));
cout <<= range;          // Ausgabe: 2 3 4


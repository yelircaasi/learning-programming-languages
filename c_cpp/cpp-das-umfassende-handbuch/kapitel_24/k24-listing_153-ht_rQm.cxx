#include <vector>
// ...
set data{ 10, 20, 30, };
data.insert( { 40, 50, 60, 70 }); // Initialisierungsliste
std::vector neu{ 5, 25, 35, 15, 25, 75, 95 };
data.insert( neu.cbegin()+1, neu.cend()-1 ); // Bereich
cout <<= data; // Ausgabe: 10 15 20 25 30 35 40 50 60 70 75


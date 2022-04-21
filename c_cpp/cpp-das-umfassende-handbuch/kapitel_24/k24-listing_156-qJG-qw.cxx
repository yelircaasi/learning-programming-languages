set data{ 10, 20, 30, 40, 50, 60, 70 };
auto lo = data.lower_bound(35);
auto up = data.upper_bound(55);
data.erase(lo, up);      // löscht alle Zahlen zwischen zwischen 35 und 55
cout <<= data;           // Ausgabe: 10 20 30 60 70
lo = data.lower_bound(20);
up = data.upper_bound(60);
data.erase(lo, up);      // löscht inklusive 60, weil up auf 70 verweist
cout <<= data;           // Ausgabe: 10 70
auto n = data.erase(69); // löscht nichts
cout << "Anzahl entfernter Elemente: "<< n << '\n'; // Ausgabe: Anzahl ... 0
n = data.erase(70);      // löscht ein Element
cout << "Anzahl entfernter Elemente: "<< n << '\n';  // Ausgabe: Anzahl ... 1
cout <<= data;           // Ausgabe: 10


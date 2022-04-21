valarray<int> v {
  1,  2,  3,
  4,  5,  6,
  7,  8,  9,
 10, 11, 12 };
v[slice(0, 4, 3)] *= valarray<int>(v[slice(0, 4, 3)]); // erste Spalte quadrieren
cout <<= v;                                     // Ausgabe: 1 2 3 16 5 6 49 8 9 100 11 12
v[slice(0, 4, 3)] = valarray<int>{1, 4, 7, 10}; // wiederherstellen
valarray<int> r3(v[gslice(0, {2, 3}, {6,2})]);  // 2-D-Schnitt vom 3-D-Würfel
cout <<= r3;                                    // Ausgabe: 1 3 5 7 9 11
valarray<char> text("jetzt gehts erst los", 20);
valarray<char> caps("JGEL", 4);
valarray<size_t> idx{ 0, 6, 12, 17 };           // Indexe in text
text[idx] = caps;                               // indirekt zuweisen
cout <<= text;                                  // Ausgabe: Jetzt Gehts Erst Los


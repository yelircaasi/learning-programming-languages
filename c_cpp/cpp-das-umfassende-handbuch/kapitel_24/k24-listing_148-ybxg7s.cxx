set quelle{1,2,3,4,5};
set<int> ziel{};
set<int> ziel2{};
cout <<= quelle;           // Ausgabe: 1 2 3 4 5
cout <<= ziel;             // Ausgabe:
cout <<= ziel2;            // Ausgabe:
ziel = quelle;             // nachträglich kopieren
cout <<= quelle;           // Ausgabe: 1 2 3 4 5
cout <<= ziel;             // Ausgabe: 1 2 3 4 5
ziel2 = std::move(quelle); // verschieben
cout <<= quelle;           // Ausgabe:
cout <<= ziel2;            // Ausgabe: 1 2 3 4 5


set quelle{1,2,3,4,5};
cout <<= quelle;           // Ausgabe: 1 2 3 4 5
set ziel( std::move(quelle) ); // verschieben statt kopieren
cout <<= quelle;           // Ausgabe:
cout <<= ziel;             // Ausgabe: 1 2 3 4 5


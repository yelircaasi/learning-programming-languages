valarray<int> data;              // zunächst Größe 0
cout << data.size() << "\n";     // Ausgabe: 0
data.resize(100);                // vergrößert
cout << data.size() << "\n";     // Ausgabe: 100
valarray<int> data2(200);        // Platz für 200 Werte
cout << data2.size() << "\n";    // Ausgabe: 200
valarray<int> dataC(5, 20);      // zwanzig 5en, andersherum als bei vector
cout << dataC.size() <<": dataC[6]="<< dataC[6]<< "\n"; // Ausgabe: 20: dataC[6]=5
valarray dataD{ 2, 3, 5, 7, 11 };      // valarray<int>, Initialisierungsliste
cout << dataD.size() <<": dataD[3]=" <<dataD[3]<< "\n"; // Ausgabe: 5: dataD[3]=7


map<string,int> zwerge;
zwerge.emplace("Fili",  2859);
cout << zwerge["Fili"] << '\n'; // Ausgabe: 2859
cout << zwerge["Dori"] << '\n'; // neu erzeugt. Ausgabe: 0
zwerge["Kili"] = 2846;          // neu erzeugt und gleich überschrieben
cout << zwerge["Kili"] << '\n'; // Ausgabe: 2846
cout <<= zwerge;                // Ausgabe: Dori:0 Fili:2859 Kili:2846


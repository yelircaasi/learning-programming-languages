vector<string> autos{ "Diesel", "Benzin", "Super", "Gas" };
cout << autos[1] << '\n';             // "Benzin"
autos.insert(autos.begin(), "Strom"); // verschiebt alles um eins nach hinten
cout << autos[1] << '\n';             // "Diesel"


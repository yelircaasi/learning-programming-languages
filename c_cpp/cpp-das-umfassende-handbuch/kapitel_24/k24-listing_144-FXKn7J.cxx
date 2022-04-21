auto vergl = [](auto e, auto f) { return e/10 < f/10; }; // zusammenfassen ist okay
std::set<int,decltype(vergl)> data(vergl);
data.insert({ 14,23,56,71 });
cout <<= data;           // Ausgabe: 14 23 56 71
auto wo = data.find(29); // 29 findet nun auch die 23
if(wo != data.end()) {
    cout << "hab es: " << *wo << '\n'; // Ausgabe: hab es: 23
}
data.insert(79);         // nichts passiert, denn 71 ist schon drin
cout <<= data;           // Ausgabe: 14 23 56 71


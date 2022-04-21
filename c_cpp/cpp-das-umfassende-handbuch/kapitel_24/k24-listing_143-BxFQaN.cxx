using std::cout; using std::ostream; using std::set;
auto vergl = [](auto e, auto f) { return e <= f; }; // ungültig definiert!
std::set<int,decltype(vergl)> data(vergl);
data.insert({ 9,5,7,2,3,6,8 });
cout <<= data;                    // Ausgabe mit Glück: 2 3 5 6 7 8 9
auto wo = data.find(7);
if(wo != data.end()) {
    cout << "hab es: " << *wo << '\n';
} else {
    cout << "weg isses!" << '\n'; // wahrscheinlich landen Sie hier
}


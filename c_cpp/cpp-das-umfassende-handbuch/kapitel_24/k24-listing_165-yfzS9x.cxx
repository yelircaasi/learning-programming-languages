string such7(const map<int,string> &data) {
    return data[7];            // non-const-Methode auf const-Parameter
}
string such5(const map<int,string> &data) {
    auto it = data.find(5);    // nicht automatisch einfügend
    return it==data.end() ? string{} : it->second;
}
// ...
map<int,string> zwerge{ {1,"eins"}, {3,"drei"}, {5,"fuenf"}, {7,"sieben"} };
cout << such7(zwerge) << '\n';
cout << such5(zwerge) << '\n';  // Ausgabe: fuenf


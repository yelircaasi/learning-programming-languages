#include <list>
#include <string>
#include <iterator>                      // make_move_iterator
using std::make_move_iterator; using std::string;
// ...
vector<int> erzeuge() { return vector<int>{8, 9, 10}; }
size_t zaehle(vector<int> d) { return d.size(); }
// ...
vector input{1,2,3};
vector outputA(std::move(input));       // Verschiebung
vector outputB = std::move(input);      // auch Verschiebung, keine Zuweisung
vector data = erzeuge();                // Return-Value-Optimization
cout << zaehle(input) << '\n';          // Aufruf per Copy-by-Value
// elementweise aus einem anderen Container verschieben
std::list<string> quelle{ "a", "a", "a", "BB", "CC", "DD", "b", "b" };
auto von = quelle.begin();
std::advance(von, 3); // 3 vorwärts, bei list aber langsam
auto bis = von;
std::advance(bis, 3); // noch mal 3 vorwärts
vector ziel(make_move_iterator(von), make_move_iterator(bis));
// quelle ist nun {"a", "a", "a", "", "", "", "b", "b"}, ziel ist nun {"BB", "CC", "DD"}


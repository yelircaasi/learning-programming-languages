#include <cstdio> // toupper, tolower
// ...
auto comp = [](char a, char b) { return toupper(a) < toupper(b); };
map<char,int,decltype(comp)> lets(comp); // als Templateparameter und Argument
lets['a'] = 1;
lets['B'] = 2;
lets['c'] = 3;
lets['A'] = 4; // überschreibt Position 'a'
cout <<= lets; // Ausgabe: a:4 B:2 c:3

struct Comp {  // Funktor
    bool operator()(char a, char b) const { return toupper(a) < toupper(b); }
};
map<char,int,Comp> lets2; // hier reicht der Templateparameter


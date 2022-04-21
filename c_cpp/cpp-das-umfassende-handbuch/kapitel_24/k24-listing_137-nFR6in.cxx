#include <deque>
#include <iostream>
#include <iterator> // ostream_iterator
#include <algorithm> // copy
using std::cout; using std::ostream; using std::ostream_iterator; using std::copy;
ostream& operator<<=(ostream& os, int val) { return os<<val<<'\n'; }
int main() {
    std::deque d{ 4, 6 };      // deque<int> mit Elementen erzeugen
    // Einfügen
    d.push_front(3);           // am Kopf: effizient
    d.insert(d.begin()+2, 5);  // mittendrin: langsam
    d.push_back(7);            // am Ende: effizient
    // Zugriff
    cout <<= d.front();        // vom Kopf: effizient
    cout <<= d[3];             // mittendrin: effizient
    cout <<= d.back();         // vom Ende: effizient

    // Größe
    cout <<= d.size();         // Größe lesen
    d.resize(4);               // Größe kappen (oder erweitern)

    // Iteratoren
    copy(d.begin(), d.end(), ostream_iterator<int>(cout, " "));
    cout << '\n';              // Ausgabe: 3 4 5 6

    // Entfernen
    d.pop_front();             // am Kopf: effizient
    d.erase(d.begin()+1);      // mittendrin: langsam
    d.pop_back();              // am Ende: effizient
    d.clear();                 // leeren
}


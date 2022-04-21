#include <map>        // die Hauptsache
#include <iostream>   // zur Ausgabe
#include <string>     // gerne mal Schlüssel oder Ziel
using std::multimap; using std::cout; using std::string;
template<typename Key, typename Trg, typename Cmp>
std::ostream& operator<<=(std::ostream&os, const multimap<Key,Trg,Cmp>&data){
    for(auto &e : data) {
        os << e.first << ":" << e.second << ' ';
    }
    return os << '\n'; // '<<=' statt '<<' für Zeilenumbruch
}
int main() {
   // Beispielcode hier
}


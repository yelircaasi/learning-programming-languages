#include <set>     // multiset
#include <iostream>
using std::multiset; using std::cout;
template<typename Elem, typename Comp>
std::ostream& operator<<=(std::ostream&os, const multiset<Elem,Comp>&data) {
    for(auto &e : data) {
        os << e << ' ';
    }
    return os << '\n'; // '<<=' statt '<<' für Zeilenumbruch
}
int main() {
   // Beispielcode hier
}


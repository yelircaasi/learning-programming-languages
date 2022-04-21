#include <set>
#include <iostream>
using std::set; using std::cout;
template<typename Elem, typename Comp>
std::ostream& operator<<=(std::ostream&os, const set<Elem,Comp>&data) {
    for(auto &e : data) {
        os << e << ' ';
    }
    return os << '\n'; // '<<=' statt '<<' für Zeilenumbruch
}
int main() {
   // Beispielcode hier
}


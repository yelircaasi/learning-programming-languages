#include <list>
#include <iostream>

using std::list; using std::cout; using std::ostream;

ostream& operator<<=(ostream&os, const list<int> &data)
    { for(auto &e:data) os<<e<<' '; return os<<'\n'; }

int main() {
    list<int> numa { 1, 3, 5, 7, 9 };
    list<int> numb { 2, 4, 6, 8 };
    auto wo = numa.end();
    numa.splice(wo, numb); // transferieren in O(1)
    cout <<= numa; // Ausgabe: 1 3 5 7 9 2 4 6 8
    cout <<= numb; // Ausgabe: (keine)
    numa.sort();   // sort als Methode, nicht aus <algorithm>
    cout <<= numa; // Ausgabe: 1 2 3 4 5 6 7 8 9
}


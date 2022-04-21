#include <set>
#include <iostream>
using std::cout; using std::ostream; using std::set;

void suchmal(const set<int>&data, int was, ostream&os) {
    auto wo = data.find(was);
    if(wo != data.end()) {
        os << "gefunden:" << *wo << " ";
    } else {
        os << was << " nicht gefunden. ";
    }
    auto lo = data.lower_bound(was);
    if(lo != data.end()) {
        os << "lo:" << *lo;
    } else {
        os << "lo:-";
    }

    auto up = data.upper_bound(was);
    if(up != data.end()) {
        os << " up:" << *up;
    } else {
        os << " up:-";
    }
    // [lo,up] ist nun das Gleiche, was equal_range geliefert hätte
    os << " Bereich:{";
    for( ; lo != up; ++ lo) {
      os << *lo << ' ';
    }
    os << "}";
    // zählen
    os << " C:" << data.count(was) // Treffer zählen
       << "\n";
}
int main() {
    set data{ 10, 20, 30, 40, 50, 60 };
    suchmal(data, 20, cout);    // gefunden:20 lo:20 up:30 Bereich:{20 } C:1
    suchmal(data, 25, cout);    // 25 nicht gefunden. lo:30 up:30 Bereich:{} C:0
    suchmal(data, 10, cout);    // gefunden:10 lo:10 up:20 Bereich:{10 } C:1
    suchmal(data, 60, cout);    // gefunden:60 lo:60 up:- Bereich:{60 } C:1
    suchmal(data, 5, cout);     // 5 nicht gefunden. lo:10 up:10 Bereich:{} C:0
    suchmal(data, 99, cout);    // 99 nicht gefunden. lo:- up:- Bereich:{} C:0
}


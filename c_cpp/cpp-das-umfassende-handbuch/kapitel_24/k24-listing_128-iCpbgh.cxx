#include <vector>
#include <iostream>
using namespace std;

ostream& operator<<(ostream&os, const vector<int> &vec) {
    for(auto &elem : vec) { os << elem << ' '; }
    return os;
}
int main() {
    vector<int> data {};     // erzeugt einen leeren vector
    data.reserve(3);         // Platz für 3 Elemente
    cout << data.size() << '/' << data.capacity() << '\n'; // 0/3
    data.push_back(111);     // ein Element hinzufügen
    data.resize(3);          // Größe verändern; hier fügt es neue Elemente an
    data.push_back(999);     // noch ein Element hinzufügen
    cout << data.size()<<'/'<<data.capacity()<<'\n'; // 4/6; Kapazität erhöht
    cout << data << '\n';    // 111, 0, 0, 999
    data.push_back(333);     // noch ein Element anfügen
    cout << data << '\n';    // 111, 0, 0, 999, 333
    data.reserve(1);         // nichts passiert, denn capacity() > 1
    data.resize(3);          // schrumpfen; Elemente werden entfernt
    cout << data << '\n';    // 111, 0, 0
    cout << data.size()<<'/'<<data.capacity()<<'\n'; // 3/6; Kapazität immer noch 6
    data.resize(6, 44);      // noch mal vergrößern, mit 44en auffüllen
    cout << data << '\n';    // 111, 0, 0, 44, 44, 44
}


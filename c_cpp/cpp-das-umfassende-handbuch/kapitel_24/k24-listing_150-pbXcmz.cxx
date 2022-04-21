#include <tuple> // tie
// ...
template<typename IT> ostream& operator<<(ostream& os,const pair<IT,bool> wo)
  { return os << (wo.second ? "ja" : "nein"); }

struct Punkt {
    double x_, y_;
    Punkt(double x, double y) : x_{x}, y_{y} {}
    friend bool operator<(const Punkt &a, const Punkt &b) { // für set benötigt
        return std::tie(a.x_, a.y_) < std::tie(b.x_, b.y_); // tuple nutzen
    }
    friend ostream& operator<<(ostream &os, const Punkt &a) {
        return os << "(" << a.x_ << ',' << a.y_<< ")";
    }
};

int main() {
    set data{ 10, 20, 30, 40, 50, 60, 70 };
    auto wo = data.insert(35);         // fügt zwischen 30 und 40 ein
    cout << "neu? " << wo << '\n';     // Ausgabe: neu? ja
    wo = data.insert(40);              // gibt es schon, fügt also nicht ein
    cout << "neu? " << wo << '\n';     // Ausgabe: neu? nein
    set<Punkt> punkte{};
    punkte.insert( Punkt{3.50,7.25} ); // temporärer Wert
    punkte.emplace(1.25, 2.00);        // Konstruktorargumente
    cout <<= punkte;                   // Ausgabe: (1.25,2) (3.5,7.25)
}


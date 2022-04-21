#include <iostream>  // ostream
#include <iomanip>   // setfill, setw
using std::ostream; using std::setfill; using std::setw;
class Value {
protected: // nicht öffentlich, nur für den eigenen und abgeleiteten Gebrauch
    int value_;
    const unsigned width_;
    Value(int v, unsigned w) // Konstruktor mit zwei Argumenten
      : value_{v}, width_{w} {}
public:
    ostream& print(ostream& os) const;
};
ostream& operator<<(ostream& os, const Value& rechts) {
    return rechts.print(os);
}
ostream& Value::print(ostream& os) const {
    return os << setfill( '0' ) << setw(width_) << value_;
}


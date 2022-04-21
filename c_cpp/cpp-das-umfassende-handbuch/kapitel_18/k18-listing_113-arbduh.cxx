// Parameter müssen gültige Werte der jeweiligen Einheit sein.
#include <iostream> // ostream
#include <iomanip> // setw, setfill
using std::ostream; using std::setw; using std::setfill;
class Clock {
protected:
    int h_, m_, s_;
public:
    Clock(int hours, int minutes, int seconds)
    : h_{hours}, m_{minutes}, s_{seconds} {}
    void setClock(int hours, int minutes, int seconds) {
        h_ = hours; m_ = minutes; s_ = seconds;
    }
    friend ostream& operator<<(ostream&os, const Clock& c) {
        return os << setw(2) << setfill( '0' ) << c.h_ <<':'
                  << setw(2) << setfill( '0' ) << c.m_ <<':'
                  << setw(2) << setfill( '0' ) << c.s_;
    }
    void tick() { // +1 Sekunde
        if(s_ >= 59) {
            s_ = 0;
            if(m_ >= 59) {
                m_ = 0;
                if(h_ >= 23) h_ = 0;
                else { h_ += 1; }
            } else { m_ += 1; }
        } else { s_ += 1; }
    }
};


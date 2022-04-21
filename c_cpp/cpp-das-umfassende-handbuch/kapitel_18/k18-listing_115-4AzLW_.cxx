// ... includes und usings ...
struct Calendar {
    int y_, m_, d_;
    static const std::vector<int> mlens_;
    bool leapyear() const {
        if(y_ % 4 != 0) return false;
        if(y_ % 100 != 0) return true;
        if(y_ % 400 != 0) return false;
        return true;
    }
public:
    Calendar(int year, int month, int day)
    : y_{year}, m_{month}, d_{day} {}
    void setCalendar(int year, int month, int day) {
        y_ = year; m_ = month; d_ = day;
    }
    friend ostream& operator<<(ostream& os, const Calendar& c) {
        return os << setw(4) << setfill( '0' ) << c.y_ <<'-'
                  << setw(2) << setfill( '0' ) << c.m_ <<'-'
                  << setw(2) << setfill( '0' ) << c.d_;
    }
    void advance() { // +1 day
        auto maxd = mlens_[m_-1]; // 0-basierter vector
        if(m_==2 && leapyear())
            maxd += 1;            // Februar im Schaltjahr
        if(d_ >= maxd) {
            d_ = 1;
            if(m_ >= 12) { m_ = 1; y_ += 1; }
            else { m_ += 1; }
        } else { d_ += 1; }
    }
};
const std::vector<int> Calendar::mlens_ = {31,28,31,30,31,30,31,31,30,31,30,31};


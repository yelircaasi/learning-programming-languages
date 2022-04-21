class Date {
    Year year_;
    Month month_ {1};
    Day day_ {1};
public:
    explicit Date(int y) : year_{y} {} // year-01-01
    Date(Year y, Month m, Day d) : year_{y}, month_{m}, day_{d} {}
    ostream& print(ostream& os) const;
};

ostream& Date::print(ostream& os) const {
    return os << year_ << "-" << month_ << "-"  << day_;
}
ostream& operator<<(ostream& os, const Date& rechts) {
    return rechts.print(os);
}
int main() {
    using std::cout;
    Date d1 { Year{2013}, Month{15}, Day{19} };
    cout << d1 << "\n"; // Ausgabe: 2013-15-19
}


class Date;  // Vorwärtsdeklaration
class Year : public Value {
public:
    explicit Year(int v) : Value{v, 4} {}
    Date ostern() const;            // neue Methode deklarieren
};
// Hier Month, Day und Date deklarieren. Dann:
Date Year::ostern() const {         // neue Methode definieren
    const int y = value_;
    int a = value_/100*1483 - value_/400*2225 + 2613;
    int b = (value_%19*3510 + a/25*319)/330%29;
    b = 148 - b - (value_*5/4 + a - b)%7;
    return Date{Year{value_}, Month{b/31}, Day{b%31 + 1}};
}
int main() {
    using std::cout;
    Year year{2014};
    cout << year.ostern() << "\n";  // Ausgabe: 2014-04-20
}


#include <iostream>               // istream, ostream, cout
class Bool {
    bool val_ = false;
    bool& operator*()             // dereferenzieren; veränderbar
        { return val_; };
    const bool& operator*() const // dereferenzieren; nur lesen
        { return val_; }
public:
    constexpr Bool() {}
    explicit constexpr Bool(bool value)
        : val_{value} {}
    // einstellige Operatoren
    Bool operator!() const        // Nicht-Operator
        { return Bool{!val_}; };
    // zweistellige Operatoren
    friend Bool operator&&(const Bool &re, const Bool &li)
        { return Bool{*re && *li}; }
    friend Bool operator||(const Bool &re, const Bool &li)
        { return Bool{*re || *li}; }
    // Ein- und Ausgabe
    friend std::ostream& operator<<(std::ostream& os, const Bool& arg);
    friend std::istream& operator>>(std::istream& is,  Bool& arg);
};

std::ostream& operator<<(std::ostream& os, const Bool& arg)
    { return os << *arg; }
std::istream& operator>>(std::istream& is, Bool& arg)
    { return is >> *arg; }

// Konstanten
static constexpr Bool False{false};
static constexpr Bool True{true};

int main() {
    Bool jein = True && ( Bool{false} || !Bool{} ); // verwendet &&, || und !
    std::cout << jein << "\n"; // Ausgabe: 1
}


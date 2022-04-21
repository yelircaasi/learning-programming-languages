#include <iostream>
struct Basis {
    int acht_ = 8;
    int wert() const { return acht_; }
    void print(std::ostream& os) const { os << wert() << "\n"; }
};
struct Print : public Basis {
    int neun_ = 9;
    void print(std::ostream& os) const { os << wert() << "\n"; }
};
struct Wert : public Basis {
    int zehn_ = 10;
    int wert() const { return zehn_; }
};
struct Beides : public Basis {
    int elf_ = 11;
    int wert() const { return elf_; }
    void print(std::ostream& os) const { os << wert() << "\n"; }
};

int main() {
    Basis ba{}; ba.print(std::cout);   // Basisaufruf
    Print pr{}; pr.print(std::cout);   // print überschrieben
    Wert we{}; we.print(std::cout);    // print aus Basis
    Beides be{}; be.print(std::cout);  // alles überschrieben
}


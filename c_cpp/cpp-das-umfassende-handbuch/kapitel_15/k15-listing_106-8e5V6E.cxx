class Base {
public:
    Base() {}                 // null-Argument-Konstruktor
    explicit Base(int i) {}   // ein Argument
    Base(int i, int j) {}     // zwei Argumente
    void func() {};           // Methode
};

class Derived : public Base { // kein eigener Konstruktor
};
int main() {
    Base b0{};                // okay, null-Argument-Konstruktor
    Base b1{12};              // okay, ein Argument
    Base b2{6,18};            // okay, zwei Argumente
    Derived d0{};             // okay, Compiler generiert Defaultkonstruktor
    d0.func();                // okay, Methode wird geerbt
    Derived d1{7};            // Fehler: kein Konstruktor für ein Argument definiert
    Derived d2{3,13};         // Fehler: kein Konstruktor für zwei Argumente definiert
}


#include <iostream>
using std::cout;

struct Base1 {
    virtual void f1() {}
};

struct Base2 {
    virtual void f2() {}
};

struct Derived : public Base1, public Base2 {
    virtual void g() {};
};

void vergleich(void* a, void* b) {
    cout << (a==b ? "identisch\n" : "unterschiedlich\n");
}

int main() {
    Derived d{};
    auto *pd = &d;

    cout << pd << '\n';       // zum Beispiel 0x1000
    auto pb1 = static_cast<Base1*>(pd);
    cout << pb1 << '\n';      // immer noch 0x1000

    auto pb2 = static_cast<Base2*>(pd);
    cout << pb2 << @'@\n@'@;      // jetzt 0x1008 !

    cout << (pd==pb1 ? "gleich\n" : "verschieden\n"); // Ausgabe: gleich
    cout << (pd==pb2 ? "gleich\n" : "verschieden\n"); // Ausgabe: gleich
    vergleich(pb1, pd);       // Ausgabe: identisch
    vergleich(pb2, pd);       // Ausgabe: unterschiedlich
}


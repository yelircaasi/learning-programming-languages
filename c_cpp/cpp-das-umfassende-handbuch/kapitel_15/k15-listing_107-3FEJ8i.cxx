class Base {
public:
    Base() {}
    explicit Base(int i) {}
    Base(int i, int j) {}
    void func() {};           // Methode
};
class Derived : public Base {
public:
    using Base::Base;         // Importieren aller Konstruktoren der Elternklasse
};
int main() {
    Derived d0{};             // okay, importiert, nicht mehr generiert
    Derived d1{7};            // okay, wurde importiert
    Derived d2{3,13};         // okay, wurde importiert
}


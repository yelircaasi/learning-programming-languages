#include <string>
struct Base {
    void func(int x) {};
};
struct Derived : public Base {
    void func(std::string y) {};   // verschattet func(int)
};
int main() {
    Derived d{};
    d.func("Text");
    d.func(3);  // Fehler: func(int) ist nicht mehr sichtbar
}


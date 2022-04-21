#include <iostream>
using std::cout;
class Base {
public:
  int data_ = 0;
};
class Derived1 : public virtual Base {
};
class Derived2 : public virtual Base {
};
class DerivedDerived : public Derived1, public Derived2 {
public:
  void method() {
     data_ = 1;  // eindeutig, denn es gibt nur ein data_
  }
};
void ausgabe(const DerivedDerived &dd) {
    cout << dd.data_
        << (((Derived1&)dd).data_)
        << (((Derived2&)dd).data_)
        << (((Base&)dd).data_) << '\n';
}
int main() {
  DerivedDerived dd{};
  ausgabe(dd);   // Ausgabe: 0000
  dd.method();   // setzt data_ auf 1
  ausgabe(dd);   // Ausgabe: 1111
}


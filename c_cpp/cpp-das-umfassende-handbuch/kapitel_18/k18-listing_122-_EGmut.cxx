#include <iostream>
using std::cout;
struct Base { // abstrakte Klasse
  virtual void anbieter() = 0;
  virtual void nutzer() = 0;
};
struct Derived1 : public virtual Base { // noch abstrakt
  virtual void nutzer() override { anbieter(); }
};
struct Derived2 : public virtual Base { // noch abstrakt
  virtual void anbieter() override { cout << "Derived2::anbieter!\n"; }
};
struct DerivedDerived : public Derived1, public Derived2 { // konkret
};
int main() {
  DerivedDerived dd{};
  DerivedDerived *pdd = &dd;
  Derived1* pd1 = pdd; // Cast innerhalb der Hierarchie
  Derived2* pd2 = pdd; // Cast innerhalb der Hierarchie
  pdd->nutzer();       // Ausgabe: Derived2::anbieter()!
  pd1->nutzer();       // Ausgabe: Derived2::anbieter()!
  pd2->nutzer();       // Ausgabe: Derived2::anbieter()!
}


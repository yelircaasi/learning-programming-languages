#include <iostream>
using std::cout;
template<typename TYP>
  void func(TYP a) { cout << a <<" TYP\n"; }
void func(int a) { cout << a << " int\n"; }
int main() {
    func<int>(8); // Ausgabe: 8 TYP
    func(8);      // Ausgabe: 8 int
}


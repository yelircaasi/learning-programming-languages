#include <random>
#include <iostream>

int main() {
    std::default_random_engine e{};
    using Dstr = std::uniform_int_distribution<int>;       // gleichverteilte int
    Dstr karte{};                                          // Verteilung erzeugen

    for(int n=32; n>=1; --n)
      std::cout <<" "<< karte(e, Dstr::param_type{1,n} );  // Parameter erst hier
    std::cout << '\n';
    // Ausgabe zum Beispiel:
    // 1 5 23 14 15 6 2 17 17 22 9 11 17 1 1 10 11 1 6 1 6 8 6 9 7 4 1 4 2 3 2 1
}


#include <iostream>                      // cout
int main() {
    using std::cout;
    Num a{1};
    *a = 7;                              // operator* liefert auch int&
    a += Num{3};                         // Inkrement mit Num
    cout << ( ++( ++a ) ) << "\n";       // Ausgabe: 12
    a -= 2;                              // Variation mit int
    cout << --(--a) << "\n";             // Ausgabe: 8
    Num b{99};
    cout << (a<b ? "ja\n" : "xxx\n");    // Ausgabe: ja
    cout << (a>b ? "xxx\n" : "nein\n");  // Ausgabe: nein
    b /= Num{3};          // b: 33
    b %= Num{10};         // b: 3
    b <<= 4;              // b: 48
    b >>= 2;              // b: 12
    Num c = b / Num{3} + a * Num{2}; // c: 20
}


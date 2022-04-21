#include <iostream>
const int& a_oder_b(int auswahl) {
    static const int a = 42;
    static const int b = 73;
    if(auswahl==1)
        return a; // const& auf innere Variable a zurückgeben
    else
        return b; // const& auf innere Variable b zurückgeben
}
template<typename TYP>
TYP add(TYP a, TYP b) {
    return a + b;
}
int main() {
    auto res = add(
        a_oder_b(0),   // const int&
        a_oder_b(1) ); // const int&
    std::cout << res << "\n"; // Ausgabe: 115
}


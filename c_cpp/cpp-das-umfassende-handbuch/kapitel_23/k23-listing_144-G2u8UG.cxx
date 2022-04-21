#include <iostream>
#include <string>

namespace lits {

    // operator"" _sx
    template<char...CS> std::string operator"" _sx() {
        return (std::string{} + ... + CS); // ein Faltausdruck
    };

}
int main() {
    using namespace lits;
    std::cout << 10000000_sx << '\n';     // Ausgabe: 10000000
    std::cout << 10'000'000_sx << '\n';   // Ausgabe: 10'000'000
    std::cout << 0x00af_sx << '\n';       // Ausgabe: 0x00af
    std::cout << 0x0'c'0'a'f_sx << '\n';  // Ausgabe: 0x0'c'0'a'f
    std::cout << 007_sx << '\n';          // Ausgabe: 007
    std::cout << 0b01_sx << '\n';         // Ausgabe: 0b01
}


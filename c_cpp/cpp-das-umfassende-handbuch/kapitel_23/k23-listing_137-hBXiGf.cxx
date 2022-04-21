#include <iostream>
template <typename ... Args>
auto countArgs(Args ... args) {
    return (sizeof ... (args) );
}
int main() {
    std::cout << countArgs("eins", 2, 3.14) << '\n';   // Ausgabe: 3
}


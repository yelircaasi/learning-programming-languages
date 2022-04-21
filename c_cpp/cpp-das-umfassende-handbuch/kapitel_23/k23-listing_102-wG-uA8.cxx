#include <iostream>
void show(auto a) { std::cout << a; } // kein template<...>
int main() {
    show(8);
    show(6.66);
}


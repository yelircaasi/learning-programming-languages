#include <iostream>
int main() {
    int count = 0;
    auto plus1 = [count](int x) mutable { // count als Kopie
        std::cout << ++count; return x+1;
    };
    for(int i=0; i<5; ++i) {
        plus1(i);
    }
    std::cout << "\n";
    // Ausgabe: 12345
}


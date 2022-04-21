#include <iostream>

int main() {
    std::cout << "3+4*5+6=" << 3+4*5+6 << "\n";          // Punkt vor Strich; = 29
    std::cout << "(3+4)*(5+6)=" << (3+4)*(5+6) << "\n";  // Klammern; = 77
    std::cout << "22/7=" << 22/7 << " Rest " << 22%7 << "\n"; // 22/7 = 3 Rest 1

    for(int n=0; n < 10; ++n) {
        std::cout << -2*n*n + 13*n - 4 << " ";           // mit unärem Minus
    }
    std::cout << "\n";
    // Ausgabe: @MINUS@4 7 14 17 16 11 2 @MINUS@11 @MINUS@28 @MINUS@49
}


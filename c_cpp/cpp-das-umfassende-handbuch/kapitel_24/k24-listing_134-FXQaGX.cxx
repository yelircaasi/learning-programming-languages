#include <array>
#include <iostream>
int main() {
    std::array ports { 80, 443  };          // array<int>
    auto [ http, https ] = ports;           // deklariert Variablen und bindet sie
    std::cout << http << " " << https << "\n";
    auto const& [ rhttp, rhttps ] = ports;  // Referenz und const sind möglich
    std::cout << rhttp << " " << rhttps << "\n";
}


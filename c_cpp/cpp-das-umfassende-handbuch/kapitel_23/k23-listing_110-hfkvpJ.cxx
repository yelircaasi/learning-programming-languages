#include <functional> // function
#include <iostream>   // cout
int berechne(int a, int b, std::function<int(int,int)> binop) {
    return binop(a,b);
}

int plus(int a, int b) { return a+b; }
int mal(int a, int b) { return a*b; }
int main() {
    std::cout << berechne(3, 4, plus) << "\n"; // Ausgabe: 7
    std::cout << berechne(3, 4, mal) << "\n";  // Ausgabe: 12
}


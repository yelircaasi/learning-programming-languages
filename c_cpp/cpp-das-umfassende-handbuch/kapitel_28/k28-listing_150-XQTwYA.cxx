#include <functional>
#include <iostream>


struct Zahlen {
    int dieZahl() {
        return 42;
    }
    int mehr(int n) {
        return n + data;
    }
    int data = 7;
};
int main() {
    auto func = std::mem_fn(&Zahlen::dieZahl);
    auto func2 = std::mem_fn(&Zahlen::mehr);
    auto zugriff = std::mem_fn(&Zahlen::data);
    Zahlen zahlen;
    std::cout << func(zahlen) << '\n';        // Ausgabe: 42
    std::cout << func2(zahlen, 66) << '\n';   // Ausgabe: 73
    std::cout << zugriff(zahlen) << '\n';     // Ausgabe: 7
}


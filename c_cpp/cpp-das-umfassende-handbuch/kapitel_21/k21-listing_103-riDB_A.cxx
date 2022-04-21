#include <iostream> // cout, cerr

constexpr int AUSGABE_VARIANTE = 0;  // Umschalten von cerr und cout

void message(const char* text) {
    if constexpr(AUSGABE_VARIANTE == 1)
        std::cerr << text << "\n";
    else
        std::cout << text << "\n";
}
int main() {
    message("Nachricht");
}


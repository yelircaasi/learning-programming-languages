#include <random>
#include <iostream>

int main() {
    std::default_random_engine e{};
    std::uniform_real_distribution<double> unif{3,7}; // im halboff. Intervall [3,7)
    double u = unif(e);                          // Zufallszahl ermitteln
    std::cout << u << '\n';                      // Beispielausgabe: 3.52615
}


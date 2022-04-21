int main() {
    Clock clock{ 23, 59, 59 };
    std::cout << clock << '\n'; // Ausgabe: 23:59:59
    clock.tick();
    std::cout << clock << '\n'; // Ausgabe: 00:00:00
}


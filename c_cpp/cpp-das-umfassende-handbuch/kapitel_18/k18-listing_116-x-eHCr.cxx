int main() {
    Calendar cal{ 2020, 2, 28 };
    std::cout << cal << '\n'; // Ausgabe: 2020-02-28
    cal.advance();
    std::cout << cal << '\n'; // Ausgabe: 2020-02-29
    cal.advance();
    std::cout << cal << '\n'; // Ausgabe: 2020-03-01
}


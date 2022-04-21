int main() {
    CalendarClock cc{ 2020,2,29, 23,59,59 };
    std::cout << cc << '\n'; // Ausgabe: 2020-02-29 23:59:59
    cc.tick();
    std::cout << cc << '\n'; // Ausgabe: 2020-03-01 00:00:00
}


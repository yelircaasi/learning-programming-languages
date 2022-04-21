#include <chrono>
#include <iostream>
void sleep(std::chrono::seconds dur) {
    std::cout << dur.count() << "s\n";
    /* ... */
}

int main() {
    using namespace std::chrono;
    sleep(3);          // Fehler: keine implizite Konvertierung von int
    sleep(seconds{4}); // okay
    sleep(5s);         // okay
    seconds x{6};
    sleep(x);          // okay
    auto y = 10s;
    y += 20s;          // Inkrementieren mit Sekunden
    sleep(y);          // nun also 30s
    y = y - 6s;        // Subtraktion von Sekunden
    sleep(y);          // und nun nur noch 24s
    y /= 2;            // Division durch einen Skalar
    sleep(y);          // 12s
    sleep(y + 7);      // Fehler: seconds+int geht nicht
}


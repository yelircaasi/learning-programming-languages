#include <iostream>
#include <thread>
using std::cout; using std::endl;

long fib(long n) { return n<=1 ? n : fib(n-1)+fib(n-2); }

void aufgabe1() { auto r = fib(40); cout << "fib(40)=" << r << endl; }
void aufgabe2() { auto r = fib(41); cout << "fib(41)=" << r << endl; }
void aufgabe3() { auto r = fib(42); cout << "fib(42)=" << r << endl; }

struct HintergrundAufgabe {
    void operator()() const {
        aufgabe1();
        aufgabe2();
        aufgabe3();
    }
};

int main() {
    HintergrundAufgabe hintergrundAufgabe{};  // Initialisierung, berechnet noch nichts
    std::thread meinThread{ hintergrundAufgabe }; // Berechnung startet
    // ... mehr ...
}


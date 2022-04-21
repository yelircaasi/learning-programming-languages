#include <iostream>
#include <thread>
#include <vector>
#include <exception>
using std::cout; using std::endl;

long fib(long n) { return n<=1 ? n : fib(n-1)+fib(n-2); }
void aufgabe1() { auto r = fib(40); cout << "fib(40)=" << r << endl; }

void hauptprogramm() {
    std::thread th{ &aufgabe1 };
    try {
        std::vector data{ 0,1,2 };
        data.at(666);                 // löst out_of_range aus
    } catch(std::runtime_error &ex) { // passt nicht auf out_of_range
         /* ... */                    // speziellen Fehler hier behandeln
    } catch( ... ) {
        th.join();
        throw;                        // Fehlerbehandlung außen fortsetzen
    }
    th.join();                        // wartet nach okay oder speziellem Fehler
}

int main() {
    try {
        hauptprogramm();
    } catch( ... ) {
        std::cout << "Ein Fehler ist aufgetreten\n";
    }
}


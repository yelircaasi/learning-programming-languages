#include <iostream>
#include <thread>
#include <vector>
#include <exception>
using std::cout; using std::endl;

long fib(long n) { return n<=1 ? n : fib(n-1)+fib(n-2); }
void aufgabe1() { auto r = fib(40); cout << "fib(40)=" << r << endl; }

void hauptprogramm() {
    try {
        std::thread th{ &aufgabe1 };
        std::vector data{ 0,1,2 };
        data.at(666);                     // löst out_of_range aus
        th.join();                        // würde warten
    } catch(std::runtime_error &ex) {     // passt nicht auf out_of_range
         /*...*/
    }
}

int main() {
  try {
    hauptprogramm();
  } catch( ... ) {                                // so weit, so gut, sieht sicher aus
    std::cout << "Ein Fehler ist aufgetreten\n";  // bekommen Sie nicht zu Gesicht
  }
}


#include <chrono>
#include <iostream>
using std::chrono::operator""s; // nur Literalsuffix verfügbar machen
constexpr auto limit = 10s;

void action(std::chrono::seconds dur) {
    if(dur <= limit) {          // vergleichen
       std::cout << dur.count() << "s\n";
    } else {
       std::cout << "zu lang!\n";
    }
}
int main() {
    action(4s);   // Ausgabe: 4s
    action(20s);  // Ausgabe: zu lang!
}


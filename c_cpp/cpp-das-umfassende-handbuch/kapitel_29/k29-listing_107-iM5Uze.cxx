#include <iostream>
#include <thread>
#include <chrono>
using namespace std::chrono; // seconds, suffix s

void delayPrint(seconds s, const char* msg) {
    std::this_thread::sleep_for(s);
    std::cout << msg << std::endl;
}

void lauf() {
    const char risiko[] = "Das geht nicht gut...";
    std::thread m{ delayPrint, 1s, risiko };
    m.detach();
    // hier wird der Bereich von 'risiko' verlassen
}
int main() {
    lauf();
    std::this_thread::sleep_for(2s); // noch 2 Sekunden warten
}


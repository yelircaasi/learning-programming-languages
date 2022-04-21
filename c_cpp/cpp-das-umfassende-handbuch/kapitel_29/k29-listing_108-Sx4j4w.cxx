#include <iostream>
#include <thread>
#include <chrono>
using namespace std::chrono; // seconds, suffix s
struct Zustand {
    int zaehler;
};
void zeigeZustand(const Zustand& zustand) {
    for(auto i : { 5,4,3,2,1 }) {
        std::cout << "zaehler: " << zustand.zaehler << std::endl;
        std::this_thread::sleep_for(1s);
    }
}
int main() {
    Zustand zustand { 4 };
    std::thread th{zeigeZustand, std::ref(zustand)}; // bleibt Referenz auf zustand
    std::this_thread::sleep_for(1s);
    zustand.zaehler = 501;
    std::this_thread::sleep_for(1s);
    zustand.zaehler = 87;
    std::this_thread::sleep_for(1s);
    zustand.zaehler = 2;
    th.join();
}


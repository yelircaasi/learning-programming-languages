#include <iostream>
#include <thread>
#include <chrono>
using namespace std::chrono; // seconds, suffix s

void delayPrint(seconds s, const std::string& msg) {
    std::this_thread::sleep_for(s);
    std::cout << msg << std::endl;
}
int main() {
    std::thread m1{ delayPrint, 1s, "Auf die Plaetze" };
    std::thread m2{ delayPrint, 2s, std::string{"fertig"} };
    std::string los = "los";
    std::thread m3{ delayPrint, 3s, los };
    m1.join(); m2.join(); m3.join();
}


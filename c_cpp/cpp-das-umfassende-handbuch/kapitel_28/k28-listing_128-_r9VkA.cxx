#include <chrono>
#include <iostream>
int main() {
    using namespace std::chrono;
    milliseconds myMs = 4'000ms;
    std::cout << myMs.count()/1000 << "s\n";
    std::cout << myMs.count()*1000 << "us\n";
    std::cout << duration_cast<seconds>(myMs).count() << "s\n"; // explizit
    std::cout << microseconds(myMs).count() << "us\n";          // wie implizit
}


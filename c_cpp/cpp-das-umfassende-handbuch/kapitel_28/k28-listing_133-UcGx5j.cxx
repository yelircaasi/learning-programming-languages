#include <iostream>
#include <chrono>
int main() {
    using namespace std::chrono;
    time_point<system_clock, seconds> t1{10000s};
    time_point<system_clock, seconds> t2{50000s};
    auto dur = t2 - t1;
    std::cout << duration_cast<hours>(dur).count() << "h"; // Ausgabe: 11h
}


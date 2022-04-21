#include <thread>
#include <iostream>

int count = 0; // wird simultan verändert

void run() {
    for(int i=0; i<1'000'000; ++i) {
        count += 1;   // ungeschützt
    }
}

int main() {
    std::cout << "Start: " << count << '\n';  // Ausgabe: Start: 0
    std::thread th1{ run };
    std::thread th2{ run };
    std::thread th3{ run };
    th1.join(); th2.join(); th3.join();
    std::cout << "Ende: " << count << '\n'; // Ausgabe sicher nicht: 3000000
}


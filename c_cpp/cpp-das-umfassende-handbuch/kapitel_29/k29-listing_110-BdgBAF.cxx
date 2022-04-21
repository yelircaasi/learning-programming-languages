#include <iostream>
#include <thread>
#include <chrono>
using namespace std::chrono; // seconds, suffix s
auto makeThread(std::string wer) {
    return std::thread{ [wer] {
        std::this_thread::sleep_for(1s);
        std::cout << "Viel Glueck, " << wer << std::endl;
    } };
}
int main() {
    auto th = makeThread("Jim"); // Ausgabe: Viel Glueck, Jim
    th.join();
}


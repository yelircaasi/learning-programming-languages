#include <thread>
#include <iostream>
#include <system_error>

int main() {
    try {
        std::thread().detach(); // das wird fehlschagen
    } catch(std::system_error& e) {
        std::cout
            << "system_error mit Code:" << e.code()
            << " Meldung:" << e.what()
            << '\n';
    }
}


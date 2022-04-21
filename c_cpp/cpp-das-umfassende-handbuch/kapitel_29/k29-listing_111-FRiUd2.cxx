#include <thread>
#include <chrono>
using namespace std::chrono; // seconds, suffix s
void kobraUebernehmenSie(std::thread job) {
    job.join();
}
int main() {
     std::thread th{ [] {
        std::this_thread::sleep_for(1s);
        std::cout << "Viel Glueck, Dan" << std::endl;
    } };
    kobraUebernehmenSie( std::move(th) );  // Zuständigkeit übertragen
}


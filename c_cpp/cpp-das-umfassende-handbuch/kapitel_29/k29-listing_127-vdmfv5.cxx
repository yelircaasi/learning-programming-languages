#include <iostream>
#include <string>
#include <thread>
#include <mutex>
thread_local unsigned int usage = 0;
static std::mutex cout_mutex;
void use(const std::string& thread_name) {
    ++usage;
    std::lock_guard lock(cout_mutex); // Ausgabe schützen
    std::cout << thread_name << ": " << usage << '\n';
}
int main() {
    std::thread a{use, "a"}, b{use, "b"};
    use("main");
    a.join(); b.join(); // warten, bis fertig
}


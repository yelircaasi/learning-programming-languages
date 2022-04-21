#include <thread>
#include <iostream>
int main() {
    std::cout << "Main: " << std::this_thread::get_id() << '\n';
    std::thread th{ []{
        std::cout << "Thread: " << std::this_thread::get_id() << '\n';
    }};
    th.join();
}


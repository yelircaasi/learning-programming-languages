#include <iostream>
#include <future>  // async
#include <chrono>
using std::cout; using std::endl; using namespace std::chrono;
long fib(long n) { return n<=1 ? n : fib(n-1)+fib(n-2); }
int main() {
    auto f43 = std::async(fib, 43);
    while(true) {
        auto fertig = f43.wait_for(500ms);
        if(fertig==std::future_status::timeout) {
            std::cout << "noch nicht..." << std::endl;
        } else {
            break;
        }
    }
    // abholen, ist sofort da
    cout << "fib(43): " << f43.get() << endl; // Ausgabe: fib(43): 701408733
}


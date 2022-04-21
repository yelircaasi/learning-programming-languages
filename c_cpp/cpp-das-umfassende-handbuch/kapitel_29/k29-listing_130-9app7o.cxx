#include <iostream>
#include <future>  // async
using std::cout; using std::endl;
long fib(long n) { return n<=1 ? n : fib(n-1)+fib(n-2); }

int main() {
    auto f40 = std::async(fib, 40);
    auto f41 = std::async(fib, 41);
    auto f42 = std::async(fib, 42);
    auto f43 = std::async(fib, 43);
    cout << "fib(40): " << f40.get() << endl; // Ausgabe: fib(40): 102334155
} // wartet auch auf f41, f42 und f43.


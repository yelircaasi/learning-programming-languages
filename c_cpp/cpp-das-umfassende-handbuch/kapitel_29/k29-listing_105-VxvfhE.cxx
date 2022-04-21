#include <iostream>
#include <thread>
using std::cout; using std::endl;

long fib(long n) { return n<=1 ? n : fib(n-1)+fib(n-2); }

void runFib(long n) {
    auto r = fib(n);
    cout << "fib("<<n<<")=" << r << endl;
}

long ack(long m, long n) { // Ackermannfunktion
    if(m==0) return n+1;
    if(n==0) return ack(m-1, 1);
    return ack(m - 1, ack(m, n-1));
}

void runAck(long m, long n) {
    auto r = ack(m, n);
    cout << "ack("<<m<<','<<n<<")=" << r << endl;
}

int main() {
    std::thread f40{ runFib, 40 };
    std::thread f41{ runFib, 41 };
    std::thread f42{ runFib, 42 };

    f40.join(); f41.join(); f42.join();

    std::thread a1{ runAck, 4, 0 };
    std::thread a2{ runAck, 4, 1 };
    std::thread a3{ runAck, 2, 700 };
    std::thread a4{ runAck, 3, 10 };

    a1.join(); a2.join(); a3.join(); a4.join();
}


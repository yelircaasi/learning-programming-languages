#include <iostream>
#include <utility> // pair

struct FibIt { // Status einer Fibonacci-Berechnung
   int prev_;
   int curr_;
   FibIt() : prev_{0}, curr_{1} {}
   explicit FibIt(int curr) : prev_{}, curr_{curr} {}
   FibIt& operator++() {
       auto tmp = prev_ + curr_; prev_ = curr_; curr_ = tmp; return *this; }
   int operator*() { return curr_; }
   friend bool operator!=(const FibIt& a, const FibIt& b) {
       return a.curr_ < b.curr_ || a.prev_ >= b.curr_; }
};
struct FibsRange { // Berechnungsauftrag
    int high_;
    FibsRange(int high) : high_{high} {}
};
FibIt begin(const FibsRange& fibs) {
    return FibIt{};
}
FibIt end(const FibsRange& fibs) {
    return FibIt{fibs.high_};
}
int main() {
    FibsRange fibs{1000};
    // Kurzform:
    for(auto f : fibs)  // implizites begin, end und !=
        std::cout << f << ' ';  // wendet operator* an
    std::cout << std::endl;
    // Ausgabe: 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987
    // entspricht Langform:
    auto b = begin(fibs);
    auto e = end(fibs);
    for( ; b != e; ++b)
        std::cout << *b << ' ';
    // Ausgabe: 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987
}


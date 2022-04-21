#include <unordered_set>     // unordered_set, unordered_multiset
#include <iostream>
#include <string>
#include <chrono>            // Zeitmessung

using std::cout;
using namespace std::chrono;

long long millisSeit(steady_clock::time_point start) {
    return duration_cast<milliseconds>(steady_clock::now()-start)
        .count();
}

struct BadHash {  // die schlechtestmögliche Hashfunktion als Funktor
    size_t   operator()(int) const { return 1; }
};
void timeStuff(size_t iters) {
    std::unordered_multiset<int,BadHash> data{};
    cout << iters << "...";
    auto start = steady_clock::now();
    for(size_t idx=0; idx<iters; ++idx) {
        data.insert( (int)idx );
    }
    cout << " " << millisSeit(start) << " ms" << std::endl;
}
constexpr size_t LIMIT = 20'000;
int main() {
    size_t iters = 100;
    while(iters < LIMIT) {
        timeStuff(iters);
        iters *= 2; // verdoppeln
    }
}


#include <set>               // set, multiset
#include <unordered_set>     // unordered_set, unordered_multiset
#include <iostream>
#include <string>
#include <chrono>            // Zeitmessung
using std::cout;
using namespace std::chrono;

long long millisSeit(steady_clock::time_point start) {
    return duration_cast<milliseconds>(steady_clock::now()-start).count();
}
constexpr size_t ITERATIONS = 100'000;
template<typename Cont, typename Func>
void timeStuff(std::string name, Cont data, Func genNum) {
    cout << name << "...";
    auto start = steady_clock::now();
    for(size_t idx=0; idx<ITERATIONS; ++idx) {
        data.insert( genNum(idx) );
    }
    cout << " " << millisSeit(start) << " ms" << std::endl;
}

int alleGleich(size_t) { return 7; }      // erzeugt immer die gleiche Zahl
int gestreut(size_t n) { return int(n); } // erzeugt unterschiedliche Zahlen
struct BadHash {  // die schlechtestmögliche Hashfunktion als Funktor
       size_t   operator()(int) const { return 1; }
};

int main() {
   std::multiset<int> m{};
   timeStuff("multiset           alleGleich        ", m, &alleGleich);
   timeStuff("multiset           gestreut          ", m, &gestreut);
   std::set<int> s{};
   timeStuff("set                alleGleich        ", s, &alleGleich);
   timeStuff("set                gestreut          ", s, &gestreut);
   std::unordered_multiset<int> um{};
   timeStuff("unordered_multiset alleGleich        ", um, &alleGleich);
   timeStuff("unordered_multiset gestreut          ", um, &gestreut);
   std::unordered_multiset<int,BadHash> umb{};
   timeStuff("unordered_multiset alleGleich badHash", umb, &alleGleich);
   timeStuff("unordered_multiset gestreut   badHash", umb, &gestreut);
}


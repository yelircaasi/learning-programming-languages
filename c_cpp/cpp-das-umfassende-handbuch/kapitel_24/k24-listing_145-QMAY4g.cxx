#include <set>
#include <functional> // function
using std::set; using std::function;
bool fcompZehner(int a, int b) { return a%10 < b%10; }
struct Fuenfer {
    bool operator()(int a, int b) { return a%5 < b% 5; }
};
int main() {
    // Funktor
    set<int, Fuenfer> ff1;
    ff1.insert(5);
    set<int> ff2(Fuenfer{}); // nur im K'tor reicht leider nicht
    // Lambda
    set<int,function<bool(int,int)>> ll1([](auto a, auto b) { return a%3 < b%3; });
    ll1.insert(3);
    auto lcomp = [](int a, int b) { return a%3 < b%3; };
    set<int, decltype(lcomp)> ll2(lcomp);
    ll2.insert(3);
    set<int> ll3(lcomp); // nur im K'tor reicht leider nicht
    // Funktionszeiger
    set<int, bool(*)(int,int)> zz1(&fcompZehner);        // C-Stil
    zz1.insert(10);
    set<int, function<bool(int,int)>> zz2(&fcompZehner); // C++-Stil
    zz2.insert(10);
    set<int, decltype(&fcompZehner)> zz3(&fcompZehner);  // C++-Stil
    zz3.insert(10);
}


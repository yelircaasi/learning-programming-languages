#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using std::to_string; using std::string; using std::vector;

struct Squares {
    mutable int n = 1;
    int operator()() const { return n*n++; }
};

int main() {
    vector<int> sq(10);
    std::generate(sq.begin(), sq.end(), Squares{});
    std::for_each(sq.begin(), sq.end(), [](auto n) {
        std::cout << n << " "; });
    std::cout << '\n';        // Ausgabe: 1 4 9 16 25 36 49 64 81 100

    string a = "NCC-";
    vector<int> b {1,7,0,1};
    vector<string> c(4);
    auto f = [](char c, int i) -> string { return c+to_string(i); };
    std::transform(
        a.begin(), a.end(),   // Eingabe 1
        b.begin(),            // Eingabe 2
        c.begin(),            // Ausgabe
        f);                   // string f(char,int)

    std::for_each(c.begin(), c.end(), [](auto s) {
        std::cout << s << " "; });
    std::cout << '\n';        // Ausgabe: N1 C7 C0 @MINUS@1
}


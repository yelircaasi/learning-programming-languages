#include <numeric> // accumulate, iota
#include <algorithm> // copy
#include <iostream>
#include <iterator> // ostream_iterator
#include <vector>
using std::accumulate; using std::cout; using std::vector;
struct Generator {
    int state_;
    void operator++() { state_ += state_; }
    operator int() { return state_; }
};
int main() {
    std::ostream_iterator<int> os{std::cout, " "}; // Streamausgabeiterator für int
    vector<int> data(7);
    std::iota(data.begin(), data.end(), 10);
    std::copy(data.begin(), data.end (), os);
    cout << '\n';          // Ausgabe 10 11 12 13 14 15 16
    vector<int> seq(7);
    std::iota(seq.begin(), seq.end(), Generator{2});
    std::copy(seq.begin(), seq.end(), os);
    cout << '\n';          // Ausgabe 2 4 8 16 32 64 128
}


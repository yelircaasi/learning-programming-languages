#include <set>
struct Zahl {
    int wert_ = 0;
    explicit Zahl(int w) : wert_{w} {}
};

bool operator<(const Zahl& links, const Zahl& rechts) {
    return links.wert_ < rechts.wert_;
}

int main() {
    std::set<Zahl> zahlen{};  // okay
    zahlen.insert( Zahl{3} ); // hier wird operator< gebraucht
}


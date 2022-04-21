#include <map>

struct Zahl {
    int wert_ = 0;
    explicit Zahl(int w) : wert_{w} {}
};

bool operator<(const Zahl& links, const Zahl& rechts) {
    return links.wert_ < rechts.wert_;
}

int main() {
    std::map<Zahl,int> zahlen{};                  // okay
    zahlen.insert( std::make_pair(Zahl{4},100) ); // hier wird operator< gebraucht
    zahlen[Zahl{5}] = 200;                        // hier ebenfalls
}


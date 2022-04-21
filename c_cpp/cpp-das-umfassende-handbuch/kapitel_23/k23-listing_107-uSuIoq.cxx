#include <iostream>
#include <vector>
#include <set>
#include <bitset>

template<typename IT>
std::ostream& druckeBinaer(std::ostream& os, IT begin, IT end)
{
    for(IT it=begin; it != end; ++it) {
        std::bitset<4> x(*it); // Zahl in bitset kopieren
        os << x << " ";
    }
    return os;
}

int main()
{
    std::vector<int> vdata { 2, 0, 15, 12 };
    druckeBinaer(std::cout, vdata.cbegin(), vdata.cend()) << "\n";
    // Ausgabe: 0010 0000 1111 1100

    std::set<int> sdata { 2, 0, 12, 15 };
    druckeBinaer(std::cout, std::begin(sdata), std::end(sdata)) << "\n";
    // Ausgabe: 0000 0010 1100 1111
    int adata[] = { 0,1,2,13,14,15 };
    druckeBinaer(std::cout, std::begin(adata), std::end(adata)) << "\n";
    // Ausgabe: 0000 0001 0010 1101 1110 1111
}


#include <random>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    static const size_t size = 10;
    default_random_engine e{};                // Zufallsgenerator
    vector<size_t> counts(size+1);
    binomial_distribution<int> muenzen{size}; // wirft 10 Münzen, 0- bis 10-mal Kopf

    for(auto i=120*1000; i>0; --i)
        ++counts[muenzen(e)];                 // Münzen werfen
    for(auto c : counts) cout<<" "<<c;
    cout << '\n';
    // Beispielausgabe:
    // 109 1159 5344 14043 24806 29505 24544 13973 5252 1150 115
}


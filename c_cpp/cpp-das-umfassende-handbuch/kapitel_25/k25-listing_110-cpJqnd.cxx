#include <iostream>
#include <algorithm>
#include <string>
void one(std::string &seq) {
    std::next_permutation(seq.begin(), seq.end());
    std::cout << seq << '\n';
}
int main() {
    std::string seq = "BDK";
    std::cout << seq << '\n'; // Ausgabe: BDK
    auto limit = 3*2*1;       // n!
    for(int i=0; i<limit; ++i)
        one(seq);
    // Hier ist die Sequenz wieder in ihrem Ursprungszustand
}


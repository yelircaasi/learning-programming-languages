#include <iostream>
#include <random>       // default_random_engine
#include <string>
#include <iterator>     // back_inserter
#include <algorithm>    // sample

int main() {
     std::default_random_engine zufall{};
     const std::string in = "abcdefgh";
     for(auto idx : {0,1,2,3}) {
         std::string out;
         std::sample(in.begin(), in.end(),
                 std::back_inserter(out), 5, zufall);
         std::cout << out << '\n';
     }
}


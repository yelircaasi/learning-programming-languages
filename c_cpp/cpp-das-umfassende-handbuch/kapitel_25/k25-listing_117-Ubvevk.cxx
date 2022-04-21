#include <vector>
#include <iostream>
// ... adjacent_pair von oben hier ...
int main() {
    std::vector v{1,2,3,4};
    auto f = [](auto a, auto b) { std::cout << (a+b) << ' '; };
    adjacent_pair(v.begin(), v.end(), f); // 3 5 7
    std::cout << '\n';

    std::vector x{4,8};
    adjacent_pair(x.begin(), x.end(), f); // 12
    std::cout << '\n';

    std::vector w{4};
    adjacent_pair(w.begin(), w.end(), f); // nichts
    std::cout << '\n';

    std::vector<int> y{};
    adjacent_pair(y.begin(), y.end(), f); // nichts
    std::cout << '\n';
}


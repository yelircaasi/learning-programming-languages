#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    std::vector<int> c{ 1,2,3,4 };
    std::for_each( c.begin(), c.end(), [](auto &n) { n*=n; }); // modifizierend
    std::cout << c[3] << '\n'; // Ausgabe: 16
}


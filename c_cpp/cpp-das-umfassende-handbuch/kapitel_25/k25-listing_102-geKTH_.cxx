#include <algorithm>
#include <vector>
#include <iostream>

void sort_uniq(std::vector<int> &data) {
    sort(data.begin(), data.end());
    auto newend = std::unique(data.begin(), data.end());
    data.erase(newend, data.end());
}

int main() {
    std::vector ns{1,5,2,3,9,2,2,2,2,1,5,2,2,3,1,1,2,2,1};
    sort_uniq(ns);
    std::for_each(ns.begin(), ns.end(), [](auto x) {
        std::cout << x << ' '; });
    std::cout << '\n'; // Ausgabe: 1 2 3 5 9
}


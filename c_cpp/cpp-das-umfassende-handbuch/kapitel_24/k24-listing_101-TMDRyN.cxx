#include <vector>
#include <iostream>
int main() {
    std::vector<int> numbers{ 1,2,3,4,5 };
    for(auto val : numbers) {
        std::cout << val << ' ';
    }
    std::cout << '\n';
}


#include <vector>
#include <iostream>

int main() {
    std::vector<int> numbers{ 1,2,3,4,5 };
    numbers.erase(numbers.begin(), numbers.end());
    std::cout << numbers.size() << "\n"; // gibt 0 aus
}


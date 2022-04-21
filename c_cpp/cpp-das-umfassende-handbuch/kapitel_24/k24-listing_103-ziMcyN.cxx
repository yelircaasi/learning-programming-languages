#include <set>
#include <iostream>
int main() {
    std::set<int> numbers{ 10, 20, 90 };
    auto nein = numbers.find(30);
    if(nein == numbers.end()) { std::cout << "nicht da.\n"; }
    auto ja = numbers.find(20);
    if(ja != numbers.end()) { std::cout << *ja << '\n'; }
}


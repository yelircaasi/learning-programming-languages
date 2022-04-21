#include <functional> // substract, minus, bind
#include <iostream>
using std::cout;
int substract(int a, int b) { return a - b; }
int main() {
    using namespace std::placeholders;
    cout << substract(9, 3) << '\n';  // Ausgabe: 6
    auto minus3 = std::bind(substract, _1, 3);
    cout << minus3(9) << '\n';        // Ausgabe: 6
    auto von9 = std::bind(substract, 9, _1);
    cout << von9(3) << '\n';          // Ausgabe: 6
    auto nochmalMinus3 = std::bind(std::minus<int>{}, _1, 3);
    cout << nochmalMinus3(9) << '\n'; // Ausgabe: 6
}


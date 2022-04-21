#include <vector>
#include <iostream>

void printAndMore(const std::vector<int>& data) { // by-const-ref
    std::cout << data[0] << std::endl;
    data[0] = 666;  // geht nicht, weil 'const int&'
}
int main() {
    std::vector zahlen {1,2,3};
    printAndMore(zahlen);
}


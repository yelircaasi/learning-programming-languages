#include <vector>
#include <iostream>  // cout, ostream
#include <algorithm> // sort, copy
#include <iterator>  // ostream_iterator
int main() {
    std::vector data { 100, 50, 1, 75, 25, 0 };    // vector<int>
    std::sort(std::begin(data), std::end(data));
    std::ostream_iterator<int> oit(std::cout," ");
    std::copy(std::begin(data), std::end(data), oit);
    // Ausgabe: 0 1 25 50 75 100
}


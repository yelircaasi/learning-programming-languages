#include <vector>
#include <iostream>   // cout
#include <iterator>   // ostream_iterator
#include <algorithm>  // copy

int main() {
  std::vector data { 1, 2, 3, 7, 9, 10 };
  std::ostream_iterator<int> out_it (std::cout,", "); // bei Zuweisung nach cout
  std::copy(data.begin(), data.end(), out_it); // alle Elemente in den Iterator
  std::cout << "\n";                           // Ausgabe: 1, 2, 3, 7, 9, 10,
}


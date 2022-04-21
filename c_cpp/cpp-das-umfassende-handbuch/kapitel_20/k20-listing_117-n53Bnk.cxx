#include <iostream>   // cout
#include <iterator>   // ostream_iterator
#include <algorithm>  // copy

int main () {
  int data[6] = { 1, 2, 3, 7, 9, 10 };
  std::ostream_iterator<int> out_it (std::cout,", ");
  std::copy(data, data+6, out_it);           // Zeiger als Iteratoren
  std::cout << "\n";                         // Ausgabe: 1, 2, 3, 7, 9, 10
}


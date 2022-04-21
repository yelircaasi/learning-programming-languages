#include <random>
#include <vector>
#include <iostream>
#include <functional>

void wuerfel() {
  std::default_random_engine engine{};
  std::vector<size_t> counts{0,0,0,0,0,0};
  std::uniform_int_distribution<int> w6{0, 5}; // gleichverteilte Ganzzahlen
  auto w = std::bind(w6, engine);              // w() = w6(engine)
  for(auto i=1200*1000; i>0; --i) ++counts[w()];
  for(auto c : counts) std::cout<<" "<<c;
  std::cout << '\n';
}

int main() {
    wuerfel();
}


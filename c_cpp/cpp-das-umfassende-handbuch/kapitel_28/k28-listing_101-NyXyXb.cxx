#include <iostream>
#include <string>
#include <algorithm> // min, max
#include <tuple>
using std::tuple; using std::make_tuple; using std::get; using std::cout;
using std::string;

tuple<int,int,int> ordne(int a, int b, int c) {
  using std::min; using std::max;
  auto x = min(a,min(b,c));
  auto y = max(min(a,b), min(max(a,b),c));
  auto z = max(a,max(b,c));
  return make_tuple(x, y, z);
}

auto praeser(int jahr) {
  using namespace std::literals;
  if(jahr>=2017)
    return make_tuple("Frank-Walter"s, "Steinmeier"s, "SPD"s, 1956);
  if(jahr>=2012)
    return make_tuple("Joachim"s, "Gauck"s, "-"s, 1940);
  // ...
}

int main() {
  tuple<int,int,int> zs = ordne(23, 42, 7);
  cout << get<0>(zs) <<' '<< get<1>(zs) <<' '<< get<2>(zs) <<'\n';// Ausgabe: 7 23 42
  auto ps = praeser(2015);
  cout << get<1>(ps) << '\n'; // Ausgabe: Gauck
}


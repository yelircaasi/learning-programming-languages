// -*- mode: c++ -*-
#include <iostream>
#include <set>

#include <functional> // invoke
#include <tuple> // apply

using std::set; using std::cout;
using std::invoke;
using std::apply;

int main() {
    set<int> data { 1,2,3,4,5,6 };
    auto r = data.equal_range(4);
    cout << std::distance(r.first, r.second) << '\n';
    //= 1

#if 0
    cout << invoke(std::distance, r.first, r.second) << '\n';
    //= 1
    cout << apply(std::distance, r) << '\n';
    //= 1
    cout << apply(std::distance, make_tuple(r.first, r.second)) << '\n';
    //= 1
    cout << apply(std::distance, data.equal_range(4)) << '\n';
    //= 1
#endif

   cout << apply(std::distance<set<int>::iterator>, data.equal_range(4)) << '\n';
   //= 1

    auto d = [](auto b, auto e) { return std::distance(b, e); };
    cout << invoke(d, r.first, r.second) << '\n';
    //= 1
    cout << apply(d, r) << '\n';
    //= 1
    cout << apply(d, make_tuple(r.first, r.second)) << '\n';
    //= 1
    cout << apply(d, data.equal_range(4)) << '\n';
    //= 1
}

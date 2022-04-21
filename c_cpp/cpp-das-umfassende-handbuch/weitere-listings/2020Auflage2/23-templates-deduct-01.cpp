// -std=gnu++2a
#include <vector>
#include <string>
#include <typeinfo>
#include <iostream>

// 23-templates-deduct-01.x
int main() {
    std::vector<std::string> v1 { "aaa", "bbb"};
    std::cout << typeid(v1).name() << "\n";
    //= St6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE

    std::vector v2 { std::string("aaa"), std::string("bbb")}; // deduce <strring>
    std::cout << typeid(v2).name() << "\n";
    //= St6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE

    std::vector v3 { "aaa", "bbb" }; // deduce <const char*>
    std::cout << typeid(v3).name() << "\n";
    //= St6vectorIPKcSaIS1_EE

    using namespace std::string_literals;
    std::vector v4 { "aaa"s, "bbb"s }; // deduce <string>
    std::cout << typeid(v4).name() << "\n";
    //= St6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE
}

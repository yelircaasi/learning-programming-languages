#include <tuple>
#include <iostream>

template<typename ... Args>
auto conv2tuple(Args ... args) {
    return std::make_tuple(args...);
}

int main() {
    auto mytuple = conv2tuple("ende", 2, 3.14, 'A', false);
    std::cout << std::get<2>(mytuple) << '\n'; // Ausgabe: 3.14
}


#include <iostream>
#include <charconv>
#include <string_view>
#include <array>
int main() {
    std::array<char, 10> str {};
    if(auto [p, ec] = std::to_chars(str.data(), str.data() + str.size(), 42);
       ec == std::errc{} )
        std::cout << std::string_view(str.data(), p - str.data()) << "\n";
}


#include <charconv>
#include <vector>
#include <iostream>
#include <string>

std::vector<size_t> num_to_vec(const std::string& nums) {
    std::vector<size_t> result {};
    // ohne Leerzeichen am Ende
    const auto end = nums.data() + nums.find_last_not_of( ' ' ) + 1;
    const char* st = nullptr; // Zählpointer in der Schleife
    auto last = nums.data();  // letztes nicht übersetztes Zeichen
    size_t n;                 // konvertierte Zahl
    do {
        for(st = last; (st<end)&&(*st==' ' ); ++st); // überspringe ' '
        if (last = std::from_chars(st, end, n).ptr; last != st)
            result.push_back(n);                     // speichere Zahl
    } while (last != st);
    return result;
}

void fehlerDemo(const char* buf, size_t sz) {
    int n;
    auto [p, ec] = std::from_chars(buf, buf+sz, n);
    if (ec != std::errc{}) {
       const auto error = std::make_error_code(ec);
       std::cout << error.message() << '\n';
    }
}

int main() {
    auto result = num_to_vec("12 33 43");

    for(auto r : result) std::cout << r << " ";
    std::cout << '\n';
    // Ausgabe: 12 33 43

    fehlerDemo("XYZ", 4);
    // Ausgabe: Invalid argument

    fehlerDemo("123123123123123", 16);
    // Ausgabe: Numerical result out of range
}


#include <array>
#include <iostream>
#include <type_traits> // is_literal_type
class Value {
    int val_;
public:
    constexpr Value(int val) : val_{val} {};
    constexpr operator int() const { return val_; }
};
namespace lit {
    constexpr Value operator"" _val(const char*, size_t sz) { return Value(sz); }
}
struct Nope {
    constexpr Nope() {};
    virtual ~Nope() {};                // nicht trivialer Destruktor
};
int main() {
    using namespace lit;
    constexpr Value fuenf{5};
    std::array<int,"11111"_val> data;  // benutzerdefiniertes Literal verwenden
    std::cout << data.size() << '\n';                        // Ausgabe: 5
    std::cout << std::boolalpha;
    std::cout << std::is_literal_type<Value>::value << '\n'; // Ausgabe: true
    std::cout << std::is_literal_type<Nope>::value << '\n';  // Ausgabe: false
}


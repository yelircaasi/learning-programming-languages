#include <array>
class Value {
    int val_;
public:
    constexpr Value(int val) : val_{val} {};
    constexpr int get() const { return val_; }
};
constexpr Value fuenf{5}; // geht, Value ist literaler Datentyp
std::array<int,fuenf.get()> data; // geht, get ist constexpr


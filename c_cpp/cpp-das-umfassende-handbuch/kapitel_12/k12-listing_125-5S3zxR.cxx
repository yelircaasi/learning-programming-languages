class Year {
public:
    using value_type = int;             // Typalias einführen
    value_type value_;                  // eigentlich intern verwendeter Typ
public:
    explicit Year(value_type v) : value_{v} {}
    value_type value() { return value_; }
};
int main() {
   Year year{ 2019 };                   // hier auf Compilerkonvertierung zählen
   Year::value_type val = year.value(); // verwenden Sie ::
}


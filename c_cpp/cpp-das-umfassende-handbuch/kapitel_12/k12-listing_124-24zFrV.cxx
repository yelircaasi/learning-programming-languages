class Year {
    int value_;                         // eigentlich intern verwendeter Typ
public:
    explicit Year(int v) : value_{v} {} // Typ wird Teil des Interface
    int value() { return value_; }      // auch bei der Rückgabe
};
int main() {
   Year year{ 2019 };                   // Typ int
   int val = year.value();              // passender Typ
}


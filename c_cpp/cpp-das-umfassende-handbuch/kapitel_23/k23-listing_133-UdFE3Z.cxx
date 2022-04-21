#include <iostream>

template <typename T, size_t n=1>    // Non-Type-Parameter mit Defaultwert
class FixedArray {
    T data_[n] {0};                  // Non-Type-Parameter verwenden
public:
    T& operator[](size_t index) { return data_[index]; }
    static constexpr size_t size() { return n; }
    void print(std::ostream &os) const {
        for(auto it : data_)
            os << it << ' ';
        os << '\n';
    }
};

int main() {
    FixedArray<int,10> vals {};        // n= 10
    for(size_t idx=0; idx < vals.size(); ++idx) {
        vals[idx] = idx+idx;
    }

    vals.print(std::cout);             // Ausgabe: 0 2 4 6 8 10 12 14 16 18
    FixedArray<double> dvals;          // Defaultparameter für n
    std::cout << dvals.size() << '\n'; // Ausgabe: 1
}


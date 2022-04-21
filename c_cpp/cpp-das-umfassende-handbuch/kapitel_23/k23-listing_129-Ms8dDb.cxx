#include <string>
#include <vector>
#include <set>
#include <tuple>
#include <memory> // shared_ptr

template <typename T>
class MyStuff {
    T data_;

public:
    MyStuff() : data_{} {}             // default c'tor
    MyStuff(const T& d) : data_{d} { } // copy c'tor
    T getStuff() const { return data_; }
};

class IntValue {
    int val_;
public:
    explicit IntValue(int val=0) : val_(val) {}
    int getInt() const { return val_; }
};
int main() {
    MyStuff intStuff(12);              // wird zu MyStuff<int>
    std::vector vs{ 1,2,3,4 };         // wird zu vector<int>
    MyStuff ivalStuff{ IntValue{33} }; // wird zu MyStuff<IntValue>
    std::tuple tpl{ 23, 'a' };         // wird zu tuple<int,char>
    std::set zweiDrei (vs.begin()+1, vs.end()-1); // wird zu set<int>
    // Kann der Compiler nicht deduzieren:
    MyStuff<double> dblStuff;              // kein Konstruktorargument
    std::vector<char> vcs(10);             // Größe 10, aber von welchem Typ?
    std::shared_ptr<int> ptr{new int{88}}; // keine Regel für int*
}


#include <iostream>
#include <string>

template <typename T>
class MyContainer {
    T data_;
public:
    void setData(const T& d) { data_ = d; } // allgemeiner Fall
    T getData() const { return data_; }     // allgemeiner Fall
};
template<>                                  // Spezialisierung
void MyContainer<std::string>::setData(const std::string& d) {
    data_ = "[" + d + "]";
}
int main() {
    MyContainer<std::string> mcString;
    mcString.setData("Geschichte");
    std::cout << mcString.getData() << '\n';  // Ausgabe: [Geschichte]
    MyContainer<int> mcInt;
    mcInt.setData(5);
    std::cout << mcInt.getData() << '\n';     // Ausgabe: 5
}


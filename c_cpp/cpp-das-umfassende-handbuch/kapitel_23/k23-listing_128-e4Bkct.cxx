#include <iostream>
#include <string>

template <typename T>
class MyContainer {
    T data_;
public:
    void setData(const T& d) { data_ = d; }
    T getData() const { return data_; }
};
class IntValue {
    int val_;
public:
    explicit IntValue(int val=0) : val_(val) {}
    int getInt() const { return val_; }
};

int main() {
    // C-Array mit drei MyContainer<double>-Instanzen
    MyContainer<double> dcont[3];
    dcont[0].setData(123.123);
    dcont[1].setData(234.234);
    std::cout << dcont[0].getData() << std::endl;
    std::cout << dcont[1].getData() << std::endl;
    // eigener Datentyp als formaler Parameter
    IntValue ival{100'000};
    MyContainer<IntValue> scont;
    scont.setData(ival);
    std::cout << scont.getData().getInt() << std::endl;
    // string als formaler Parameter
    std::string str("Text");
    MyContainer<std::string> strCont;
    strCont.setData(str);
    std::cout << strCont.getData() << std::endl;
}


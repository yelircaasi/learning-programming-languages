#include <iostream>

template<typename T, typename U>
class MyPair {
    T data01_;
    U data02_;
public:
    MyPair(const T& t,const U& u) : data01_{t}, data02_{u} {}
    void print(std::ostream& os) const {
        os << data01_ << " : " << data02_ << std::endl;
    }
};

int main() {
    std::string month{"Januar"};
    int temp = -5;
    MyPair<std::string, int> temperatur{month, temp};
    temperatur.print(std::cout);
}


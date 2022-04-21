#include <iostream>

struct Zahl {
    int wert_;
};
template<typename TYP>
void print(TYP value) {
    std::cout << value << "\n";
}
int main() {
    print(5);
    print(-10.25);
    print("Flamingo");
    Zahl sieben { 7 };
    print(sieben);
}


#include <array>
int main() {
    std::array<int, 5> arr5{};     // Literal und somit ein konstanter Ausdruck
    std::array<int, 2+3> arr23{};  // 2+3 kann der Compiler auswerten
    const size_t SIZE = 5;         // definiert eine Konstante
    std::array<int, SIZE> arrSC{}; // kann der Compiler verwenden @GEDSTRICH@ oft
    size_t size = 7;
    std::array<int,size> arrVar{}; // eine Variable können Sie nicht verwenden
}


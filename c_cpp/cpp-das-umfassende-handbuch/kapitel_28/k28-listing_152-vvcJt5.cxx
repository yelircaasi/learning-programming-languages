#include <variant>
#include <iostream>
using std::cout;
struct TypGruss {
  void operator()(int) const { cout << "Hallo int"; }
  void operator()(float) const { cout << "Servus float"; }
};
int main() {
    std::variant<int, float> var{};
    var = 12;                                   // Zustand int
    std::visit([](auto a) { cout << a; }, var); // generisches Lambda
    cout << std::endl;
    var = 3.456f;                               // Zustand float
    std::visit(TypGruss{}, var);                // Funktor mit Überladungen
    cout << std::endl;
}


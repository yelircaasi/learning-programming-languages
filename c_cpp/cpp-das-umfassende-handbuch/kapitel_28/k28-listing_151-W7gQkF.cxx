#include <variant> 
using std::get;
int main() {
    std::variant<int, float> v{};
    v = 12;                  // Zustand wechselt auf int
    auto i = get<int>(v);    // holt den int
    std::cout << i << '\n';  // Ausgabe: 12
    v = 3.456f;              // Zustand wechselt auf float
    std::cout << get<float>(v) << '\n';  // Ausgabe: 3.456
    get<double>(v);          // Fehler
    get<3>(v);               // Fehler
    std::variant<int, float> w{};
    w = get<float>(v);       // Zugriff über Typ
    w = get<1>(v);           // Zugriff geht auch über Index
    w = v;                   // ganze Zuweisung geht auch
    try {
        get<int>(w);         // löst Exception aus
    } catch (std::bad_variant_access&) { /* ... */ }
}


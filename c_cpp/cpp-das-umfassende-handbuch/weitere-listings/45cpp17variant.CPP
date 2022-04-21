    #include <variant>
    #include <iostream>
    using std::get;
    int main() {
        std::variant<int, float> v{};
        v = 12;                  // Zustand wechselt auf int
        auto i = get<int>(v);    // hold den int
        std::cout << i << '\n';  // (+Ausgabe:+) 12
        //= 12
        v = 3.456f;               // Zustand wechselt auf float
        std::cout << get<float>(v) << '\n';  // (+Ausgabe:+) 3.456
        //= 3.456

        std::variant<int, float> w{};
        w = get<float>(v);             // Zugriff über Typ
        w = get<1>(v);               // Zugriff geht auch über Index
        w = v;                       // ganze Zuweisung geht auch
        try {
            get<int>(w);           // löst Exception aus
        } catch (std::bad_variant_access&) {
            std::cout << "enthalte gerade kein int\n";
            //= enthalte gerade kein float
        }
    }

#include <typeinfo>               // operator typeid
#include <typeindex>              // type_index
#include <map>
#include <string>
#include <iostream>
template <typename T>
void output(std::ostream& os, T val) { // einen Typnamen ausgeben
    // static: beim ersten Mal initialisiert
    static const std::map<std::type_index,std::string> type_names {
        { std::type_index(typeid(const char*)), "const char*"},
        { std::type_index(typeid(char)),  "char"},
        { std::type_index(typeid(int)),  "int"},
        { std::type_index(typeid(double)),  "double"},
        { std::type_index(typeid(bool)),  "bool"},
    };
    const std::string name = type_names.at(std::type_index(typeid(T)));
    os << name << ": " << val << '\n';
}
// rekursives variadisches Funktionstemplate:
template<typename First, typename ... Rest>
void output(std::ostream &os, First first, Rest ... rest) {
    output(os, first);           // einzelner Aufruf mit vorderstem Element
    output(os, rest ...);        // Rekursion mit Rest der Elemente
}
int main() {
  output(std::cout, 3.1415);                      // normales Template
  output(std::cout, "ende", 2, 3.14, 'A', false); // rekursive variadische Funktion
}


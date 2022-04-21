// modul.hpp
#include <string>
#include <iostream>

namespace plant {
    class Baum {
        std::string name_;
    public:
        explicit Baum(const std::string& name);
        void print(std::ostream& os) const;
    };
    std::ostream& operator<<(std::ostream& os, const Baum& arg);
}

// modul.cpp
#include "modul.hpp"
namespace {  // anonymer Namensraum
    std::string PREFIX = "BAUM:";
    void printInfo(std::ostream& os) {
        os << "Autor: Torsten T. Will\n";
    }
}
bool debug = false;  // global, kein Namensraum
namespace plant {
    Baum::Baum(const std::string& name)
        : name_{name} {}
    void Baum::print(std::ostream& os) const {
        os << PREFIX << name_;
    }
    std::ostream& operator<<(std::ostream& os, const Baum& arg) {
        if(debug) printInfo(os);
        arg.print(os); return os;
    }
}

// main.cpp
#include "modul.hpp"
int main() {
    plant::Baum x{"x"};
    x.print(std::cout); std::cout << "\n";
}


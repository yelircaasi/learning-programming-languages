#include <vector>
#include <memory>           // unique_ptr, shared_ptr
struct Typ1 {               // automatische komplette Kopie der Ressource
    std::vector<char> data_;
    Typ1(int n) : data_(n) {}
};
struct Typ2 {               // Kopie untersagt, Verschieben möglich
    std::unique_ptr<int[]> data_;
    Typ2(int n) : data_(new int[n]) {}
};
struct Typ3 {               // Kopie erlaubt, Ressource wird dann sauber geteilt
    std::shared_ptr<Typ1> data_;
    Typ3(int n) : data_(std::make_shared<Typ1>(n)) {}
};


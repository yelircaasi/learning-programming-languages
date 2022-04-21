#include <vector>
#include <string>

struct Praesident {
  std::string name_; int jahr_;
  Praesident(std::string name,  int jahr)    // name ist by Value
    : name_{std::move(name)}, jahr_{jahr}    // move spart hier eine weitere Kopie
    { }
};

int main() {
    using namespace std; // String-Literale ermöglichen
    vector<Praesident> praesidenten{};
    praesidenten.emplace_back("Heuss"s, 1949);
    praesidenten.emplace_back("Luebke"s, 1959);
    praesidenten.emplace_back("Heinemann"s, 1969);
    // ...
    vector<int> v{};
    v.reserve(100);
    for(int idx = 0; idx < 100; ++idx)
        v.push_back(idx);
    // ...
}


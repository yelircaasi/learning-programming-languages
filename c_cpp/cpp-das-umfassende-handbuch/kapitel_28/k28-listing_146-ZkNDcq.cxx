#include <set>
#include <string>
struct Drachen {
    std::string name_;
};
namespace std {
    template<> struct less<Drachen> { // Templatespezialisierung
        bool operator()(const Drachen &lhs, const Drachen &rhs) const {
            return lhs.name_ < rhs.name_;
} }; }
int main() {
  std::set<Drachen> drachen {
    Drachen{"Smaug"},Drachen{"Glaurung"},Drachen{"Ancalagon"},Drachen{"Scatha"}};
}


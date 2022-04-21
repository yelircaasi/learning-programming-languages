#include <vector>
#include <iostream>
using std::vector; using std::cout;
template<typename Elem>
std::ostream& operator<<(std::ostream&os, const vector<Elem>&data) {
    for(auto &e : data) {
        os << e << ' ';
    }
    return os;
}
int main() {
   // Beispielcode hier
}


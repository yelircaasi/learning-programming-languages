#include <valarray>
#include <iostream>
using namespace std;
template<typename T>
ostream& operator<<=(ostream &os, const valarray<T>& a) { // '<<=' mit Newline
    for(const auto &v : a) os << v << ' ';
    return os << '\n';
}
int main() {
    // ... Beispielcode hier ...
}


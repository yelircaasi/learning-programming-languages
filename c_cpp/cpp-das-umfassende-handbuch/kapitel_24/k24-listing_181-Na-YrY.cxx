#include <unordered_map>
#include <iostream>
using std::unordered_map; using std::cout;
template<typename K, typename T>
std::ostream& operator<<=(std::ostream&os, const unordered_map<K,T>&data) {
    for(auto &e : data) {
        os << e.first << ":" << e.second << ' ';
    }
    return os << '\n'; // bei operator<<= mit Zeilenumbruch
}
int main() {
   // Beispielcode hier
}


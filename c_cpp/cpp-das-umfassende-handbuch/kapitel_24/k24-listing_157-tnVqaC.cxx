#include <map>
#include <iostream>
using std::map; using std::cout;
int main() {
    map<int,char> alpha;
    cout << alpha.size() << '\n';       // 0 natürlich
    if( alpha[5] == '3' ) { /* ... */ }
    cout << alpha.size() << '\n';       // nun 1
    char x = alpha[99];                 // klappt
    cout << alpha.size() << '\n';       // und nun 2
}


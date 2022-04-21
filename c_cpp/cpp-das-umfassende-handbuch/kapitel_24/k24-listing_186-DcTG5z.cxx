#include <unordered_set> // unordered_multiset
#include <iostream>
#include <string>
using std::unordered_multiset; using std::cout; using std::string;
int main() {
    const string in = "Keines meiner beiden Beine zeigt einen Schein.";
    unordered_multiset<int> cs(in.begin(), in.end()); // string als Container
    cout << cs.count( 'e' ) << " mal e\n"; // Ausgabe: 10 mal e
}


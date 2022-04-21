#include <iostream>
#include <iomanip>
using std::cin; using std::cout; using std::endl;
void f(bool b) {
     cout << b << endl;                    // Ausgabe:  true
}
int main () {
    bool b=true;
    cout << std::boolalpha << b << endl;   // Ausgabe: true
    b=false;
    cout << b << endl;                     // Ausgabe: false
    f(true);
    cout << std::noboolalpha << b << endl; // Ausgabe: 0
    b=true;
    cout << b << endl;                     // Ausgabe: 1
}


#include <iostream>
#include <ios>
using std::cout; using std::endl;
void f() {
    int val = 100;
    cout << val << endl;               // Ausgabe: 0x64
}
int main() {
    int val = 255;
    cout << std::showbase;
    cout << std::dec << val << endl;   // Ausgabe: 255
    cout << std::hex << val << endl;   // Ausgabe: 0xff
    f();
    cout << std::oct << val << endl;   // Ausgabe: 0377
    cout << val << std::endl;          // Ausgabe: 0377
}


#include <iostream>
#include <ios> // hex, dec
using std::cout; using std::endl;
int main() {
    int val = 255;
    cout << std::showbase << std::hex << val << endl;   // Ausgabe: 0xff
    cout << std::noshowbase << std::dec << val << endl; // Ausgabe: 255
}


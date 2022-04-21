#include <iostream>
using std::cout; using std::endl;
int main() {
    int val = 255;
    std::ios::fmtflags ff = std::cout.flags();
    cout.flags(std::ios::hex | std::ios::showbase);
    cout << val << endl;  // Ausgabe: 0xff
    cout.flags(ff);
    cout << val << endl; // Ausgabe: 255
}


#include <iostream>
#include <ios>        // left, right, internal
#include <iomanip>    // setw

using std::cout; using std::endl;

int main() {
    double dval = 3.14159;
    std::ios_base::fmtflags ff(std::ios::scientific|std::ios::uppercase);
    cout << std::setiosflags(ff);
    cout << dval << endl;                           // Ausgabe: 3.141590E+00

    cout << std::resetiosflags(ff) << dval << endl; // Ausgabe: 3.14159

    cout << std::setprecision(3) << dval << endl;   // Ausgabe: 3.14
    cout << std::setw(10);
    cout << std::setfill( '*' ) << 1246 << endl;    // Ausgabe: ******1246
}


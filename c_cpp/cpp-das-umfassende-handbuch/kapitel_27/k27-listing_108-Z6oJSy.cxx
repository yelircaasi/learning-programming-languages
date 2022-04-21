#include <iostream>
#include <ios>        // left, right, internal
#include <iomanip>    // setw
using std::cout; using std::cin; using std::endl;
std::ostream& tabl(std::ostream& os) {
    os << '\t';
    return os;
}
std::istream& firstNum(std::istream& is) {
    char ch;
    is.get(ch);
    if( (ch >= '0') && (ch <= '9') ) {
        std::cin.putback(ch);
    }
    return is;
}
int main() {
    int val=0;
    cout << "Text1" << tabl << "Text2" << endl; // Ausgabe: Text1 (tab) Text2
    cout << "Eingabe machen: ";
    cin >> firstNum >> val;
    cout << val << std::endl; // Ausgabe: 12345
}


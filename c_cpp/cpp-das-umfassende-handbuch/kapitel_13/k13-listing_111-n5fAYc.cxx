#include <string>
#include <iostream>
using std::string; using std::cout;
class Widget {
    string name_{};
public:
    const string& readName() const;        // const&-Rückgabe, const-Methode
    string& getName();                     // &-Rückgabe
};
const string& Widget::readName() const { return name_; }
string& Widget::getName() { return name_; }
int main() {
    Widget w{};
    const string& readonly = w.readName(); // const&, unveränderbar
    cout << "Name: " << readonly << "\n";  // noch "" leer
    string& readwrite = w.getName();       // &, veränderbar
    readwrite.append("dran");       // verändert auch name_ und readonly
    cout << "Name per readwrite: " << readwrite << "\n"; // "dran"
    cout << "Name per readonly: " << readonly << "\n";   // auch "dran"
}


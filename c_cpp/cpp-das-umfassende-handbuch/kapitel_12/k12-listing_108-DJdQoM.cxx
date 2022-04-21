#include <string>
#include <iostream>    // ostream

using std::string; using std::ostream;

struct Person {
    string name_;
    int alter_;
    string ort_;
    ostream& drucke(ostream& os) {  // Methode inline definiert
        return os << name_ << " ("<< alter_<<") aus " << ort_;
    }
};


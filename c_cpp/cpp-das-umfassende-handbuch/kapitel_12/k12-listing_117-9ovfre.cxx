#include <string>
using std::string;

class Person { // eine Klasse beginnt mit privater Sichtbarkeit
    string name_;
    int alter_;
    string ort_;
public:  // alles ab hier darf von außen verwendet werden
    Person(string n, int a, string o)
      : name_{n}, alter_{a}, ort_{o} { }
    void drucke();
};


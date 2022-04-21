#include <string>
using std::string;

struct Person {
private: // alles ab hier kann von außen nicht benutzt werden
    string name_;
    int alter_;
    string ort_;
public:  // alles ab hier darf von außen verwendet werden
    Person(string n, int a, string o)
      : name_{n}, alter_{a}, ort_{o} { }
    void drucke();
};


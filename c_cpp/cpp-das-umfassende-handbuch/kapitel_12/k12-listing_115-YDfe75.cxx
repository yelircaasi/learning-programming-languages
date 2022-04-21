#include <string>

using std::string;

struct Person {
    string name_;
    int alter_;
    string ort_;
    Person(string n, int a, string o)
            {           // Initialisierungsliste fehlt
        init(n, a, o);  // fragwürdiger "Initialisierungsaufruf"
    }
    void init(string n, int a, string o) {
      name_ = n; alter_ = a; ort_ = o;
    }
};


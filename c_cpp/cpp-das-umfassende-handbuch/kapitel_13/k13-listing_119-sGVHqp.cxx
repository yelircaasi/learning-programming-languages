#include <map>
#include <string>
using std::map; using std::string;
struct MyClass {
  bool isFound(const map<int,string> &dict,     // unveränderbarer Eingabeparam.
               const int &key,                  // ebenso
               string &result                   // Ausgabeparameter: kein const
               ) const                          // Instanz von MyClass const
  {
    const map<int,string>::const_iterator where // Verweis und Wert fest
      = dict.find(key);
    if(where == end(dict)) {
      return false;
    } else {
      result = where->second;
      return true;
    }
  }
};


#include <unordered_map>
#include <iostream>
#include <string>
using std::string; using std::unordered_map; using std::cout;
struct Stadt {
    string name_;
    explicit Stadt(const string &name) : name_{name} {}
    friend bool operator==(const Stadt& a, const Stadt &b)
        { return a.name_ == b.name_; }
 };
 struct StadtHash {
     std::hash<string> sHash;
     size_t operator()(const Stadt& a) const {
         return sHash(a.name_);
     }
 };
 int main() {
     unordered_map<Stadt,string,StadtHash> abk{
         {Stadt{"Bielefeld"}, "BI"},
         {Stadt{"Jetzendorf"}, "JE"},
         {Stadt{"Tharandt"}, "TH"},
         };
     cout << abk[Stadt{"Bielefeld"}] << '\n'; // Ausgabe: BI
 }


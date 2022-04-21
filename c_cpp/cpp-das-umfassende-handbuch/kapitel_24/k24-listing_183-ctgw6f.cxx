#include <unordered_set> // unordered_multiset
#include <iostream>
#include <string>
using std::string; using std::unordered_multiset; using std::cout;

struct Stadt {
    string name_;
    explicit Stadt(const string &name) : name_{name} {}
    friend bool operator==(const Stadt& a, const Stadt &b)
        { return a.name_ == b.name_; }
 };
 struct Eintrag { string stadt_; int plz_; };
 struct EqEintrag {
     bool operator()(const Eintrag&a, const Eintrag&b) const {
         return a.stadt_==b.stadt_;
     }
 };
 struct HashEintrag {
     std::hash<string> sHash;
     size_t operator()(const Eintrag& a) const {
         return sHash(a.stadt_);
     }
 };

 int main() {
     unordered_multiset<Eintrag,HashEintrag,EqEintrag> verzeichnis{
         {Eintrag{"Bielefeld", 33615}},
         {Eintrag{"Bielefeld", 33617}},
         {Eintrag{"Bielefeld", 33621}},
         {Eintrag{"Berlin", 10032}},
         {Eintrag{"Berlin", 10027}},
         };

     const Eintrag such{"Bielefeld", 0}; // plz spielt bei Suche keine Rolle
     cout<<"Bielefeld hat "<<verzeichnis.count(such)<<" Postleitzahlen.\n";

     cout<<"Die Postleitzahlen von Bielefeld sind:\n";
     auto [wo, bis] = verzeichnis.equal_range(such);
     while(wo != bis) {
         cout << "  " << wo->plz_ << '\n';
         ++wo;
     }
 }


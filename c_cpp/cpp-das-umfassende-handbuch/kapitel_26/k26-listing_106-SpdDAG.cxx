#include <vector>
#include <iostream>
#include <string>
using std::ostream; using std::cout; using std::vector;
struct Side { std::string which_; };
ostream& operator<<(ostream&os, const Side&s)
  { os << s.which_; return os; }
ostream& operator<<(ostream&os, const vector<int>&data)
  { for(auto &e : data) os << e << ' '; return os; }
int main() {
  vector<Side> sides{ Side{"dark"}, Side{"light"} };
  vector<Side>::iterator it1 = sides.begin();
  cout << *it1 << '\n';  // Dereferenzierung mit *; Ausgabe: dark
  *it1 = Side{"bright"}; // * für iterator ist eine non-const-Referenz
  cout << *it1 << '\n';
  cout << it1->which_.substr(1, 3) << '\n'; // Dereferenzierung mit ->; Ausgabe: rig
  // statt den Iteratortyp auszuschreiben, sollten Sie auto verwenden:
  auto it2 = sides.begin();
  if(it1==it2) cout << "Beide am Anfang\n";
}


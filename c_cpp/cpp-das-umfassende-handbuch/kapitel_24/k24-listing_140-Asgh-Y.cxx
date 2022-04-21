#include <forward_list>
#include <iostream>
#include <iterator> // next
using std::cout; using std::forward_list; using std::ostream;
ostream& operator<<=(ostream&os, const forward_list<int> &data)
    { for(auto &e:data) os<<e<<' '; return os<<'\n'; }
int main()     {
    forward_list<int> zahlen {40, 50, 60, 70};
    cout <<= zahlen; // Ausgabe: 40 50 60 70
    zahlen.insert_after(zahlen.before_begin(), {10, 20, 30});
    cout <<= zahlen; // Ausgabe: 10 20 30 40 50 60 70
    auto wo = std::next(zahlen.begin(), 2); // zwei Elemente weiter
    auto bis = std::next(wo, 3); // drei Elemente nach wo
    zahlen.erase_after(wo, bis);
    cout <<= zahlen; // Ausgabe: 10 20 30 60 70
}


#include <forward_list>
#include <iostream>
using std::cout; using std::forward_list; using std::ostream;
ostream& operator<<=(ostream&os, const forward_list<int> &data)
  { for(auto &e:data) os<<e<<' '; return os<<'\n'; }
int main() {
  {
    forward_list<int> fw1 {10, 20, 30, 40};
    forward_list<int> fw2 {5, 6, 7, 8};
    fw1.splice_after(fw1.begin(), fw2);                       // transferiert alles
    cout <<= fw1;                 // Ausgabe: 10 5 6 7 8 20 30 40
    cout <<= fw2;                 // Ausgabe:
  }
  {
    forward_list<int> fw1 {10, 20, 30, 40};
    forward_list<int> fw2 {5, 6, 7, 8};
    fw1.splice_after(fw1.begin(), fw2,fw2.begin(),fw2.end()); // ein Element übrig
    cout <<= fw1;                 // Ausgabe: 10 6 7 8 20 30 40
    cout <<= fw2;                 // Ausgabe: 5
  }
}


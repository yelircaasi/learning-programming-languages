#include <iostream>
#include <ratio>
using std::cout; using std::endl;
int main() {
  using einDrittel = std::ratio<1,3>;
  using zweiViertel = std::ratio<2,4>;
  cout << einDrittel::num << "/" << einDrittel::den << endl;   // Ausgabe: 1/3
  cout << zweiViertel::num << "/" << zweiViertel::den << endl; // Ausgabe: 1/2
  using sum = std::ratio_add<einDrittel,zweiViertel>;          // addieren
  cout << sum::num << "/" << sum::den;                         // Ausgabe: 5/6
}


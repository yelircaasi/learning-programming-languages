#include <iostream>
using std::cout; using std::endl;
class dendl { // Punkte gefolgt von Newline
    int dendl_;
public:
    dendl(int n=1)
      : dendl_{n} {}
    std::ostream& operator()(std::ostream& os) const { // Funktor
        for(int i=0; i<dendl_; ++i) os << '.';
        return os << '\n';
    }
};
std::ostream& operator<<( std::ostream& os, const dendl& elem) {
    return elem(os);
}
int main() {
    cout << "Text1" << dendl(4); // Ausgabe: Text1....
    cout << "Text2" << dendl(2); // Ausgabe: Text2..
    cout << "Text3" << dendl();  // Ausgabe: Text3.
}


#include <vector>
#include <string>
#include <algorithm> // sort
#include <iostream>  // cout
using std::string; using std::vector; using std::cout;
// wie zuvor
int main() {
    vector zwerge{    // wie zuvor
    /* sortieren */
    bool rueckwaerts = true; // oder false. Variable außerhalb des Lambdas
    std::sort(begin(zwerge), end(zwerge),
        [rueckwaerts](const Zwerg& a, const Zwerg& b) {
            if(rueckwaerts)
                return a.name_ > b.name_;
            else
                return a.name_ < b.name_;
        }
    );
    /* ausgeben */
    for(const auto& z : zwerge) // rückwärts: "Thorin" bis "Balin"
        cout << z.name_  << " ";
    cout << "\n";
}


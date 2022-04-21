#include <vector>
#include <string>
#include <algorithm> // sort
#include <iostream>  // cout
using std::string; using std::vector; using std::cout;
// wie zuvor
int main() {
    vector zwerge{           // wie zuvor

    /* sortieren */
    bool rueckwaerts = true; // oder false. Variable außerhalb des Lambdas
    unsigned richtigrum = 0; // zählt < mit
    unsigned falschrum = 0;  // zählt > mit
    std::sort(begin(zwerge), end(zwerge),
        [rueckwaerts,&falschrum,&richtigrum](const Zwerg& a, const Zwerg& b) {
            bool result = rueckwaerts
                ? a.name_ > b.name_
                : a.name_ < b.name_;
            if(result==false) ++falschrum; else ++richtigrum;
            return result;
        }
    );

    /* ausgeben */
    cout << "Falschrum:" << falschrum << " Richtigrum: " << richtigrum << "\n";
    for(const auto& z : zwerge) // rückwärts: "Thorin" bis "Balin"
        cout << z.name_  << " ";
    cout << "\n";
}


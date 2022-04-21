#include <iostream>
#include <string>
#include <vector>
#include <utility> // pair
using std::pair; using std::cout; using std::cin; using std::string;
std::vector<string> monate { "Jan", "Feb", "Mar" };
std::vector temps { 8, 12, 11 };
std::pair<string, int> monatMitTemp(size_t m) {
    auto monat = monate.at(m);
    auto temperatur = temps.at(m);
    return std::make_pair(monat, temperatur);
}
int main() {
    std::pair daten = monatMitTemp(1);
    cout << "Monat : " << daten.first << std::endl; // Ausgabe: Monat : Feb
    cout << "Temperatur : " << daten.second << std::endl; // Ausgabe: Temperatur : 12
}


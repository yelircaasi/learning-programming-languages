#include <cstdlib> // EXIT_SUCCESS
#include <iostream> // cout
#include <vector>
#include <string>
#include "qwort/qwort.hpp"

using std::cout;
using std::vector; using std::string;

int main(int argc, const char* argv[]) {
    cout << "qwort version " << qw::version() << "\n";
    // Index bauen
    qw::index myindex{};
    // - demodaten
    myindex.add("Deutschland");
    myindex.add("Griechenland");
    // Abfragen erzeugen
    vector<string> args(argv+1, argv+argc); // interatorbasierte initialisierung
    for(auto &querystring : args) {
        cout << "Suche '" << querystring << "'... ";
        const auto match = myindex.getBestMatch(querystring);
        cout << match << "\n";
    }
    return EXIT_SUCCESS;
}

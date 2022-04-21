#include <regex>
#include <string>
#include <iostream>
using std::regex; using std::regex_search; using std::cmatch;
int main() {
    cmatch res;                              // für Detailergebnisse
    std::string text = "<h2>Ergebnis und Teile davon</h2>";
    regex muster{"<h(.)>([^<]+)"};           // Suchmuster mit Gruppen
    regex_search(text.c_str(), res, muster); // Details nach res
    std::cout << res[1] << ". "                   // ()-Gruppe 1: H-Ebene
         << res[2] << std::endl;                  // ()-Gruppe 2: H-Text
}


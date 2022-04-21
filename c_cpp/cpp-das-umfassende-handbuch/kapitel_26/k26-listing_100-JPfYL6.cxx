#include <vector>
#include <iostream>
#include <algorithm>
using std::vector; using std::ostream; using std::cout;
int main() {
    vector<int> data{};
    data.reserve(400);                    // Platz für 400 Elemente
    // Phase 1: befüllen
    for(int idx = 1; idx <= 20; ++idx) {
        for(int val = 0; val < 20; ++val) {
            data.push_back(val % idx);    // irgendwas zwischen 0 und 19
        }
    }
    cout << data.size() << '\n';          // 400 Elemente zwischen 0 und 19
    // Nachbereitung Phase 1: set-Äquivalent erstellen
    std::sort(data.begin(), data.end());  // Vorbereitung für unique
    auto wo = std::unique(data.begin(), data.end()); // doppelte ans Ende
    data.erase(wo, data.end());           // doppelte wegräumen
    data.shrink_to_fit();
    cout << data.size() << '\n';          // nur noch 20 Elemente
    // Phase 2: benutzen
    for(auto &e:data)
        cout << e << ' ';                 // Ausgabe: 0 1 2 .. 18 19
    cout << '\n';
    auto it = std::lower_bound(data.begin(), data.end(), 16); // suche Wert
    if(it!=data.end() && *it == 16)
        cout << "gefunden!\n";
    if(std::binary_search(data.begin(), data.end(), 7))       // ja oder nein
        cout << "auch gefunden!\n";
}


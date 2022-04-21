#include <vector>
#include <iostream>
#include <algorithm>                // sort
using std::vector; using std::cout;

double median(vector<int> daten) {  // kopiert
    std::sort(daten.begin(), daten.end());
    auto it = daten.begin();
    auto sz = daten.size();
    if(sz==0) return 0;             // Sonderfall

    // Median ermitteln:
    auto m = (it+sz/2);             // ungefähr die Mitte
    if(sz%2 != 0) {                 // ungerade Anzahl Elemente
        return *m;
    } else {                        // gerade Anzahl Elemente
        return double(*m + *(m-1)) / 2;
    }
}

int main() {
    vector daten1 { 12, 22, 34, 10, 1, 99, 33 };
    cout << median(daten1) << '\n'; // 22

    vector daten2 { 30, 2, 80, 99, 31, 3 };
    cout << median(daten2) << '\n'; // 30.5
}


#include <numeric> // adjacent_difference
#include <functional> // plus
#include <algorithm> // copy
#include <iostream>
#include <iterator> // ostream_iterator
#include <vector>
using std::cout; using std::vector;
int main() {
    // Streamausgabeiterator für int;
    std::ostream_iterator<int> os{std::cout, " "};
    vector data{ 1, -1, 2, -2, -4, 4, -6, 6 };
    std::copy(data.begin(), data.end (), os);
    cout << '\n'; // Ausgabe: 1 -1 2 -2 -4 4 -6 6
    vector<int> res( data.size()-1 ); // Platz für Ergebnis
    // Ergebnisse nach res schreiben:
    adjacent_difference(data.begin(), data.end(), res.begin());
    std::copy (res.begin(), res.end (), os);
    cout << '\n'; // Ausgabe: 1 -2 3 -4 -2 8 -10
    // gleich nach os schreiben:
    adjacent_difference(data.begin(), data.end(), os, std::plus<int>{});
    cout << '\n'; // Ausgabe: 1 0 1 0 -6 0 -2 0
}


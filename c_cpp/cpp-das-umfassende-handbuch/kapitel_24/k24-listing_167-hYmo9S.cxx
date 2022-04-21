#include <vector>
// ...
multiset msinit{1,2,2,3,1};                   // sortiert bei Initialisierung
cout <<= msinit; // Ausgabe: 1 1 2 2 3
std::vector in{ 7,7,7,7,7,7,7 };
std::set srange( in.begin(), in.end() );      // set entfernt doppelte
cout << srange.size() << ": " << *srange.begin() << '\n'; // Ausgabe: 1: 7

multiset msrange( in.begin(), in.end() );      // multiset erhält doppelte
cout <<= msrange; // Ausgabe: 7 7 7 7 7 7 7


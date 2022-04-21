unordered_set<int> data;
auto res1 = data.insert( 5 );                  // einfügen per Kopie
if(res1.second) cout << "ja, 5 nun drin\n";    // das klappt
auto res2 = data.emplace( 5 );                 // einfügen vor Ort
if(res2.second) cout << "zweite 5 nun drin\n"; // das klappt nicht
auto res3 = data.insert(res1.first, 6 );       // mit Positionshinweis
// res3 ist nur ein iterator ohne bool
cout << *res3 << '\n';                         // auf jeden Fall eine 6


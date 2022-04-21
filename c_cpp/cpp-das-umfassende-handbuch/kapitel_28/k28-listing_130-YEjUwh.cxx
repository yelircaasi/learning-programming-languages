#include <chrono>
#include <iostream>
using namespace std::chrono; using std::cout;
using seconds32 = duration<int32_t>;            // andere Repräsentation
using week = duration<int,std::ratio<86400*7>>; // andere Zeiteinheit
using fseconds = duration<double>;              // Fließkommarepräsentation
int main() {
  seconds32 s{5};
  cout << milliseconds(s).count() << "ms\n";
  week w{1};
  hours h = w; // Umwandlung kostenlos
  cout << "1 Woche hat "<<h.count()<<" Stunden\n";                // ...168...
  fseconds fs{23.75};
  cout << fs.count() << "s\n"; // Fließkommaausgabe
  auto printDur = [](fseconds f) { cout << f.count() << "s\n"; }; // Funktion
  printDur(45ms + 63us); // Umwandlung in fseconds
  // Ausgabe: 0.045063s
}


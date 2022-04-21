#include <vector>
#include <iostream>
#include <cstdio> // fopen, fclose, fwrite, fread, remove
using namespace std;
ostream& operator<<(ostream&os, const vector<int>&data) {
    for(auto &e : data) os << e << ' '; return os;
}
static const char* FILENAME = "nums.dat";

int main() {
  const vector nums{10,11,22,34};
  { // Schreiben
    auto out = fopen(FILENAME, "wb"); // Datei mit C zum Schreiben öffnen
    if(out==nullptr) {
        cerr << "Fehler beim Oeffnen\n"; return -1;
    }

    auto ok = fwrite(nums.data(), sizeof(int), nums.size(), out);
    if(ok!=nums.size()) {
        cerr << "Fehler beim Schreiben\n"; return -1;
    }
    fclose(out); // In C muss man explizit schließen. Ehrlich.
  }

  vector<int> gelesen{};
  { // Lesen
    auto in = fopen(FILENAME, "rb"); // Datei mit C zum Lesen öffnen
    if(in==nullptr) {
        cerr << "Fehler beim Oeffnen\n"; return -1;
    }
    const size_t sz = 4; // angenommen, wir wissen, wir lesen 4 Elemente ...
    gelesen.resize(sz); // Platz schaffen für zu lesende Daten
    auto ok = fread(gelesen.data(), sizeof(int), sz, in);
    if(ok!=sz) {
        cerr << "Fehler beim Lesen\n"; return -1;
    }
    fclose(in);
  }

  { // Vergleichen
    cout << nums << '\n';    // 10 11 22 34
    cout << gelesen << '\n'; // 10 11 22 34
  }

  if(remove(FILENAME) == -1) {
      cerr << "Warning: Fehler beim Loeschen\n";
  }
}


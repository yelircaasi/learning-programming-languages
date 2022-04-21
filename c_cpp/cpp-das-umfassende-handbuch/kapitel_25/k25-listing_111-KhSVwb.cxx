#include <numeric> // accumulate
#include <functional> // multiplies
#include <algorithm> // transform
#include <iostream>
#include <vector>
using std::accumulate; using std::cout; using std::vector; using std::multiplies;
int main() {
  vector data{ 2, 3, 5, 10, 20 };
  cout << accumulate(data.begin(),data.end(),0)<<'\n'; // +, Ausgabe: 40
  cout << accumulate(data.begin(),data.end(),1,multiplies<int>{})<<'\n'; // *, 6000
  vector<bool> gerade( data.size() );
  std::transform( data.begin(), data.end(), gerade.begin(),
      [](auto n) { return n%2==0; });
  for(auto b : gerade) {
      cout << ( b ? "gerade " : "ungerade ");
  }
  cout << "\n";       // Ausgabe: gerade ungerade ungerade gerade gerade
  auto sindAlleGerade = accumulate(gerade.begin(), gerade.end(), true,
          [](auto b, auto c) { return b&&c; });
  if(sindAlleGerade) {
      cout << "alles gerade Zahlen\n";
  } else {
      cout << "ungerade Zahlen dabei\n"; // das ist die Ausgabe
  }
}


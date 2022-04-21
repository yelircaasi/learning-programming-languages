#include <map>
#include <memory> // unique_ptr
#include <string>
#include <iostream>
#include <chrono> // Zeitmessung
using std::map; using std::cout; using std::endl; using namespace std::chrono;

struct Node {
  std::unique_ptr<int> d_;
  Node() : Node{0}  { }
  explicit Node(int d) : d_{ new int } { *d_ = d; } // auch etwas Speicher
  friend bool operator<(const Node& a, const Node& b) { return *a.d_<*b.d_; }
  friend bool operator==(const Node& a, const Node& b) { return *a.d_==*b.d_; }
};
long long millisSeit(steady_clock::time_point start) { // Helfer zur Zeitmessung
  return duration_cast<milliseconds>(steady_clock::now()-start).count();
}
int main() {
  std::unique_ptr<map<int,Node>> riesig{ new map<int,Node>{} };
  cout << "Aufbau..." << endl;
  steady_clock::time_point start = steady_clock::now();
  for(int idx=0; idx < 100*1000*1000; ++idx) {   // massive Menge in der map
      (*riesig)[idx] = Node{idx};
  }
  cout << "Fertig: " << millisSeit(start) << " ms" << endl; // Zeitmessung hier
  start = steady_clock::now();
  riesig.reset();                                           // wegräumen hier
  cout << "Ende: " << millisSeit(start) << " ms" << endl;   // Zeitmessung hier
}


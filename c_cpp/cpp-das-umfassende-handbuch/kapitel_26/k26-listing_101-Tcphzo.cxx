#include <algorithm> // copy
#include <iterator>  // ostream_iterator
#include <vector>
int main() {
  std::vector<char> pfad{};
  for (char ch = 'a'; ch <= 'z'; ++ch) {
    pfad.push_back(ch);
  }
  std::copy(pfad.begin(), pfad.end(), // von ... bis
    std::ostream_iterator<char>(std::cout, " ") // kopiere nach cout, Separator " "
  );
}


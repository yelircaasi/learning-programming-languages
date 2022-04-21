#include <iostream>
#include <array>
#include <vector>
#include <string>
using std::array; using std::move; using std::forward;

// == array vergrößern ==
template<typename T, size_t S, std::size_t... Idx>
constexpr array<T, S+1>
help_append(array<T, S>&& data, T&& elem, std::index_sequence<Idx...>) {
  return { std::get<Idx>(forward<array<T, S>>(data))..., forward<T>(elem) };
}

template<typename T, size_t S>
constexpr auto
append(array<T, S> data, T elem) {
  return help_append(move(data), move(elem),
                  std::make_index_sequence<S>{});
}
// == Beispiel ==
class Picture { // Nullerregel; verschiebbar
  std::vector<char> data_; // viele Daten
  std::string name_;
public:
  explicit Picture(const std::string& name) : data_(1000,0), name_{name}
    { /* ... hier Bild laden ... */ }
  auto name() const { return name_; }
};
int main() {
  // vorher
  array pics{Picture{"Mona"}, Picture{"Schrei"}, Picture{"Vincent"}};
  std::cout << pics[0].name() << '\n'; // Ausgabe: Mona
  // vergrößern
  Picture neu { "Uhren" };
  auto mehr = append(move(pics), move(neu));
  // nachher
  std::cout << pics[0].name() << '\n'; // Ausgabe:
  std::cout << mehr[0].name() << '\n'; // Ausgabe: Mona
  std::cout << mehr[3].name() << '\n'; // Ausgabe: Uhren
}


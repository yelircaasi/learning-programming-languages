// ...hier Inhalt von <vector>...
//... hier Inhalt von <iostream>...
using container_type = std::vector<int>;
static constexpr unsigned SIZE = 10;

int main() {
  { (std::cout) << "Programmstart" << "\n"; }
  container_type data(SIZE);
  { (std::cout) << "Der Container hat " << data.size() << " Elemente." << "\n";}
  { (std::cout) << "Programmende" << "\n"; }
  { std::cout << "Das ging ja noch mal gut.\n"; }
}


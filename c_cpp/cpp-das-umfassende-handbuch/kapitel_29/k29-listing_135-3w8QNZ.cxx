#include <future> // async
#include <iostream>

int berechneHoehe(int count, int maxCount, int scale) {
  if(maxCount == 0)
      throw std::logic_error("maxCount ist 0");
  return (count * scale) / maxCount;
}

int main() {
  auto fut = std::async(std::launch::async, berechneHoehe, 0, 0, 200);
  try {
    std::cout << fut.get() << '\n';               // löst Exception aus
  } catch(std::exception &ex) {
    std::cout << "Fehler: " << ex.what() << '\n'; // Ausgabe: Fehler: maxCount ist 0
  }
}


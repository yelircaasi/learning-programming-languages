#include <iostream>
#include <system_error> // std::make_error_condition, std::ios_errc

int main () {
  // umschalten auf Exceptions:
  std::cin.exceptions (std::ios::failbit|std::ios::badbit);

  try {
    std::cin.rdbuf(nullptr);       // löst eine Exception aus
  } catch (std::ios::failure& e) { // abgeleitet von system_error
    std::cerr << "Fehler: ";
    if (e.code() == std::make_error_condition(std::io_errc::stream)) {
      std::cerr << "stream\n";
    } else {
      std::cerr << "andere\n";
    }
  }
}


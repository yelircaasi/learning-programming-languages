#include <future>
#include <thread>
#include <iostream>
#include <exception>
int ack(int m, int n); // Ackermannfunktion
void langeBerechnung(std::promise<int> intPromise) {
  try {
    int result = ack(3,12);
    intPromise.set_value(result);                    // Ergebnis mitteilen
  } catch (std::exception &e) {
    intPromise.set_exception(make_exception_ptr(e)); // Exception mitteilen
  } catch ( ... ) {
    intPromise.set_exception(std::current_exception());   // Exc. ohne Namen
  }
}
int main () {
  std::promise<int> intPromise;                           // Promise erzeugen
  std::future<int> intFuture = intPromise.get_future();   // Future anfordern
  std::thread th{ langeBerechnung,                        // starten
             std::move(intPromise) };                     // Promise übergeben
  th.detach();                                       // weiterlaufen lassen
  // könnte eine Exception werfen:
  int result = intFuture.get();                      // Ergebnis anfordern
  std::cout << result << std::endl;
}


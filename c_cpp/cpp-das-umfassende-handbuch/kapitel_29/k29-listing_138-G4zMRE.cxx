#include <future>
#include <thread>
#include <iostream>
int ack(int m, int n); // Ackermannfunktion
int main () {
  std::packaged_task<int(int,int)> task2 { &ack }; // andere Signatur
  auto f2 = task2.get_future();
  std::thread th2 { move(task2), 3, 12 };          // Parameter hier
  std::cout << "  ack(3,12):" << f2.get() << '\n'; // Ausgabe: ack(3,12):32765
  th2.join();
}


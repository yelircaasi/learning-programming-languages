#include <chrono>
void sleep(std::chrono::seconds s) { // nimmt Sekunden als Dauer
    /* ... */
}
/* ... */
int main() {
    using namespace std::chrono; // Literale verfügbar machen
    sleep(10min);   // 10 Minuten warten, also 600 Sekunden
    sleep(10ms);    // 10 Millisekunden? Mit Sekunden nicht abzubilden.
}


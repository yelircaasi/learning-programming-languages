#include <chrono>
#include <iostream>
int main() {
    using namespace std::chrono;             // Suffixe erlauben
    seconds mySecs = 121s;                   // seconds{121}
    std::cout << mySecs.count() << "s\n";    // Ausgabe: 121s
    milliseconds myMillis = mySecs;          // automatisch umgewandelt
    std::cout << myMillis.count() << "ms\n"; // Ausgabe: 121000ms
    nanoseconds myNanos = mySecs;
    std::cout << myNanos.count() << "ns\n";  // Ausgabe: 121000000000ns
    minutes myMinutesErr = mySecs;           // Fehler: Konvertierung mit Verlust
    minutes myMinutes = duration_cast<minutes>(mySecs); // explizit gehts
    std::cout<<myMinutes.count()<<"min\n";   // Ausgabe: 2min
}


#include <thread>
#include <mutex>
#include <vector>
#include <numeric> // accumulate, iota
using std::mutex; using std::unique_lock;

std::vector<int> myData;             // geteilte Daten
mutex myMutex;                       // Mutex zu den Daten
unique_lock<mutex> bereiteDatenVor() {
    unique_lock lk1{myMutex};        // sperren
    myData.resize(1000);
    std::iota(myData.begin(), myData.end(), 1); // 1..1000
    return lk1;                                 // Sperre transferieren
}
int verarbeiteDaten() {
    unique_lock lk2 = bereiteDatenVor();        // Sperre transferiert
    return std::accumulate(myData.begin(), myData.end(), 0);
}


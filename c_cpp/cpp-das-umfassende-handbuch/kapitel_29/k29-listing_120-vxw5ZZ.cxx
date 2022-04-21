#include <vector>
#include <thread>
#include <mutex>
#include <iostream>
#include <numeric>  // iota

/* T: noexcept kopier- und zuweisbar */
template<typename T>
class MxStack {
    std::vector<T> data_;
    std::mutex mx_;

public:
    MxStack() : data_{} {}

    bool isEmpty() const { return data_.empty(); }

    void push(const T& val) {
        std::lock_guard<std::mutex> g{mx_};
        data_.push_back(val);
    }

    T pop() {
        std::lock_guard g{mx_};
        if(data_.empty())
            throw std::length_error{"empty stack"};
        T tmp{std::move(data_.back())};
        data_.pop_back();
        return tmp;
    }
};

int main() {
    // Stack vorbereiten
    MxStack<int> mxs{};
    for(int i=1; i<=1'000'000; ++i) mxs.push(i);
    // Berechnung definieren
    auto sumIt = [&mxs](long &sum) {
        int val{};
        try {
            while( ! mxs.isEmpty()) {
                sum += mxs.pop(); // könnte immer noch werfen
            }
        } catch(std::length_error &ex) {}
    };
    // Berechnen
    long sum1 = 0;          // fürs Teilergebnis
    std::thread th1{sumIt, std::ref(sum1)};
    long sum2 = 0;          // fürs Teilergebnis
    std::thread th2{sumIt, std::ref(sum2)};
    th1.join(); th2.join();
    long sum = sum1 + sum2; // Gesamtergebnis
    // Ergebnis
    std::cout << "Sollergebnis: "
        << (1'000'000L*1'000'001)/2 << '\n'; // Ausgabe: 500000500000
    std::cout << "Tatsaechlich: "
        << sum << '\n';                      // Ausgabe: 500000500000
}


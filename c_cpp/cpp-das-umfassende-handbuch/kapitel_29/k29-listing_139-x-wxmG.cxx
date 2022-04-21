#include <iostream>
#include <atomic>

struct CArray { int a[100]; };
struct Einfach { int x, y; };

int main() {
    std::atomic<CArray> carray{};
    std::cout << (carray.is_lock_free() ? "sperrfrei" : "sperrt")
        << '\n';                                        // Ausgabe: sperrt
    std::atomic<Einfach> einfach{};
    std::cout << (einfach.is_lock_free() ? "sperrfrei" : "sperrt")
        << '\n';                                        // Ausgabe: sperrfrei
}


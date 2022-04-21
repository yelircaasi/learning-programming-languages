class thread_guard {
    std::thread &th_;
public:
    explicit thread_guard(std::thread &th) : th_{th} {}
    ~thread_guard() {
        if(th_.joinable()) th_.join();      // wartet bei okay und Fehler
    }
    thread_guard(const thread_guard&) = delete; // keine Kopie
    thread_guard& operator=(const thread_guard&) = delete; // keine Zuweisung
};
long fib(long n) { return n<=1 ? n : fib(n-1)+fib(n-2); }
void aufgabe1() { auto r = fib(40); cout << "fib(40)=" << r << endl; }

void hauptprogramm() {
    try {
        std::thread th{ &aufgabe1 };
        thread_guard tg{ th };             // wacht über th
        std::vector data{ 0,1,2 };
        data.at(666);                      // löst out_of_range aus
    } catch(std::runtime_error &ex) {      // passt nicht auf out_of_range
         /* ... */   // speziellen Fehler hier behandeln
    }
}
// main() wie zuvor


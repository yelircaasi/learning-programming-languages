#include <iostream>

// Produktionscode:
struct DatabaseInterface {
    virtual int getData() const = 0;
};
struct RealDatabase : public DatabaseInterface {
    int getData() const override { return 999; }
};
struct Programm {
    DatabaseInterface &db_;
    void run() {
        std:: cout << db_.getData() << "\n";
    }
};

// main als Test:
int main() {
    RealDatabase db;
    Programm prog { db }; // echte DB wird  mitgetestet
    prog.run();  // Erwartete Ausgabe: 999
}


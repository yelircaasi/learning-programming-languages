#include <iostream>
// Produktionscode:
struct DatabaseInterface {
    virtual int getData() const = 0;
};
struct Programm {
    DatabaseInterface &db_;
    void run() {
        std:: cout << db_.getData() << "\n";
    }
};
// Testhelfer:
struct MockDatabase : public DatabaseInterface {
    int getData() const override { return 5; }
};
// main als Test:
int main() {
    MockDatabase mockDb;
    Programm prog { mockDb }; // echte DB wird nicht mitgetestet
    prog.run();  // Erwartete Ausgabe: 5
}


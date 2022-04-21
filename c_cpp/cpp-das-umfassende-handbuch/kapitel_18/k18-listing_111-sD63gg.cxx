#include <iostream>           // cout
#include <memory>             // unique_ptr
using std::cout;

class Driver {                // abstrakte Basisklasse
public:
    virtual void init() = 0;
    virtual void done() = 0;
    virtual void send(const std::string &data) = 0;
};
class ProductionDriver : public Driver {
public:
    void init() override { }
    void done() override { }
    void send(const std::string &data) override { cout << data << "\n"; }
};
class DebuggingDriver : public Driver {
   size_t countSend_ = 0;
public:
    void init() override {
        countSend_= 0; cout << "Ok, bin initialisiert.\n";
    }
    void done() override {
        cout << "send benutzt:" << countSend_ << " mal\n";
    }
    void send(const std::string &data) override {
        cout << "send("<<countSend_<<"):"<< data << "\n";
        ++countSend_;
    }
};
struct DriverWrapper {        // RAII-Wrapper für init() und done()
    Driver &driver_;
    explicit DriverWrapper(Driver& driver) : driver_(driver) { driver_.init(); }
    ~DriverWrapper() { driver_.done(); }
    DriverWrapper(const DriverWrapper&) = delete; // nicht kopieren
};

void doWork(Driver &driver) { // jemand, der flexibel einen beliebigen Driver nutzt
    DriverWrapper wrapper(driver);      // init() und done() aufrufen
    driver.send("Eine unerwartete Reise");
    driver.send("Smaugs Einoede");
}

int main() {
    // gleiche doWork, einmal mit Produktions- und einmal mit Debugging-Treiber
    ProductionDriver production{};
    doWork( production );
    DebuggingDriver debugging{};
    doWork( debugging );

    // üblichere Variante eines dynamisch erzeugten Treibers
    std::unique_ptr<Driver> driver{ new ProductionDriver{} };
    doWork( *driver );
}


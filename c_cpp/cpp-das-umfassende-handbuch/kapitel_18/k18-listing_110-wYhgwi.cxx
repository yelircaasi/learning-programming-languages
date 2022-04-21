#include <iostream>
using std::cout;

struct KeyboardDriver : public Driver {
    void init() override { cout << "Init Keyboard\n"; }
    void done() override { cout << "Done Keyboard\n"; }
    bool send(const char* data, unsigned int len) override {
        cout << "sending " << len << " bytes\n";
        return true;
    }
};

struct Computer {
    Driver &driver_;
    explicit Computer(Driver &driver) : driver_{driver} {
        driver_.init();
    }
    void run() {
        driver_.send("Hello", 5);
    }
    ~Computer() {
        driver_.done();
    }
    Computer(const Computer&) = delete;
};

int main() {
    KeyboardDriver keyboard {};
    Computer computer(keyboard); // Ausgabe: Init Keyboard
    computer.run();              // Ausgabe: sending 5 bytes
}                                // Ausgabe: Done Keyboard


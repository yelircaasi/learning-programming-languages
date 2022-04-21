#include <iostream>
#include <vector>
using std::cout;

// == Beobachter-Entwurfsmuster ==
struct Observer {
    virtual void update() = 0;
};
class Subject {
    std::vector<Observer*> observers_; // not owning pointers
protected:
    void notify() {
        for (auto o : observers_)
            o->update();
    }
public:
    void addObserver(Observer* o) {
        observers_.push_back(o);
    }
};

// == konkrete Klasse ==
struct MyThing {
    int calc() { return 1+1; }
};
// == zusammenbringen ==
struct MyObservableThing : public MyThing, public Subject {
    int calc() {
        notify();
        return MyThing::calc();
    }
};
// == etwas beobachten ==
struct MyObserver : public Observer {
    void update() override {
        cout << "observed\n";
    }
};
int main() {
    MyObserver myObserver{};
    MyObservableThing myObservableThing{};
    myObservableThing.addObserver(&myObserver);
    auto result = myObservableThing.calc(); // Ausgabe: observed
}


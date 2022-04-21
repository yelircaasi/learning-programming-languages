#include <string>
using std::string;
class Widget {
    string name_ = "";
public:
    void setName(string newName) {
        name_ = newName;
    }
    const string& getName() const {    // const&-Rückgabe
        return name_;
    }
};
int main() {
    Widget w{};
    w.setName("Titel");
    string name1 = w.getName();        // neuer String, also Kopie
    name1.clear();                     // die Kopie dürfen Sie wieder verändern
    const string& name2 = w.getName(); // const-Referenz auf inneren string name_
    /* name2.clear(); */               // name2 ist const, geht also nicht
    string& name3 = w.getName(); // geht nicht, Funktion gibt const& zurück, nicht &
    auto name4 = w.getName();          // identisch mit name1
    const auto& name5 = w.getName();   // identisch mit name2
}


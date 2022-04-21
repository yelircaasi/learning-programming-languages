#include <memory>                        // unique_ptr
#include <string>
#include <iostream>
using std::unique_ptr; using std::string;
class Component { };                     // Dummy-Fensterhierarchie
class Label : public Component { };
class Textfield : public Component { };
class Button : public Component {
public:
    int id_; // ID zur Unterscheidung der Buttons
    explicit Button(int id) : id_{id} {}
};
class Window { };
class MyDialog : public Window {
    string title_;
    unique_ptr<Label> lblVorname_{new Label{}};         // lauter Datenfelder
    unique_ptr<Textfield> txtVorname_{new Textfield{}}; // ... an die Lebensdauer
    unique_ptr<Label> lblNachname_{new Label{}};        // ... der Klasse gebunden
    unique_ptr<Textfield> txtNachname_{new Textfield{}};
    unique_ptr<Button> btnOk_{new Button{1}};
    unique_ptr<Button> btnAbbrechen_{new Button{2}};
public:
    explicit MyDialog(const string& title) : title_{title} {}
    unique_ptr<Button> showModal()
        { return std::move(btnOk_); }    // Platzhalter-Code; OK gedrückt
};
unique_ptr<MyDialog> createDialog() {
    return unique_ptr<MyDialog>{ // temporärer Wert
        new MyDialog{"Bitte Namen eingeben"}};
}
int showDialog() {
    unique_ptr<MyDialog> dialog = createDialog();       // lokale Variable
    unique_ptr<Button> gedrueckt = dialog->showModal(); // Rückgabewert
    return gedrueckt->id_;
}
int main() {
    int gedrueckt_id = showDialog();
    if(gedrueckt_id == 1) {
        std::cout << "Danke, dass Sie OK gedrueckt haben\n";
    }
}


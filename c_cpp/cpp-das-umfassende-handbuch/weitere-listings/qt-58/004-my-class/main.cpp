// 004-my-class/main.cpp
#include "my_class.hpp"
#include <QApplication>
#include <QMessageBox>
#include <sstream>

// Eine einfache Nachrichtenbox
void show(MyClass& a, MyClass& b, const char* title) {
    std::stringstream ss;
    ss << title << "\na: " << a.value()
       << "\nb: " << b.value();
    QMessageBox::information(0, "MyClass Information",
        QString::fromStdString(ss.str()), QMessageBox::Ok);
}

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    // Zwei MyClass-Objekte
    MyClass a{};
    MyClass b{};
    // Das Signal des einen wird mit dem Slot
    // des anderen Objekts verbunden.
    QObject::connect(
        &a, &MyClass::valueChanged,
        &b, &MyClass::setValue );
    // b.val bekommt den Wert 100
    b.setValue( 100 );
    show(a, b, "b->setValue(100)");
    // a.val bekommt den Wert 99. Durch die Signal-Slot
    // Verknüpfung bekommt jetzt auch b.val den Wert 99
    a.setValue( 99 );
    // Der Beweis
    show(a, b, "a->setValue(99)");
    return app.exec();
}


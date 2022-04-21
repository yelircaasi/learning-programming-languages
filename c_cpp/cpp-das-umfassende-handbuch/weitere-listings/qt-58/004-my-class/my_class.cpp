// 004-my-class/my_class.cpp
#include "my_class.hpp"

// kapitel17/signalslot1/myclass.cpp
#include "my_class.hpp"
void MyClass::setValue(int newVal ) {
    // val wird nur neu gesetzt,
    // wenn tatsächlich ein anderer Wert übergeben wird.
    if (val_ != newVal) {
        val_ = newVal;
        emit valueChanged(val_);
    }
}

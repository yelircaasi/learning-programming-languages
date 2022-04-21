// 006-my-button/my_button.cpp
#include "my_button.hpp"
MyButton::MyButton(const QString& text, int id, QWidget* parent)
    : QPushButton{text, parent}, id_(id) {
    connect(this, SIGNAL(clicked()), this, SLOT(click()));
}
MyButton::MyButton(const QString& text, QWidget* parent)
    : MyButton{text, nextId_++, parent} {
}
void MyButton::click() {
    emit clicked(id_);
}
int MyButton::nextId_ = 0;

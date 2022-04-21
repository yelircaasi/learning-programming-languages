// 006-my-button//my_window.cpp
#include "my_window.hpp"
#include "my_button.hpp"
#include <QtCore>
#include <QtGui>

MyWindow::MyWindow(QWidget* parent)
: QWidget{parent}
, myButton_{new MyButton{tr("Drück mich"), this},
    new MyButton{tr("Mich auch"), this},
    new MyButton{tr("Und mich"), this} }
{
    QVBoxLayout* layout = new QVBoxLayout{this};
    for(auto w : myButton_) {
        layout->addWidget(w);
        connect(w, &MyButton::clicked, this, &MyWindow::myMessageBox);
    }
}
void MyWindow::myMessageBox(int id) {
    QMessageBox::information(this, tr("Ein Button wurde betätigt"),
        tr("Button ID: %1").arg(id), QMessageBox::Ok);
}

// 005-my-window/my_window.cpp
#include "my_window.hpp"
#include <QApplication>
#include <memory>
MyWindow::MyWindow(QWidget *parent)
: QWidget{parent}
, label_{new QLabel{"alter Text", this}}
, button0_{new QPushButton{"Label aktualisieren", this}}
, button1_{new QPushButton{"Beenden", this}}
, layout_{new QVBoxLayout{this}}
{
    layout_->addWidget(button0_);
    layout_->addWidget(button1_);
    layout_->addWidget(label_);
    setLayout(layout_);
    connect(button0_, &QPushButton::clicked, this, &MyWindow::setText);
    connect(button1_, &QPushButton::clicked, qApp, &QApplication::quit);
}
void MyWindow::setText() {
    label_->setText(tr("Label aktualisiert %1-mal").arg(++cnt_));
}

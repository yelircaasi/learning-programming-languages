// 012-dialog/mydialog.cpp
#include "mydialog.hpp"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
// Neue Dialog-Klasse von QDialog ableiten
MyDialog::MyDialog(QWidget *parent)
    : QDialog{parent}
{
    setFixedSize(150, 100);
    auto vbox = new QVBoxLayout{this};
    auto *label = new QLabel{"Ok oder Abbrechen?", this};
    auto *button01 = new QPushButton{"Ok", this};
    auto *button02 = new QPushButton{"Abbrechen", this};
    button02->setDefault(true);
    vbox->addWidget(label);
    vbox->addWidget(button01);
    vbox->addWidget(button02);
    setLayout(vbox);
    connect(button01, &QPushButton::clicked, this, &MyDialog::accept);
    connect(button02, &QPushButton::clicked, this, &MyDialog::reject);
}

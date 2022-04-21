// 013-dialog/mydialog.cpp
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
    auto *bOk = new QPushButton{"Ok", this};
    auto *bAb = new QPushButton{"Abbrechen", this};
    auto *bIg = new QPushButton{"Ignorieren", this}; //+
    bAb->setDefault(true);
    vbox->addWidget(label);
    vbox->addWidget(bOk);
    vbox->addWidget(bAb);
    vbox->addWidget(bIg); //+
    setLayout(vbox);
    connect(bOk, &QPushButton::clicked, this, &MyDialog::accept);
    connect(bAb, &QPushButton::clicked, this, &MyDialog::reject);
    connect(bIg, &QPushButton::clicked, this, &MyDialog::mySetResult);
}

void MyDialog::mySetResult() {
    int result = 99;
    emit done(result);
}

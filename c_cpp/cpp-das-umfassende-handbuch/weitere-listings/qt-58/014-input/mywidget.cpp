// 014-input/mywidget.cpp
#include "mywidget.hpp"
#include <QApplication>
#include <QInputDialog> //+
#include <QString>

MyWidget::MyWidget(QWidget *parent)
    : QWidget{parent}
    , bGetText_{new QPushButton{"get Text",this}}
    , bGetDouble_{new QPushButton{"get Double",this}}
    , bGetInt_{new QPushButton{"get Int",this}}
    , bGetItem_{new QPushButton{"get Item",this}}
    , lResult_{new QLabel{this}}
    , layout_{new QVBoxLayout{this}}
{
    layout_->addWidget(bGetText_);
    layout_->addWidget(bGetDouble_);
    layout_->addWidget(bGetInt_);
    layout_->addWidget(bGetItem_);
    layout_->addWidget(lResult_);
    connect(bGetText_, &QPushButton::clicked, this, &MyWidget::myGetText);
    connect(bGetDouble_,&QPushButton::clicked, this, &MyWidget::myGetDouble);
    connect(bGetInt_,  &QPushButton::clicked, this, &MyWidget::myGetInt);
    connect(bGetItem_, &QPushButton::clicked, this, &MyWidget::myGetItem);
    setWindowTitle("Hauptfenster - Anwendung");
}

void MyWidget::myGetText() {
    bool ok = false;
    auto res = QInputDialog::getText(this, "Frage",
        "Was ist Ihr Name?", QLineEdit::Normal, "", &ok);
    if(ok) {
        lResult_->setText(tr("Antwort: %1").arg(res));
    }
}

void MyWidget::myGetDouble() {
    bool ok = false;
    auto res = QInputDialog::getDouble(this, "Frage",
        "Was ist Pi?", 0., -1000., +1000., 8, &ok);
    if(ok) {
        lResult_->setText(tr("Antwort: %1").arg(res));
    }
}

void MyWidget::myGetInt() {
    bool ok = false;
    auto res = QInputDialog::getInt(this, "Frage",
        "Was ist Ihr Alter?", 0, 0, 150, 1, &ok);
    if(ok) {
        lResult_->setText(tr("Antwort: %1").arg(res));
    }
}

void MyWidget::myGetItem() {
    bool ok = false;
    QStringList items{"rot", "schwarz", "0"};
    auto res = QInputDialog::getItem(this, "Frage",
        "Rien ne va plus!", items, 0, false, &ok);
    if(ok) {
        lResult_->setText(tr("Antwort: %1").arg(res));
    }
}

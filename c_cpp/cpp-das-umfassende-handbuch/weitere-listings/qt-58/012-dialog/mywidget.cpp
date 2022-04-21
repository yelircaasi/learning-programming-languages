// 012-dialog/mywidget.cpp
#include "mywidget.hpp"
#include "mydialog.hpp"
#include <QApplication>
// Neue Widget-Klasse von QWidget ableiten
MyWidget::MyWidget(QString lab, QWidget *parent)
    : QWidget{parent}
    , button0_{new QPushButton{"Dialog starten",this}}
    , label1_{new QLabel(lab, this)}
    , label2_{new QLabel{this}}
    , layout_{new QVBoxLayout{this}}
    , dialog_{new MyDialog{this}}
{
    // Elemente des Widgets anordnen/anpassen
    layout_->addWidget(label1_);
    layout_->addWidget(button0_);
    layout_->addWidget(label2_);
    // Signal-Slot-Verbindungen einrichten
    connect(button0_, &QPushButton::clicked, dialog_, &MyDialog::exec);
    connect(dialog_, &MyDialog::accepted, this, &MyWidget::checkInputDialog);
    connect(dialog_, &MyDialog::rejected, this, &MyWidget::checkInputDialog);
    setWindowTitle("Hauptfenster - Anwendung");
}

void MyWidget::checkInputDialog( ) {
    int val = dialog_->result();
    if(val == QDialog::Accepted)
        label2_->setText(tr("'Ok' wurde gewählt"));
    else if( val == QDialog::Rejected )
        label2_->setText(tr("'Abbrechen' wurde gewählt"));
}

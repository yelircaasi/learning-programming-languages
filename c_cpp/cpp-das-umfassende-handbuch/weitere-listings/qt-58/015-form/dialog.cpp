// 015-form/dialog.cpp
#include "dialog.hpp"
#include "ui_dialog.h"
#include <QMessageBox>
Dialog::Dialog(QWidget *parent)
    : QDialog{parent}
    , ui{std::make_unique<Ui::Dialog>()}
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &Dialog::analyseDialog); //+
}
Dialog::~Dialog() noexcept
{}
void Dialog::analyseDialog() {
    QString str{};
    if( ui->lineEdit->text().isEmpty()) {
        str += tr("Name: keine Angaben\n");
    } else {
        str += tr("Name: %1\n").arg(ui->lineEdit->text());
    }
    if( ui->spinBox->cleanText().isEmpty()) {
        str += tr("Geburtsdatum: keine Angaben\n");
    } else {
        str += tr("Geburtsdatum: %1\n").arg(ui->spinBox->cleanText());
    }
    if( ui->radioButton->isChecked()) {
        str += tr("Geschlecht: männlich\n");
    } else {
        str += tr("Geschlecht: weiblich\n");
    }
    QMessageBox::information(nullptr, tr("Die Auswertung"), str);
}

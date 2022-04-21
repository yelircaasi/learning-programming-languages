// 020-mainwin/dialog.cpp
#include "dialog.hpp"
#include "ui_dialog.h"
#include <QMessageBox>
Dialog::Dialog(QWidget *parent)
    : QDialog{parent}
    , ui{std::make_unique<Ui::Dialog>()}
{
    ui->setupUi(this);
    connect(this, &Dialog::accepted, this, &Dialog::done);
}
Dialog::~Dialog() noexcept
{}
void Dialog::done() {
    emit addEntry(ui->lineEdit->text(), ui->spinBox->value(),
      ui->radioButton->isChecked() ? "m" : "w");
}

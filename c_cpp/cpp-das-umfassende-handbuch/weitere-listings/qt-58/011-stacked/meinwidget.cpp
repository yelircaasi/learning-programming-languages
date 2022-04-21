#include "meinwidget.h"
#include "ui_meinwidget.h"

MeinWidget::MeinWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MeinWidget)
{
    ui->setupUi(this);
}

MeinWidget::~MeinWidget()
{
    delete ui;
}

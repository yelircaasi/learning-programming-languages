#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "dialog.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    dialog{new Dialog}
{
    ui->setupUi(this);
    ui->tableWidget->insertColumn(0);
    connect(ui->action_Neu, &QAction::triggered, dialog, &Dialog::exec); //+
    connect(dialog, &Dialog::addEntry, this, &MainWindow::addEntry); //+
    //auto icon = QApplication::style()->standardIcon(QStyle::SP_FileDialogNewFolder);
    //ui->action_Neu->setIcon(icon);
    auto icon = QIcon(":/icon/neu.png");
    ui->action_Neu->setIcon(icon);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::addEntry(QString str) {
    ui->tableWidget->insertRow(0);
    ui->tableWidget->setItem(0, 0, new QTableWidgetItem(str));
    ui->statusBar->showMessage(tr("Eintrag hinzugefügt"));
}
void MainWindow::actionNeu() {
    dialog->exec();
}

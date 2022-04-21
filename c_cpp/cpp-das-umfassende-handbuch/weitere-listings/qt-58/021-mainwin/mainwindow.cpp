// 021-mainwin/mainwindow.cpp
#include "mainwindow.hpp"
#include <QApplication>
#include <QMenu>
#include <QVBoxLayout>
MainWindow::MainWindow(QWidget *parent)
: QMainWindow{parent}
, actNeu_{new QAction{QIcon{":/icon/neu.png"}, "&Neu", this}}
, centralWidget_{new QWidget{this}}
, tblWidget_{new QTableWidget{centralWidget_}}
, mebMain_{new QMenuBar{this}}
, tobMain_{new QToolBar{this}}
, stbMain_{new QStatusBar{this}}
, dialog_{new Dialog{}}
{
    resize(480, 300);
    auto layout = new QVBoxLayout{centralWidget_};
    layout->setSpacing(6);
    layout->setContentsMargins(10, 10, 10, 10);
    layout->addWidget(tblWidget_);
    setCentralWidget(centralWidget_);
    // Menüsh
      auto menuDatei = new QMenu{"&Datei", mebMain_};
      mebMain_->addAction(menuDatei->menuAction());
      auto menuBearbeiten = new QMenu{"&Bearbeiten", mebMain_};
      mebMain_->addAction(menuBearbeiten->menuAction());
      auto menuAktionen = new QMenu{"&Aktionen", mebMain_};
      mebMain_->addAction(menuAktionen->menuAction());
      menuAktionen->addAction(actNeu_);
      setMenuBar(mebMain_);
    tobMain_->addAction(actNeu_);
    addToolBar(Qt::TopToolBarArea, tobMain_);
      setStatusBar(stbMain_);
    // tblWidget auf Inhalte vorbereiten
    tblWidget_->setColumnCount(3);
    tblWidget_->setHorizontalHeaderLabels({"Name","Jahr","m/w"});
    tblWidget_->setColumnWidth(0, 250);
    tblWidget_->setColumnWidth(1, 80);
    tblWidget_->setColumnWidth(2, 50);
    // weitere Texte
    setWindowTitle("Hauptfenster");
    actNeu_->setStatusTip("Eintrag hinzufügen");
    // connect
    connect(actNeu_, &QAction::triggered, dialog_, &Dialog::exec); //+
    connect(dialog_, &Dialog::addEntry, this, &MainWindow::addEntry); //+
}

void MainWindow::addEntry(QString name, int jahr, QString geschl) {
    tblWidget_->insertRow(0); // Zeile 0 hinzufügen
    tblWidget_->setItem(0, 0, new QTableWidgetItem{name});
    tblWidget_->setItem(0, 1, new QTableWidgetItem{tr("%1").arg(jahr)});
    tblWidget_->setItem(0, 2, new QTableWidgetItem{geschl});
    stbMain_->showMessage(tr("Eintrag hinzugefügt"));
}

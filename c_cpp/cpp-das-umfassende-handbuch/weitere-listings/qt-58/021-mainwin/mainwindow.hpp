// 021-mainwin/mainwindow.hpp
#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include <QAction>
#include <QMainWindow>
#include <QMenuBar>
#include <QStatusBar>
#include <QTableWidget>
#include <QToolBar>

#include "dialog.hpp"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
private:
    QAction *actNeu_;
    QWidget *centralWidget_;
    QTableWidget *tblWidget_;
    QMenuBar *mebMain_;
    QToolBar *tobMain_;
    QStatusBar *stbMain_;
    //
    Dialog *dialog_;
public slots:
    void addEntry(QString name, int jahr, QString geschl);
};

#endif // MAINWINDOW_HPP

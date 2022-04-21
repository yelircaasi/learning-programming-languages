// 013-dialog/mydialog.hpp
#ifndef MY_DIALOG_HPP
#define MY_DIALOG_HPP
#include <QDialog>
class MyDialog : public QDialog {
    Q_OBJECT
public:
    explicit MyDialog(QWidget *parent = nullptr);
public slots: //+
    void mySetResult(); //+
};
#endif // MY_DIALOG_HPP

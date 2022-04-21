// 014-input/mywidget.hpp
#ifndef MY_WIDGET_HPP
#define MY_WIDGET_HPP
#include <QString>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
class MyWidget : public QWidget {
    Q_OBJECT
public:
    explicit MyWidget(QWidget* parent = nullptr);
private slots:
    void myGetText(); //+
    void myGetDouble(); //+
    void myGetInt(); //+
    void myGetItem(); //+
private:
    QPushButton* bGetText_; //+
    QPushButton* bGetDouble_; //+
    QPushButton* bGetInt_; //+
    QPushButton* bGetItem_; //+
    QLabel* lResult_;
    QVBoxLayout* layout_;
};
#endif // MY_WIDGET_HPP

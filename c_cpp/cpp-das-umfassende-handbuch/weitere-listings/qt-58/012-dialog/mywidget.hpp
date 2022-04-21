// 012-dialog/mywidget.hpp
#ifndef MY_WIDGET_HPP
#define MY_WIDGET_HPP
#include <QString>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include "mydialog.hpp"
class MyWidget : public QWidget {
    Q_OBJECT
public:
    explicit MyWidget(QString title = tr("Bitte Button betätigen"),
                      QWidget* parent = nullptr);
private slots:
    void checkInputDialog();
private:
    QPushButton* button0_;
    QLabel* label1_;
    QLabel* label2_;
    QVBoxLayout* layout_;
    MyDialog* dialog_;
};
#endif // MY_WIDGET_HPP

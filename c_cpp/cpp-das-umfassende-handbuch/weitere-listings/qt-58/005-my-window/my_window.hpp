// 005-my-window/my_window.hpp
#ifndef MY_WINDOW_HPP
#define MY_WINDOW_HPP
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QObject>
class MyWindow : public QWidget {
    Q_OBJECT
public:
    MyWindow(QWidget* parent = nullptr);
private: // nicht selbst Besitzer dieser QWidgets:
    QLabel* label_;
    QPushButton* button0_;
    QPushButton* button1_;
    QVBoxLayout* layout_;
    int cnt_ = 0; // zählt die Klicks mit
private slots:
    void setText();
};
#endif // MY_WINDOW_HPP

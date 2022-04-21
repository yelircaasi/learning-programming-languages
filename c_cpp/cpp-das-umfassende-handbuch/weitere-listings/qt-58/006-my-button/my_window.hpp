// 006-my-button/my_window.hpp
#ifndef MY_WINDOW_HPP
#define MY_WINDOW_HPP
#include <QWidget>
#include <QVBoxLayout>
#include <QMessageBox>
#include <array>
#include "my_button.hpp"
class MyWindow : public QWidget {
    Q_OBJECT
public:
    explicit MyWindow(QWidget* parent = 0);
private:
    std::array<MyButton*,3> myButton_;
public slots:
    void myMessageBox(int id); // Slot für die Ausgabe
};
#endif // MY_WINDOW_HPP

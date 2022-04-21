// 006-my-button/my_button.hpp
#ifndef MY_BUTTON_HPP
#define MY_BUTTON_HPP
#include <QString>
#include <QWidget>
#include <QPushButton>
class MyButton : public QPushButton {
    Q_OBJECT
public:
    MyButton(const QString& text, int id, QWidget* parent = 0);
    explicit MyButton(const QString& text, QWidget* parent = 0);
private:
    static int nextId_;
    int id_;
public slots:
    void click();         // click() überschreiben
signals:
    void clicked(int id); // ein neues Signal hinzufügen
};
#endif // MY_BUTTON_HPP

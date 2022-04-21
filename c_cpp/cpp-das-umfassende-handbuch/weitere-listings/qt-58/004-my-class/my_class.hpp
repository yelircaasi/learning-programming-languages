// 004-my-class/my_class.hpp
#ifndef MY_CLASS_HPP // Include Guard
#define MY_CLASS_HPP

#include <QObject>

/* Eine Klasse, die Signals und Slots besitzt. */
class MyClass : public QObject {
    Q_OBJECT
public:
    int value() const { return val_; }
public slots:
    // Der Wert von "val" wird geändert.
    void setValue(int newVal);
signals:
    /* Das Signal soll nur ausgesandt werden,
       wenn "val" geändert wird. */
    void valueChanged(int);
private:
    int val_;
};

#endif // MY_CLASS_HPP

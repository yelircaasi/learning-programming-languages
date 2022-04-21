// 002-signal-slot/signal_slot01.cpp
#include <QApplication>
#include <QtWidgets>
#include <memory>
int main(int argc, char **argv) {
    QApplication app(argc, argv);
    QWidget win{};
    win.setWindowTitle("Signal-Slot-Verbindungen");
    // Neues Eingabefeld
    auto spin = new QSpinBox{&win};
    spin->setMinimum(0);       // Minimum
    spin->setMaximum(100);     // Maximum
    // Neuer Schieberegler
    auto slider = new QSlider{Qt::Horizontal, &win};
    slider->setMinimum(0);     // Minimum
    slider->setMaximum(100);   // Maximum
    // Signal-und-Slot Verbindungen einrichten
    QObject::connect(
        spin, SIGNAL( valueChanged(int) ),
        slider, SLOT( setValue(int) ) );
    QObject::connect(
        slider, SIGNAL( valueChanged(int) ),
        spin, SLOT( setValue(int) ) );
    // Neue horizontale Box
    auto layout = new QVBoxLayout{&win};
    layout->addWidget(spin);
    layout->addWidget(slider);
    win.show();
    return app.exec();
}

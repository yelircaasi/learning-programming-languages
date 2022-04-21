// 002-lambda/lambda01.cpp
#include <QApplication>
#include <QtWidgets>
#include <memory>
int main(int argc, char **argv) {
    QApplication app(argc, argv);
    auto win = std::make_unique<QWidget>();
    win->setWindowTitle("Signal-Slot-Verbindungen");
    // Neues Eingabefeld
    auto spin = std::make_unique<QSpinBox>();
    spin->setMinimum(0);       // Minimum
    spin->setMaximum(100);     // Maximum
    // Neuer Schieberegler
    auto slider = std::make_unique<QSlider>(Qt::Horizontal);
    slider->setMinimum(0);     // Minimum
    slider->setMaximum(100);   // Maximum
    // Signal-und-Slot Verbindungen einrichten
    QObject::connect(
        spin.get(), SIGNAL( valueChanged(int) ),
        slider.get(), SLOT( setValue(int) ) );
    QObject::connect(
        slider.get(), SIGNAL( valueChanged(int) ),
        spin.get(), SLOT( setValue(int) ) );
    // Button und Label
    auto button = std::make_unique<QPushButton>("Knopf");
    auto label = std::make_unique<QLabel>("Titel");
    auto pLabel = label.get();
    QObject::connect(
        button.get(), &QPushButton::clicked,
        [pLabel](auto) { pLabel->setText("Neuer Titel"); } );
    // Neue vertikale Box
    auto layout = std::make_unique<QVBoxLayout>(win.get());
    layout->addWidget(spin.release());
    layout->addWidget(slider.release());
    layout->addWidget(button.release());
    layout->addWidget(label.release());
    win->show();
    return app.exec();
}

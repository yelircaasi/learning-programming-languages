#include <QApplication>
#include <QtWidgets>

int main(int argc, char **argv) {
    QApplication app{argc, argv};
    // Komponenten zusammenfügen
    // - Fenster
    QWidget window{};
    window.setWindowTitle("Hallo Qt");
    // - Knopf
    auto button = new QPushButton("Ende", &window);
    QObject::connect(
        button, &QPushButton::clicked,
        &app, &QApplication::quit );
    // - Layout
    auto layout = new QVBoxLayout{&window};
    layout->addWidget(button);
    window.setLayout(layout);
    // Start
    window.show();
    return app.exec();
}

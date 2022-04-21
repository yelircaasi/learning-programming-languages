#include <QApplication>
#include "meinwidget.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MeinWidget window{};
    window.show();
    return app.exec();
}

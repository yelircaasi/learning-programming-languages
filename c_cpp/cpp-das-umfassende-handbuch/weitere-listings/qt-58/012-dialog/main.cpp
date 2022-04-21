// 012-dialog/main.cpp
#include <QApplication>
#include "mywidget.hpp"
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MyWidget window{};
    window.show();
    return app.exec();
}

// 006-my_button/main.cpp
#include <QApplication>
#include "my_window.hpp"
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MyWindow window{};
    window.show();
    return app.exec();
}

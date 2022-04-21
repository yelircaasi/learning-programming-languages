#ifndef MEINWIDGET_H
#define MEINWIDGET_H

#include <QWidget>

namespace Ui {
class MeinWidget;
}

class MeinWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MeinWidget(QWidget *parent = 0);
    ~MeinWidget();

private:
    Ui::MeinWidget *ui;
};

#endif // MEINWIDGET_H

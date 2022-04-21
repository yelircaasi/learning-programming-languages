#ifndef DIALOG_HPP
#define DIALOG_HPP

#include <QDialog>
#include <memory>

namespace Ui {
    class Dialog;
}

class Dialog : public QDialog {
    Q_OBJECT
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog() noexcept;
private:
    std::unique_ptr<Ui::Dialog> ui;
private slots: //+
    void done(); //+
signals:
    void addEntry(QString str);
};

#endif // DIALOG_HPP

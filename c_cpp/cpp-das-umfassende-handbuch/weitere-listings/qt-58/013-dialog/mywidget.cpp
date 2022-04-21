// 013-dialog/mywidget.cpp
#include "mywidget.hpp"
#include "mydialog.hpp"
#include <QApplication>
#include <QMessageBox>
#include <QFileDialog>
#include <QString>
// Neue Widget-Klasse von QWidget ableiten
MyWidget::MyWidget(QString lab, QWidget *parent)
    : QWidget{parent}
    , button0_{new QPushButton{"Dialog starten",this}}
    , label1_{new QLabel(lab, this)}
    , label2_{new QLabel{this}}
    , layout_{new QVBoxLayout{this}}
    , dialog_{new MyDialog{this}}
{
    // Elemente des Widgets anordnen/anpassen
    layout_->addWidget(label1_);
    layout_->addWidget(button0_);
    layout_->addWidget(label2_);
    // Signal-Slot-Verbindungen einrichten
    connect(button0_, &QPushButton::clicked, dialog_, &MyDialog::exec);
    connect(dialog_, &MyDialog::accepted, this, &MyWidget::checkInputDialog);
    connect(dialog_, &MyDialog::rejected, this, &MyWidget::checkInputDialog);
    connect(dialog_, &MyDialog::finished, this, &MyWidget::checkInputDialogArg);
    setWindowTitle("Hauptfenster - Anwendung");
}

void MyWidget::checkInputDialog( ) {
    int val = dialog_->result();
    if(val == QDialog::Accepted)
        label2_->setText(tr("'Ok' wurde gewählt"));
    else if( val == QDialog::Rejected )
        label2_->setText(tr("'Abbrechen' wurde gewählt"));
}

void MyWidget::checkInputDialogArg(int val) {
    auto res = QMessageBox::question(this,
        "Frage", "Sein oder nicht sein?",
        QMessageBox::Yes | QMessageBox::No);
    if(res == QMessageBox::Yes) {
        QMessageBox::warning(this, "Na dann", "Du hast es so gewollt");
    } else {
        QMessageBox box(QMessageBox::Warning, "Wählen", "Welche Aktion?",
            QMessageBox::Cancel | QMessageBox::Yes | QMessageBox::No | QMessageBox::YesToAll | QMessageBox::NoToAll );
        box.addButton("Unentschlossen", QMessageBox::RejectRole);
        auto res2 = box.exec();
        switch(res2) {
        case QMessageBox::Yes:
            ;
        case QMessageBox::Rejected:
            myopenfile();
            ;
        }
    }
    if(val == 99)
        label2_->setText("'Ignorieren' wurde gewählt");
}

void MyWidget::myopenfile() {
    QFileDialog dlg{this, "Bitte eine Datei auswählen"};
    dlg.setFileMode(QFileDialog::ExistingFiles);
    dlg.setDirectory(QDir::homePath());
    dlg.setNameFilter("Dateien (*.cpp *.cxx *.cc)");
    dlg.setViewMode(QFileDialog::Detail);
    QStringList fileNames{};
    if(dlg.exec())
        fileNames = dlg.selectedFiles();
    auto info = tr("Ihre Auswahl: %1\n")
        .arg(fileNames.join("\n"));
    QMessageBox::information(
        this, "Ihre Auswahl", info, QMessageBox::Ok );
}

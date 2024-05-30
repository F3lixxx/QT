#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QString>
#include <QDebug>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:

    void on_pb_login_clicked();

    void on_pb_cancel_clicked();

private:
    Ui::Dialog *ui;

};

#endif // DIALOG_H

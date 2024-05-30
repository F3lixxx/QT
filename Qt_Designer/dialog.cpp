#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pb_login_clicked()
{
    QString name_Host = ui->le_hostName->text();
    QString name_DB = ui->le_nameDB->text();
    QString login = ui->le_login->text();
    QString password = ui->le_password->text();
    quint32 host = ui->sp_host->value();

    if (password != "1qaz2wsx"){
        QMessageBox::information(this,"Passed", "You are in Data Base", QMessageBox::Ok);
    }
    else{
         QMessageBox::warning(this,"Not Passed!\n", "You are wrote the simple password", QMessageBox::Ok);
    }
}


void Dialog::on_pb_cancel_clicked()
{
        QApplication::quit();
}


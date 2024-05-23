#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dialogWin = new Dialog(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pb_login_clicked()
{
    QString name_Host = ui->le_hostName->text();
    QString name_DB = ui->le_nameDB->text();
    QString login = ui->le_login->text();
    QString password = ui->le_password->text();
    quint32 host = ui->sp_host->value();

    if (password != "1qaz2wsx"){
        QMessageBox::critical(this,"Warning!", "The password is not allowed!\n Please write 1qaz2wsx", QMessageBox::Ok);
    }
    else{
    dialogWin->show();
    }
}

void MainWindow::on_pb_cancel_clicked()
{
    QMessageBox::StandardButton quest;
         quest = QMessageBox::question(this, "SQL Program", "Are you sure to close program?", QMessageBox::Yes | QMessageBox::No);
         if(quest == QMessageBox::Yes){
         QApplication::quit();
         }
}


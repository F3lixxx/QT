#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dialog.h"

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

void MainWindow::on_pb_go_clicked()
{
    dialogWin->show();
}

void MainWindow::on_pb_cancel_clicked()
{
    QApplication::quit();
}


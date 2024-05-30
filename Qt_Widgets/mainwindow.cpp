#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QAbstractButton>

#include <QPushButton>
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pb_dialog, &QPushButton::clicked,this, &MainWindow::pushbuttonClicked);
    ui->progressBar->setMaximum(100);

    connect(ui->pb_toggle, &QPushButton::toggled, this, &MainWindow::pushbuttonToggle);
    ui->pb_toggle->setCheckable(true);

    ui->rb_firstChanel->setText("Fisrt Chanel");
    ui->rb_secondChanel->setText("Second Chanel");

    ui->cb_choose->insertItem(1, "First Item");
    ui->cb_choose->insertItem(2, "Second Item");
    ui->cb_choose->insertItem(3, "Third Item");
    ui->cb_choose->insertItem(4, "Fourth Item");
    ui->cb_choose->insertItem(5, "Five Item");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pushbuttonClicked(){
    int value = ui->progressBar->value();
    if(value >= 100){
            ui->progressBar->setValue(0);
    }
    else{
            ui->progressBar->setValue(value+10);
    }
}

void MainWindow::pushbuttonToggle(bool checked){
    if(checked){
        qDebug() << "you are clicked toggle button";
    }
    else{
        qDebug() << "toggle button is off";
    }
}



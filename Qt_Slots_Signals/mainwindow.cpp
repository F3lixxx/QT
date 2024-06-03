#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <qDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ms = 0;
    s = 0;
    m = 0;
    lap = 0;
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    lb_lap = new QLabel;

    ui->verticalLayout->addWidget(lb_lap);
    ui->pb_lap->setDisabled(true);
    ui->pb_start_and_stop->setText("Start");
    ui->pb_lap->setText("Lap");
    ui->pb_reset->setText("Reset");

}

MainWindow::~MainWindow()
{
    delete ui;
}

class StopWatch{
public:
void MainWindow::updateTime(){
    ms++;
    if(ms >= 1000){
        ms = 0;
        s++;
    }
    if(s >= 60){
        s = 0;
        m++;
    }
    ui->lb_minute->setText(QString::number(m) + " : ");
    ui->lb_sec->setText(QString::number(s));
    ui->lb_msec->setText(" : " + QString::number(ms));
}

void MainWindow::on_pb_start_and_stop_clicked()
{
    flag = !flag;
    if(flag){
        ui->pb_lap->setDisabled(true);
        ui->pb_start_and_stop->setText("Start");
        timer->stop();
    }
    else{
        ui->pb_lap->setDisabled(false);
        ui->pb_start_and_stop->setText("Stop");
        timer->start(1);
    }
}

void MainWindow::on_pb_lap_clicked()
{
    ++lap;
    QString currentText = lb_lap->text();
    currentText.append("\nLap " + QString::number(lap) + ", Time: " + QString::number(m) + " : " + QString::number(s) + " : " + QString::number(ms));
    lb_lap->setText(currentText);
}

void MainWindow::on_pb_reset_clicked()
{
    m = 0;
    s = 0;
    ms = 0;
    lap = 0;
    lb_lap->clear();
    ui->lb_minute->setText(QString::number(m) + " : ");
    ui->lb_sec->setText(QString::number(s));
    ui->lb_msec->setText(" : " + QString::number(ms));
}
}

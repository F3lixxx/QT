#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stopwatch.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    watch(new Stopwatch),
    lapNumber(0)
{
    ui->setupUi(this);
    lb_timer = ui->lb_timer;
    tb_lap = ui->tb_lap;
    pb_start_stop = ui->pb_start_stop;
    pb_lap = ui->pb_lap;
    pb_reset = ui->pb_reset;

    // connect(pb_start_stop, &QPushButton::clicked, this, &MainWindow::on_pb_start_stop_clicked);
    // connect(pb_lap, &QPushButton::clicked, this, &MainWindow::on_pb_lap_clicked);
    // connect(pb_reset, &QPushButton::clicked, this, &MainWindow::on_pb_reset_clicked);
    connect(watch, &Stopwatch::timeUpdated, this, &MainWindow::updateTime);
    connect(watch, &Stopwatch::lapUpdated, this, &MainWindow::updateLap);

    pb_start_stop->setText("Start");
    pb_lap->setText("Lap");
    pb_reset->setText("Reset");
    pb_lap->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_start_stop_clicked()
{
    if (watch->isRunning()) {
        watch->stop();
        pb_start_stop->setText("Start");
        pb_lap->setEnabled(false);
    } else {
        watch->start();
        pb_start_stop->setText("Stop");
        pb_lap->setEnabled(true);
    }
}

void MainWindow::on_pb_lap_clicked()
{
    watch->lap();
}

void MainWindow::on_pb_reset_clicked()
{
    watch->reset();
    lapNumber = 0;
    tb_lap->clear();
    lb_timer->setText("00:00");
    pb_start_stop->setText("Start");
    pb_lap->setEnabled(false);
}

void MainWindow::updateTime(int elapsedTime)
{
    QString time = QTime::fromMSecsSinceStartOfDay(elapsedTime).toString("mm:ss");
    lb_timer->setText(time);
}

void MainWindow::updateLap(int lapNumber, int lapTime)
{
    QString time = QTime::fromMSecsSinceStartOfDay(lapTime).toString("mm:ss");
    tb_lap->append("Lap " + QString::number(lapNumber) + ", Time: " + time);
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTextBrowser>
#include <QPushButton>
#include <QTime>
#include "stopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_start_stop_clicked();
    void on_pb_lap_clicked();
    void on_pb_reset_clicked();
    void updateTime(int elapsedTime);
    void updateLap(int lapNumber, int lapTime);

private:
    Ui::MainWindow *ui;
    Stopwatch *watch;
    QLabel *lb_timer;
    QTextBrowser *tb_lap;
    QPushButton *pb_start_stop;
    QPushButton *pb_lap;
    QPushButton *pb_reset;
    int lapNumber;
};

#endif // MAINWINDOW_H

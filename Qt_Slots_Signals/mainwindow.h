#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QString>
#include <QPushButton>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private Q_SLOTS:
    void updateTime();

    void on_pb_start_and_stop_clicked();

    void on_pb_lap_clicked();

    void on_pb_reset_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QLabel *lb_lap;
    int ms, s, m;
    int prevMs, prevS, prevM;
    int lap;
    bool flag = true;
};
#endif // MAINWINDOW_H

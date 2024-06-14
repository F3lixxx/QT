#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>
#include <QTime>

class Stopwatch : public QObject
{
    Q_OBJECT

public:
    explicit Stopwatch(QObject *parent = nullptr);
    void start();
    void stop();
    void reset();
    void lap();
    bool isRunning() const;

signals:
    void timeUpdated(int elapsedTime);
    void lapUpdated(int lapNumber, int lapTime);

private slots:
    void onTimeout();

private:
    QTimer *timer;
    int elapsedTime;
    int lapStartTime;
    int lapNumber;
    bool running;
};

#endif // STOPWATCH_H

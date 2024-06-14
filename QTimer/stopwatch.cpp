#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent) :
    QObject(parent),
    timer(new QTimer(this)),
    elapsedTime(0),
    lapStartTime(0),
    lapNumber(0),
    running(false)
{
    connect(timer, &QTimer::timeout, this, &Stopwatch::onTimeout);
    timer->setInterval(100); // 100 ms interval
}

void Stopwatch::start()
{
    if (!running) {
        timer->start();
        running = true;
    }
}

void Stopwatch::stop()
{
    if (running) {
        timer->stop();
        running = false;
    }
}

void Stopwatch::reset()
{
    stop();
    elapsedTime = 0;
    lapStartTime = 0;
    lapNumber = 0;
    emit timeUpdated(elapsedTime);
}

void Stopwatch::onTimeout()
{
    elapsedTime += timer->interval();
    emit timeUpdated(elapsedTime);
}

void Stopwatch::lap()
{
    if (running) {
        lapNumber++;
        int currentLapTime = elapsedTime - lapStartTime;
        lapStartTime = elapsedTime;
        emit lapUpdated(lapNumber, currentLapTime);
    }
}

bool Stopwatch::isRunning() const
{
    return running;
}

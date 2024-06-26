#include "mainwindow.h"
#include "./ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->sb_initNum->setValue(200000);
    ui->rb_synchOff->setChecked(true);

   race1 = new Controller(&m);
   race2 = new Controller(&m);

   concurRace1 = new ExampleRace(&m);
   concurRace2 = new ExampleRace(&m);

    //Сигналы по завершению работы потоков
    connect(race1, &Controller::sig_WorkFinish, [&](){
        //отображаем только когда второй поток закончит работу
        if(countFinish == 0){
            countFinish++;
        }
        else{
            ui->te_debug->append("Искомое число равно: " + QString::number(number) + ", а должно быть " +
                                  QString::number(ui->sb_initNum->value()*2));
            ui->pb_start->setEnabled(true);
        }

    });

    connect(race2, &Controller::sig_WorkFinish, [&](){

        if(countFinish == 0){
            countFinish++;
        }
        else{
            ui->te_debug->append("Искомое число равно: " + QString::number(number) + ", а должно быть " +
                                 QString::number(ui->sb_initNum->value()*2));
            ui->pb_start->setEnabled(true);
        }

    });


    connect(concurRace1, &ExampleRace::sig_Finish, [&](){

        if(countFinish == 0){
            countFinish++;
        }
        else{
            ui->te_debug->append("Искомое число равно: " + QString::number(number) + ", а должно быть " +
                                 QString::number(ui->sb_initNum->value()*2));
            ui->pb_start->setEnabled(true);
        }
    });

    connect(concurRace2, &ExampleRace::sig_Finish, [&](){

        if(countFinish == 0){
            countFinish++;
        }
        else{
            ui->te_debug->append("Искомое число равно: " + QString::number(number) + ", а должно быть " +
                                 QString::number(ui->sb_initNum->value()*2));
            ui->pb_start->setEnabled(true);
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Метод запускает два потока
void MainWindow::StartRace(void){

    if(ui->rb_qtConcur->isChecked()){
        //  MainWindow, в методе StartRace, реализовать последовательный вызов методов
        // DoWork объектов concurRace1 и concurRace2 при помощи QtConcurrent.
        ui->te_debug->append("Запуск concurRace1->DoWork");

        uint32_t* inc = &number;
        bool mutexOn = ui->rb_mutexOn->isChecked();
        int numIterat = ui->sb_initNum->value();

        QFuture<void> future1 = QtConcurrent::run([this, inc, mutexOn, numIterat]() {
            this->concurRace1->DoWork(inc, mutexOn, numIterat);
        });

        QFutureWatcher<void> *watcher1 = new QFutureWatcher<void>(this);
        connect(watcher1, &QFutureWatcher<void>::finished, [this, inc, mutexOn, numIterat, watcher1]() {
            ui->te_debug->append("concurRace1 завершил DoWork");
            delete watcher1;  // Освобождаем память
            ui->te_debug->append("Запуск concurRace2->DoWork");

            QFuture<void> future2 = QtConcurrent::run([this, inc, mutexOn, numIterat]() {
                this->concurRace2->DoWork(inc, mutexOn, numIterat);
            });

            QFutureWatcher<void> *watcher2 = new QFutureWatcher<void>(this);
            connect(watcher2, &QFutureWatcher<void>::finished, [this, watcher2]() {
                ui->te_debug->append("concurRace2 завершил DoWork");
                delete watcher2;  // Освобождаем память
            });
            watcher2->setFuture(future2);
        });
        watcher1->setFuture(future1);

    }
    else{
        race1->operate(&number, ui->rb_mutexOn->isChecked(), ui->sb_initNum->value());
        race2->operate(&number, ui->rb_mutexOn->isChecked(), ui->sb_initNum->value());
    }
}

//Обработка кнопки "Старт"
void MainWindow::on_pb_start_clicked()
{
    ui->pb_start->setEnabled(false);
    countFinish = 0;
    number = 0;
    StartRace( );
}


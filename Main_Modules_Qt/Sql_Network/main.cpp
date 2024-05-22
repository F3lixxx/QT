#include <QCoreApplication>
#include <QtSql/QSqlDatabase>
#include <QtNetwork/QNetworkAccessManager>
#include <QDebug>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":memory:");

    if(!db.open()){
        qDebug() << "Failed to open database";
    } else {
        qDebug() << "Datatbase opened seccessfully";
    }


    QNetworkAccessManager manager;
    qDebug() << "Network Access Manager created";

    return a.exec();
}

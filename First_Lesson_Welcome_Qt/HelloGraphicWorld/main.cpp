#include <QApplication>
#include <QMessageBox>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int x = 0;
    QString str = "123";
    QMessageBox msg;
    msg.setText("Hello Graphic World!!!");
    msg.setIcon(QMessageBox::Warning);
    msg.setWindowTitle("Hello");
    msg.setStyleSheet("color : green");
    qDebug() << str;
    //std::cout << str; // std::cout лучше не использовать!
    msg.show();

    // MainWindow w;
    // w.show();

    return a.exec();


}

#include "mainwindow.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qDebug()<<"status: "<<healthy<<" "<<infect<<" "<<immuniz;

    MainWindow w;
    w.show();



    return a.exec();
}

#include "mainwindow.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Human* phuman = NULL;

    phuman = new Human [SIZEMASS];

    parssing_file(phuman);

    QVector <int> temp = phuman[0].get_friends();

    qDebug()<<phuman[0].get_index()<<"\n";

    foreach (int i, temp ) {

        qDebug()<<i;
    }

    MainWindow w;
    w.show();

    return a.exec();
}

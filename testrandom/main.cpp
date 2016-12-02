#include "main.h"


int main(int argc, char *argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    int mas[100];

    qsrand(midnight.secsTo(QTime::currentTime()));

    for (int i=0; i<100;i++){

        mas[i]=0;
    }

    for (int i=0; i<10000;i++){

        mas[qrand()%100]++;

    }

    int min=10000,max=-10000;

    for (int i=0; i<100;i++){

        qDebug()<<"\n"<<mas[i];

        (mas[i]>max)?max=mas[i]:1;
        (mas[i]<min)?min=mas[i]:1;

    }

    qDebug()<<"\n min: "<<min<<" max:"<<max;

    return 0;
}


#ifndef HUMAN_H
#define HUMAN_H

#include <QVector>
#include <QFile>
#include <QString>
#include <QStringList>
#include <QDebug>

#define SIZEMASS 10000

class Human

{
public:
    Human();
    void set_index(int i);
    void add_to_vector(int i);

    QVector <int> get_friends();
    int get_index();

    friend bool parssing_file(Human* pointerHuman);



private:
    int index = 0;
    int status = 0;
    QVector <int> friends;
};


//class human
//{
//    int index;

//    QVector<int> friend;
//};

#endif // HUMAN_H

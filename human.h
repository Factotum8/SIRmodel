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
    void set_status(int values);
    void set_iteration(int value);

    QVector <int> get_friends();
    int get_index();
    int get_status();
    int get_iteration();


    static bool parssing_file(Human* pointer);



private:
    int index;
    int status;
    int iteration;
    QVector <int> friends;
};


//class human
//{
//    int index;

//    QVector<int> friend;
//};

#endif // HUMAN_H

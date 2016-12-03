#include "human.h"



Human::Human()
{
    index =0;
    status=0;
    iteration =0;
}

void Human::set_index(int i)
{
    this->index   = i;
}

int Human::get_index()
{
    return index;
}

int Human::get_status()
{
    return status;
}
void Human::set_status(int values)
{
    status = values;
}

int Human::get_iteration()
{
    return iteration;
}

void Human::set_iteration(int value)
{
    iteration = value;
}

void Human::add_to_vector(int value)
{
    this->friends.push_back(value);
}

QVector <int> Human::get_friends()
{
    return friends;
}

bool Human::parssing_file (Human* pointerHuman)
{
    QFile file ("inputfile");

    if (!file.open(QIODevice::ReadOnly)){

        return true;
    }

    QStringList rawdata;

    while (!file.atEnd()){

        QByteArray line = file.readLine();

        rawdata << line;

    }

    int length = rawdata.size();

    for (int i=0;i<length;++i){

        QStringList temp = rawdata.at(i).simplified().split(' ');
        /* simplified Возвращает строку,
         у которой пробельные символы удалены в начале и в конце, а все последовательные пробельные символы заменены одиночным пробелом.*/

        pointerHuman[temp.at(0).toInt()-1].index=temp.at(0).toInt()-1;
        pointerHuman[temp.at(0).toInt()-1].friends<<( temp.at(1).toInt() - 1);

//        qDebug()<<temp.at(1).toInt();

    }


    file.close();

    return false;
}

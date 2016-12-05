#include "mainwindow.h"
#include "ui_mainwindow.h"

Human* phuman = NULL;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose);

    QTime midnight(0,0,0);

    qsrand(midnight.secsTo(QTime::currentTime()));

    //    Status status;

}

MainWindow::~MainWindow()
{
    if (phuman != NULL)
        delete [] phuman;

    delete ui;
}

void MainWindow::on_showGraph_clicked()
{

    if (ui->CountImmunized->text().isEmpty() || ui->CountInfected->text().isEmpty() ||
            ui->CountNodes->text().isEmpty() || ui->ProbabilityImmunize->text().isEmpty() || ui->ProbabilityInfecting->text().isEmpty() )
    {
        return;
    }

    CountInfected = ui->CountInfected->text().toInt();
    CountImmunized = ui->CountImmunized->text().toInt();
    CountNodes = ui->CountNodes->text().toInt();

    ProbabilityImmunize = ui->ProbabilityImmunize->text().toInt();
    ProbabilityInfecting = ui->ProbabilityInfecting->text().toInt();


    QVector <double>* infected = NULL;
    QVector <double>* immunized = NULL;

    infected = new QVector <double>;

    immunized = new QVector <double>;

    int raund = 1;
    int* count_immuniz=NULL;
    int* count_infect =NULL;

    count_immuniz = new int;

    count_infect = new int;

    phuman = new Human [CountNodes];


    if ( Human::parssing_file(phuman) ) {

        return;
    }

    for (int i=0; i<CountInfected; ){

        int j = qrand()%CountNodes;

        if ( phuman[j].get_status() == 0 ){

            phuman[j].set_status(infect);

            ++i;
        }
    }

    for (int i=0; i<CountImmunized; ){

        int j = qrand()%CountNodes;

        if ( phuman[j].get_status() == 0 ){

            phuman[j].set_status(immuniz);

            ++i;
        }
    }

    //    qDebug()<<"count_infect: "<<count_infect_immuniz(phuman);
    print_sources();



    while (CountInfected>0)
    {
        for (int i=0;i<CountNodes;i++){

            if (phuman[i].get_status() == infect && phuman[i].get_iteration() != raund){

                phuman[i].set_iteration(raund);

                //                qDebug()<<"phuman[i]: "<<i;

                if ( qrand()%100+1 <= ProbabilityImmunize ){ // пробуем имунизироваться

                    phuman[i].set_status(immuniz);

                    CountInfected--;

                    //                    qDebug()<<"     CountInfected immuniz:"<<CountInfected;
                }

                int size = phuman[i].get_friends().size();

                for (int j=0; j<size ; ++j ){

                    int roll = qrand()%100+1;

                    //                    qDebug()<<"     roll"<< roll;

                    int _friend = phuman[i].get_friends().at(j);

                    //                    qDebug()<<"     get_friends at"<< _friend;

                    if (roll<=ProbabilityInfecting && phuman[ _friend ].get_iteration() != raund && phuman[ _friend ].get_status() != immuniz && phuman[ _friend ].get_status() != infect) { // пробуем заразить

                        phuman[ _friend ].set_status(infect);

                        phuman[ _friend ].set_iteration(raund);

                        CountInfected++;

                    }

                }
            }

        }

        ++raund;

        //            qDebug()<< "raund: "<<raund;

        //            qDebug()<< "CountInfected: "<<CountInfected;

        count_infect_immuniz(phuman,count_infect,count_immuniz);

        (*infected)<<(*count_infect);


        (*immunized)<<(*count_immuniz);

        //            qDebug()<<"count_infect: "<<flag;

        if ( (*infected).last() == 0 ) break;
    }


    qDebug()<<"CountInfected"<<CountInfected;

    FormGraphHuman*  formgraphhuman = new FormGraphHuman (raund,infected,immunized);

    formgraphhuman->show();
}

void MainWindow::on_exit_clicked()
{
    close();
}


void MainWindow::print_sources ()
{
    qDebug()<<"CountInfected: "<< CountInfected;
    qDebug()<<"CountImmunized: "<<CountImmunized ;
    qDebug()<<"CountNodes: "<<CountNodes;
    qDebug()<<"ProbabilityImmunize: "<<ProbabilityImmunize;
    qDebug()<<"ProbabilityInfecting: "<<ProbabilityInfecting;
}

int MainWindow::count_infect_immuniz (Human* pointer,int* count_inf, int* count_imm)
{
    *count_inf=0;

    *count_imm=0;

    for (int i=0;i<CountNodes;++i)

    {
        if (pointer[i].get_status() == infect){

            (*count_inf) = (*count_inf)+1;

        }

        if (pointer[i].get_status() == immuniz){

            (*count_imm) = (*count_imm)+1;

        }
    }

    return 0;
}

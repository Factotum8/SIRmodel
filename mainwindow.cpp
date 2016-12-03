#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    delete ui;
}

void MainWindow::on_showGraph_clicked()
{
    Human* phuman = NULL;

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


    QVector <int> infected;

    phuman = new Human [CountNodes];

    if ( Human::parssing_file(phuman) ) {

        return;
    }

    for (int i=0; i<CountInfected; ){

        int j = qrand()%CountNodes;

        if ( phuman[j].get_status() == 0 ){

            phuman[j].set_status(infect);

            infected << j;

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

    print_sources();

    int raund = 1;

    while (CountInfected>0)
    {
        for (int i=0;i<CountNodes;i++){

            if (phuman[i].get_status() == infect && phuman[i].get_iteration() != raund){

                phuman[i].set_iteration(raund);

                if ( qrand()%100+1 <= ProbabilityImmunize ){ // пробуем имунизироваться

                    phuman[i].set_status(immuniz);

                    --CountInfected;
                }

                int size = phuman[i].get_friends().size();

                for (int j=0; j<size ; ++j ){

                    int roll = qrand()%100+1;

                    int _friend = phuman[i].get_friends().at(j);

                    if (roll<=ProbabilityInfecting && phuman[ _friend ].get_iteration() != raund && phuman[ _friend ].get_status() != immuniz ) { // пробуем заразить

                        phuman[ _friend ].set_status(infect);

                        phuman[ _friend ].set_iteration(raund);

                        ++CountInfected;

                    }

                }
            }

        }

        ++raund;
        if (raund % 2000 == 0) {

            qDebug()<< "raund: "<<raund;

            qDebug()<< "CountInfected: "<<CountInfected;
        }
    }


    FormGraphHuman*  formgraphhuman = new FormGraphHuman;

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

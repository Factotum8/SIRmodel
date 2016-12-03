#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qsrand(midnight.secsTo(QTime::currentTime()));

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

    int CountInfected = ui->CountInfected->text().toInt() , CountImmunized = ui->CountImmunized->text().toInt(), CountNodes = ui->CountNodes->text().toInt();

    phuman = new Human [CountNodes];

    parssing_file(phuman);

    for (int i=0; i<CountInfected; ){

        int j = qrand()%CountNodes;

        if ( phuman[j].status == 0 ){


        }
    }

    //        QVector <int> temp = phuman[0].get_friends();

    //        qDebug()<<phuman[0].get_index()<<"\n";

    //        foreach (int i, temp ) {

    //            qDebug()<<i;

    //    }



}

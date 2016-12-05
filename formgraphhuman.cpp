#include "formgraphhuman.h"
#include "ui_formgraphhuman.h"

FormGraphHuman::FormGraphHuman(int iteration, QVector<double>* infected, QVector<double>* immunized, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FormGraphHuman)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose);

    this->setFixedHeight(600);

    this->setFixedWidth(1250);

    ui->centralwidget->addGraph();

    ui->centralwidget->addGraph();

    ui->centralwidget->xAxis->setLabel("кол-во итераций");

    ui->centralwidget->yAxis->setLabel("Кол-во узлов");

    ui->centralwidget->xAxis->setRange(0,iteration);

    ui->centralwidget->yAxis->setRange(0,10000);

    QVector <double> xaxis;

    for (int i=0;i<iteration-1;i++){

        xaxis<<i;
    }

    ui->centralwidget->graph(0)->setPen(QColor(00, 100, 00, 255));


    ui->centralwidget->graph(0)->setData(xaxis,(*infected));

    ui->centralwidget->graph(1)->setData(xaxis,*immunized);

    ui->centralwidget->replot();

    //    ui->centralWidget->graph(0)->setData(x,y);
}

FormGraphHuman::~FormGraphHuman()
{
    delete ui;
}

#include "formgraphhuman.h"
#include "ui_formgraphhuman.h"

FormGraphHuman::FormGraphHuman(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FormGraphHuman)
{
    ui->setupUi(this);
}

FormGraphHuman::~FormGraphHuman()
{
    delete ui;
}

#include "formgraphhuman.h"
#include "ui_formgraphhuman.h"

FormGraphHuman::FormGraphHuman(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FormGraphHuman)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose);
}

FormGraphHuman::~FormGraphHuman()
{
    delete ui;
}

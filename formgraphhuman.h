#ifndef FORMGRAPHHUMAN_H
#define FORMGRAPHHUMAN_H

#include <QMainWindow>

namespace Ui {
class FormGraphHuman;
}

class FormGraphHuman : public QMainWindow
{
    Q_OBJECT

public:
    explicit FormGraphHuman(QWidget *parent = 0);
    ~FormGraphHuman();

private:
    Ui::FormGraphHuman *ui;
};

#endif // FORMGRAPHHUMAN_H
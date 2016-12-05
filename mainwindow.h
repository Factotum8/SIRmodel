#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>

#include "human.h"
#include "formgraphhuman.h"



enum Status {

    healthy = 0,
    infect = 1,
    immuniz =2
};

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void print_sources ();
    int count_infect_immuniz (Human* pointer,int* count_infect, int* count_immuniz);

private slots:
    void on_showGraph_clicked();

    void on_exit_clicked();

private:
    Ui::MainWindow *ui;

    int CountInfected , CountImmunized , CountNodes ;

    int ProbabilityImmunize , ProbabilityInfecting ;
};


#endif // MAINWINDOW_H

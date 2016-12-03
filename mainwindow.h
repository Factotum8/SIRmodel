#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>

#include "human.h"

namespace Ui {
class MainWindow;
}

QTime midnight(0,0,0);

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_showGraph_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

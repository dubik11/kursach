#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "scheduler.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_checkBox_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_action_3_triggered();

    void on_action_changed();

    void on_action_hovered();

    void on_action_triggered(bool checked);

    void on_action_3_triggered(bool checked);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_action_5_triggered(bool checked);

    void on_action_4_triggered(bool checked);

private:
    Ui::MainWindow *ui;
    Scheduler *a;
    Ticker *f1 = NULL, *f2 = NULL, *f3 = NULL;

};

#endif // MAINWINDOW_H

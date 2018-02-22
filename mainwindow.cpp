#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fstream"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    statusBar()->addWidget(ui->label_2);
    statusBar()->addWidget(ui->label);
    a = new Scheduler(ui->label);
    a->start();
    ifstream fin;
    fin.open("config.lrm");
    if (fin)
    {
        string t;
        fin >> t;
        ui->timeEdit->setTime(QTime::fromString(QString::fromStdString(t)));
        fin >> t;
        ui->checkBox_2->setChecked(stoi(t));
        fin >> t;
        ui->timeEdit_2->setTime(QTime::fromString(QString::fromStdString(t)));
        fin >> t;
        ui->checkBox_3->setChecked(stoi(t));
        fin >> t;
        ui->timeEdit_3->setTime(QTime::fromString(QString::fromStdString(t)));
        fin >> t;
        ui->checkBox_4->setChecked(stoi(t));
    }
    fin.close();
}

MainWindow::~MainWindow()
{
    delete ui;
    a->terminate();
    ofstream fout;
    fout.open("config.lrm");
    fout << ui->timeEdit->time().toString().toStdString() << endl << int(ui->checkBox_2->isChecked()) << endl;
    fout << ui->timeEdit_2->time().toString().toStdString() << endl << int(ui->checkBox_3->isChecked()) << endl;
    fout << ui->timeEdit_3->time().toString().toStdString() << endl << int(ui->checkBox_4->isChecked()) << endl;
    fout.close();
    if (f1 != NULL)
        f1->terminate();
    if (f2 != NULL)
        f2->terminate();
    if (f3 != NULL)
        f3->terminate();
}

void MainWindow::on_pushButton_clicked()
{
    if (f1 == NULL)
    {
        ui->pushButton->setText("Остановить");
        f1 = new Ticker(ui->timeEdit->time(), ui->checkBox_2, ui->label_3);
        f1->start();
        ui->timeEdit->setEnabled(false);
    }
    else
    {
        ui->pushButton->setText("Запустить");
        f1->terminate();
        delete f1;
        f1 = NULL;
        ui->timeEdit->setEnabled(true);
    }
}



void MainWindow::on_checkBox_clicked()
{

}

void MainWindow::on_checkBox_stateChanged(int arg1)
{

}

void MainWindow::on_action_3_triggered()
{

}

void MainWindow::on_action_changed()
{

}

void MainWindow::on_action_hovered()
{

}

void MainWindow::on_action_triggered(bool checked)
{

}

void MainWindow::on_action_3_triggered(bool checked)
{
    qApp->quit();
}

void MainWindow::on_pushButton_2_clicked()
{
    if (f2 == NULL)
    {
        ui->pushButton_2->setText("Остановить");
        f2 = new Ticker(ui->timeEdit_2->time(), ui->checkBox_3, ui->label_4);
        f2->start();
        ui->timeEdit_2->setEnabled(false);
    }
    else
    {
        ui->pushButton_2->setText("Запустить");
        f2->terminate();
        delete f2;
        f2 = NULL;
        ui->timeEdit_2->setEnabled(true);
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    if (f3 == NULL)
    {
        ui->pushButton_3->setText("Остановить");
        f3 = new Ticker(ui->timeEdit_3->time(), ui->checkBox_4, ui->label_5);
        f3->start();
        ui->timeEdit_3->setEnabled(false);
    }
    else
    {
        ui->pushButton_3->setText("Запустить");
        f3->terminate();
        delete f3;
        f3 = NULL;
        ui->timeEdit_3->setEnabled(true);
    }
}

void MainWindow::on_action_5_triggered(bool checked)
{
    QMessageBox Author;
    Author.setText("Программа создана Дубоносовым Вячеславом Сергеевичем\nСтудентом группы 726-2\nСпециальность Информационная безопасность");
    Author.setWindowTitle("Об авторе");
    Author.exec();
}

void MainWindow::on_action_4_triggered(bool checked)
{
    QMessageBox About;
    About.setText("Для установки времени срабатывания используйте специальные формы со временем.\nЕсли необходимо, поставьте галочку напротив надписи \"Каждый день\" для ежедневого срабатывания.\nНажмите кнопку \"Запустить\" чтобы запустить будильник.\nПри срабатывании будилника нажмите кнопку \"Остановить\" чтобы выключить его.\nПри закрытии программы все настройки сохраняются.");
    About.setWindowTitle("О программе");
    About.exec();
}

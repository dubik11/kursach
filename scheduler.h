#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <QWidget>
#include "QThread"
#include "QTime"
#include "QLabel"
#include "QTimeEdit"
#include "QMessageBox"
#include "QApplication"
#include "QCheckBox"

class Scheduler : public QThread
{
private:
    QLabel *a;
public:
    Scheduler(QLabel*& A)
    {
        a = A;
        this->setTerminationEnabled();
    }
    void run() override
    {
        QTime b;
        QString c;

        for(;;)
        {
            b = QTime::currentTime();
            c = b.toString();
            a->setText(c);
            sleep(1);
        }
    }
};

class Ticker: public QThread
{
private:
    QTime a;
    QCheckBox *b;
    QLabel *D;
public:
    Ticker(QTime A, QCheckBox *B, QLabel* d)
    {
        a = A;
        b = B;
        D = d;
        this->setTerminationEnabled();
    }

    void run() override
    {
        QTime cur;
        D->setText("");
        do
        {
            cur = QTime::currentTime();
            while (!((a.minute() == cur.minute()) && (a.hour() == cur.hour())))
            {
                cur = QTime::currentTime();
                sleep(1);
            }
            for (int i = 0; i < 10; i++)
            {
                D->setText("Будильник сработал");
                QApplication::beep();
                sleep(1);
                D->setText("");
                sleep(1);
            }
            D->setText("Будильник сработал");

        } while(b->isChecked());
    }

};


#endif // SCHEDULER_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{ double x0,y0,delta,lambda;
    x0=ui->doubleSpinBox->value();
    qDebug()<<x0<<" x0 ";
    y0=ui->doubleSpinBox_2->value();
    qDebug()<<y0<<" y0 ";
    bool trs; //trs=ui->checkBox->isTristate();
    //if (trs==false)
      //  {x0*=-1;}
    //trs=ui->checkBox_2->isTristate();
    //if (trs==false)
      //  {y0*=-1;}
    delta=ui->doubleSpinBox_3->value();
    qDebug()<<delta;
    //lambda=ui->doubleSpinBox_4->value();
    //trs=ui->checkBox_3->isTristate();
    //if(trs=true)
     //   {lambda/=10;}
    lambda=0.00001;
    qDebug()<<lambda;

    double x,y,gradx,grady;
    x=x0;
    y=y0;

    bool b; b=true;

    qDebug()<<"start! ";
    int i=0;
    while(b)
        { gradx=2*x*exp(x*x+y*y)+2;
          qDebug()<<gradx;
          grady=2*y*exp(x*x+y*y)-3.5;
          qDebug()<<grady;




         x-=lambda*gradx;
              qDebug()<<" x "<<x;
         y-=lambda*grady;
              qDebug()<<" y "<<y;

         b=(sqrt(gradx*gradx+grady*grady)>delta);//пока существует градиент
              qDebug()<<b<<" b ";
         i++;

        }

    double ff;
    ff=exp(x*x+y*y)+2*x-3.5*y;
    ui->textEdit->setText("Многомерная оптимизация: ");
    ui->textEdit->append("Значение  в точке x: ");
    ui->textEdit->append(QString::number(x));
    ui->textEdit->append("Значение  в точке у: ");
    ui->textEdit->append(QString::number(y));
    ui->textEdit->append("Значение функции: ");
    ui->textEdit->append(QString::number(ff));
    ui->textEdit->append("Количество измерений: ");
    ui->textEdit->append(QString::number(i));



}

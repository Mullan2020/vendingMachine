#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::changeMoney(int n){
    money +=n;
    ui->lcdNumber->display(QString::number(money));

    //
    if (money<100){
        ui->pbPepsi->setEnabled(false);
        ui->pbCoffee->setEnabled(false);
        ui->pbTea->setEnabled(false);
    }
    else if(money<130){

        ui->pbPepsi->setEnabled(false);
        ui->pbTea->setEnabled(false);
    }
    else if(money<200){
        ui->pbPepsi->setEnabled(false);
    }//

}





void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);

}

void Widget::on_pbPepsi_clicked()
{   changeMoney(-200);

}

void Widget::on_pbTea_clicked()
{
    changeMoney(-130);
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbChange_clicked()
{

     QMessageBox msg;
    if (money==0){
        msg.information(nullptr, "change", "no change");
    }//end of if
    else {

        int a=0,b=0,c=0,d=0;

        a=money/500;
        money=money % 500;

        b=money/100;
        money=money % 100;

        c=money/50;
        money=money % 50;

        d=money/10;

        char s[4];
        sprintf(s,"%d",a);

        char sum[100] = "500 won= ";
        strcat(sum,s);

        strcat(sum,"\n100 won= ");
        sprintf(s,"%d",b);
        strcat(sum,s);


        strcat(sum,"\n50 won= ");
        sprintf(s,"%d",c);
        strcat(sum,s);


        strcat(sum,"\n10 won= ");
        sprintf(s,"%d",d);
        strcat(sum,s);


        msg.information(nullptr,"change",sum);




    }//end of else if

}

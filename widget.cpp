#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setControl();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int coin)
{
    money += coin;
    ui->lcdNumber->display(money);
    setControl();
}

void Widget::setControl()
{
    ui->pbCoffee->setEnabled(money >= 200);
    ui->pbTea->setEnabled(money >= 150);
    ui->pbMilk->setEnabled(money >= 100);
}


void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}


void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}


void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbReset_clicked()
{
    int coin500 = 0, coin100 = 0, coin50 = 0, coin10 = 0;
    while(money > 0){
        if(money >= 500){
            changeMoney(-500);
            coin500++;
        } else if(money >= 100){
            changeMoney(-100);
            coin100++;
        } else if(money >= 50){
            changeMoney(-50);
            coin50++;
        } else if(money >= 10){
            changeMoney(-10);
            coin10++;
        }
    }
    QString msg;
    msg.sprintf("500원: %d개\n100원: %d개\n50원: %d개\n10원: %d개", coin500, coin100, coin50, coin10);
    QMessageBox::information(this, "거스름돈", msg);
}


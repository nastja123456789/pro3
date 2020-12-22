#include "dialog.h"
#include "ui_dialog.h"
#include "TEvent.h"
#include "TSingleEvent.h"
#include "TRegularEvent.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

/*void Dialog::on_buttonBox_accepted()
{
}*/

void Dialog::setTyp( int t )
{
    ui->label_2->setVisible( t >= 1);
    ui->dateEdit->setVisible( t >= 1);

    ui->label_3->setVisible( t >= 2);
    ui->spinBox->setVisible( t >= 2);
    ui->label_4->setVisible( t >= 2);
    ui->spinBox_2->setVisible( t >= 2);
    ui->pushButton_3->setVisible( t >= 2 );
}

void Dialog::getData( TEvent *e )
{
    e->setName(ui->lineEdit->text());

    if (typ >= 1)
    {
        ((TSingleEvent*) e)->setDt(ui->dateEdit->date());
        ((TSingleEvent*) e)->setDTime(ui->dateEdit->time());
    }

    if (typ >= 2)
    {
        ((TRegularEvent*) e)->setDelta(ui->spinBox->value());
        ((TRegularEvent*) e)->setLim(ui->spinBox_2->value());
        ((TSingleEvent*) e)->setDt(ui->dateEdit->date());
        ((TSingleEvent*) e)->setDTime(ui->dateEdit->time());
    }
}

void Dialog::on_pushButton_2_clicked()
{
    reject();
}

void Dialog::on_pushButton_clicked()
{
    accept();
}

void Dialog::on_pushButton_3_clicked()
{
    ui->spinBox_2->setValue(-1);
}

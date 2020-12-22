#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <model.h>
#include "dialog.h"
#include "TEvent.h"
#include "TRegularEvent.h"
#include "TSingleEvent.h"

MyModel *model;
QList<TEvent*> lst;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Создаем модель и устаналиваем ее параметры
    model = new MyModel();

    // Заголовки берутся из модели
    // model->setHeaderData( 0, Qt::Horizontal, tr("Описание") );

    ui->tableView->setModel( model );
    ui->tableView->setColumnWidth( 0, 150 );
    ui->tableView->setColumnWidth( 1, 250 );

    model->selModel = ui->tableView->selectionModel();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    lst.clear();

    lst.append( new TEvent( (char*) "Купить хлеба" ) );
    lst.append( new TSingleEvent( (char*) "Сдать экзамен", QDate(2020, 11, 25), QTime(12, 13, 14, 15)) );
    lst.append( new TRegularEvent( (char*) "Погулять с собакой", QDate(2020, 11, 1), QTime(07, 0, 0, 0)) );

    doFilter();
}

// Единая функция фильтрации
void MainWindow::doFilter()
{
    model->clear();
    QDate now =  QDate::currentDate();

    for( int i = 0; i < lst.size(); i++ )
    {
        TEvent *e = lst.at(i);

        // Обрабатываем галки на форме
        if (ui->radioButton_2->isChecked())
        {
            if (!e->inDate(now, now))
                continue;
        }
        if (ui->radioButton_3->isChecked())
        {
            if (!e->inDate( ui->dateEdit->date(), ui->dateEdit->date()) )
                continue;
        }
        if (ui->radioButton_4->isChecked())
        {
            if (!e->inDate( ui->dateEdit->date(), ui->dateEdit_2->date()) )
                continue;
        }

        model->add( e );
    }
}

void MainWindow::on_radioButton_clicked()
{
    doFilter();
}

void MainWindow::on_radioButton_2_clicked()
{
    doFilter();
}

void MainWindow::on_radioButton_3_clicked()
{
    doFilter();
}

void MainWindow::on_radioButton_4_clicked()
{
    doFilter();
}

// Добавить разные события
void MainWindow::on_pushButton_2_clicked()
{
    Dialog *dlg = new Dialog( this );
    dlg->setTyp( 0 );

    if (dlg->exec() == QDialog::Accepted)
    {
        TEvent *e = new TEvent();

        dlg->getData( e );

        lst.append( e );

        doFilter();
    }

    delete dlg;
}

void MainWindow::on_pushButton_3_clicked()
{
    Dialog *dlg = new Dialog( this );
    dlg->setTyp( 1 );

    if (dlg->exec() == QDialog::Accepted)
    {
        TSingleEvent *e = new TSingleEvent();

        dlg->getData( e );

        lst.append( e );

        doFilter();
    }

    delete dlg;
}

void MainWindow::on_pushButton_4_clicked()
{
    Dialog *dlg = new Dialog( this );
    dlg->setTyp( 2 );

    if (dlg->exec() == QDialog::Accepted)
    {
        TRegularEvent *e = new TRegularEvent();

        dlg->getData( e );

        lst.append( e );

        doFilter();
    }

    delete dlg;
}

void MainWindow::on_pushButton_5_clicked()
{
    auto ind = ui->tableView->selectionModel()->selectedIndexes();

    if (ind.size() != 1)
        return;

    lst.removeAll( model->lst.at( ind.at(0).row() ) );

    doFilter();
}

void MainWindow::on_pushButton_6_clicked()
{
    Sort<TEvent> sort(lst);

    sort.sorting();

    lst = sort.getLst();

    model->clear();

    for( int i = 0; i < lst.size(); i++ )
    {
        TEvent *e = lst.at(i);

        model->add( e );
    }
}

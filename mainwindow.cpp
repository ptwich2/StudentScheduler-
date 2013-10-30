#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialogButtonBox>
#include <QAbstractButton>
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);

    QPushButton *okButton = ui->holidayChanges->button(QDialogButtonBox::Ok);
    connect(okButton, SIGNAL(clicked()), this, SLOT(okBox()));

    QPushButton *resetButton = ui->holidayChanges->button(QDialogButtonBox::Reset);
    connect(resetButton, SIGNAL(clicked()), this, SLOT(resetBox()));

    ui->holidayStart->setDate(QDate::currentDate());
    ui->holidayEnd->setDate(QDate::currentDate());
}

MainWindow::~MainWindow()
{
    delete ui;
}

//name field to object

/*
void MainWindow::on_holidayStart_clicked()
{
    ui->startCalendar->show(); //on click display start calendar
}

//
void MainWindow::on_holidayEnd_clicked()
{
    ui->endCalendar->show(); //on click display end calendar
}
*/

//need calendar events start
//need calendar events end

/*
//reset = all objects saved = null
void MainWindow::QDialogButtonBox::Reset::on_clicked()
{
   //QDialogButtonBox::ResetRole needed to reset input fields?
}
*/

//ok = retrieve objects and send to higher
//void MainWindow::holidayChanges(QAbstractButton *button)
//{
//    if(ui->holidayChanges->buttonRole(button) == QDialogButtonBox::ResetRole)
//    {
//        ui->holidayName->clear();//setText("Hi");
//    }
//    //QString holidayName = ui->holidayName->text();
//    //QString holidayComments = ui->holidayComments->text();
//    //cout << holidayName;
//    //cout << holidayComments;
//}
void MainWindow::okBox()
{
    QString holidayNameContents = ui->holidayName->text();
    QString holidayCommentsContents = ui->holidayComments->toPlainText();
    QString holidayStartDate = ui->holidayStart->date().toString();
    QString holidayEndDate = ui->holidayEnd->date().toString();
}

void MainWindow::resetBox()
{
    ui->holidayName->clear();
    ui->holidayComments->clear();
    ui->holidayStart->setDate(QDate::currentDate());
    ui->holidayEnd->setDate(QDate::currentDate());
}


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QDateTime>
#include <QDialogButtonBox>
#include <QAbstractButton>
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

void MainWindow::setHiUserText(QString hiText){
    ui->hiUser->setText(hiText);
}
/*
 * When user clicks on the "Create" button, it should
 * send the information to the server and then show the client
 * a message saying, "Semester successfully created!"
 *
 * It should also print out a string that includes the information
 * which the user will send to the server.
 */
void MainWindow::on_createSemester_clicked()
{
    ui->notificationSemester->setText("Semester successfully created!");


    //Print out the information that the user inputs
    //cout << dateStart;
    //cout << dateEnd;
    //cout << nameSemesterEdit;

}

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




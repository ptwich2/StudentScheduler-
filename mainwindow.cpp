#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mynetwork.h"
#include <iostream>
#include <QDateTime>
#include <QDialogButtonBox>
#include <QAbstractButton>

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QDebug>

using namespace std;

#include <QDebug>

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
void MainWindow::on_createButton_click()
{
    ui->notificationSemester->setText("Semester successfully created!");

    //Print out the information that the user inputs
    //cout << dateStart;
    //cout << dateEnd;
    //cout << nameSemesterEdit;

}

void MainWindow::setUserID(QString u){
    userID = u;
}

void MainWindow::okBox()
{
    QString holidayNameContents = ui->holidayName->text();
    QString holidayCommentsContents = ui->holidayComments->toPlainText();
    QString holidayStartDate = ui->holidayStart->date().toString();
    QString holidayEndDate = ui->holidayEnd->date().toString();

    qDebug() << holidayNameContents;
    qDebug() << holidayStartDate;
    qDebug() << userID;
    MyNetwork *myPost = new MyNetwork;
    myPost->setPost("userID",userID);
    myPost->setPost("action","addHoliday");
    myPost->setPost("holidayName", holidayNameContents);
    myPost->setPost("holidayStartDate", holidayStartDate);
    myPost->setPost("holidayEndDate",holidayEndDate);


    connect(myPost, SIGNAL(donePost(MyNetwork *)),this,SLOT(sendHolidayName(MyNetwork *)));
    myPost->sendPost();
}

void MainWindow::sendHolidayName(MyNetwork *myPost)
{
    QJsonDocument jsonResponse  = QJsonDocument::fromJson(myPost->theResponse);
    QJsonObject jsonObject = jsonResponse.object();
    qDebug() << myPost->theResponse;
}

void MainWindow::resetBox()
{
    ui->holidayName->clear();
    ui->holidayComments->clear();
    ui->holidayStart->setDate(QDate::currentDate());
    ui->holidayEnd->setDate(QDate::currentDate());
}

void MainWindow::on_holidayChanges_clicked(QAbstractButton *button)
{

}

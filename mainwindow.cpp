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
 * When user clicks on the "Create" button, it sends the
 * information to the server and then prompts with an
 * authentication message, "Semester successfully created!"
 *
 */
void MainWindow::createButton()
{
    
    //Declare UI as strings and then convert to text
    QString dateStart = ui->dateStart->date().toString();
    QString dateEnd = ui->dateEnd->date().toString();
    QString semesterNameContents = ui->semesterNameEdit->text();
    
    //Sends to the server
    MyNetwork *myPost = new MyNetwork;
    myPost->setPost("action","addSemester");
    myPost->setPost("semesterName", semesterNameContents);
    
    connect(myPost, SIGNAL(donePost(MyNetwork *)),this,SLOT(sendSemesterName(MyNetwork *)));
    myPost->sendPost();
    
    
}//end on_createButton_click

/*
 * The information from the fields in the "Add new semester" form is sent to the server.
 */
void MainWindow::sendSemesterName(MyNetwork *myPost)
{
    
    QJsonDocument jsonResponse = QJsonDocument::fromJson(myPost->theResponse);
    QJsonObject jsonObject = jsonResponse.object();
    qDebug() << myPost->theResponse;
    // QJsonValue theStatusValue = jsonObject.value("status");
    // QJsonValue theInfoValue = jsonObject.value("userInfo");
    // QJsonObject theInfoValueObject = theInfoValue.toObject();
    
    // //Declare value of the objects using our field names
    // QJsonValue semesterStart = theInfoValueObject["semesterStartDate"];
    // QJsonValue semesterEnd = theInfoValueObject["semesterEndDate"];
    // QJsonValue semesterName1 = theInfoValueObject["semesterName"];
    
    // //If the server confirms the information, then it sends back a message
    // //Otherwise it sends an error message
    // if(theStatusValue.toString().compare("Good") == 0)
    // {
    // this->hide();
    // MainWindow mainWindow;
    // }
    // else
    // {
    // ui->notificationSemester->setText(theStatusValue.toString());
    // }
    
}//end void MainWindow::sendSemesterName...

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
    myPost->setPost("holidayComments", holidayCommentsContents);
    myPost->setPost("holidayStartDate", holidayStartDate);
    myPost->setPost("holidayEndDate",holidayEndDate);
    myPost->setPost("holidayComments",holidayCommentsContents);

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

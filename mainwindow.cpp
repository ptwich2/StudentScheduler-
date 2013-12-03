#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mynetwork.h"

#include <iostream>
#include <QDateTime>
#include <QDialogButtonBox>
#include <QAbstractButton>
#include <QDebug>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QApplication>

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

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

void MainWindow::setUserID(QString u)
{
    userID = u;
}

void MainWindow::setHiUserText(QString hiText){
    ui->hiUser->setText(hiText);
}
/*
 * When user clicks on the "Create" button, it sends the
 * information to the server.
 */
void MainWindow::on_createButton_clicked()
{

    //Declare UI as strings and then convert to text
    QString dateStart = ui->dateStart->date().toString();
    QString dateEnd = ui->dateEnd->date().toString();
    QString semesterNameContents = ui->semesterNameEdit->text();

    //Sends to the server
    MyNetwork *myPost = new MyNetwork;
    myPost->setPost("userID", userID);
    myPost->setPost("action","addSemester");
    myPost->setPost("semesterName", semesterNameContents);
    myPost->setPost("semesterStartDate", dateStart);
    myPost->setPost("semesterEndDate", dateEnd);

    connect(myPost, SIGNAL(donePost(MyNetwork *)),this,SLOT(sendSemesterName(MyNetwork *)));
    myPost->sendPost();

}//end on_createButton_clicked()

/*
 * The information from the fields in the "Add new semester" form is sent to the server.
 */
void MainWindow::sendSemesterName(MyNetwork *myPost)
{

    QJsonDocument jsonResponse = QJsonDocument::fromJson(myPost->theResponse);
    QJsonObject jsonObject = jsonResponse.object();
    qDebug() << myPost->theResponse;
    QJsonValue theStatusValue = jsonObject.value("status");
    QJsonValue theInfoValue = jsonObject.value("userInfo");
    QJsonObject theInfoValueObject = theInfoValue.toObject();

    //Declare value of the objects using our field names
    QJsonValue semesterStart = theInfoValueObject["semesterStartDate"];
    QJsonValue semesterEnd = theInfoValueObject["semesterEndDate"];
    QJsonValue semesterName1 = theInfoValueObject["semesterName"];

    //If the server confirms the information, then it sends back a message
    //Otherwise it sends an error message
    if(theStatusValue.toString().compare("Good") == 0)
    {
        //QString notificationSemester = ui->
        //notificationSemester.setText("Semester successfully added!");
    }
    else
    {
        ui->notificationSemester->setText(theStatusValue.toString());
    }

}//end void MainWindow::sendSemesterName...

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

/*
 * When the user creates an event, it will show up on the calendar.
 * When a specific day is clicked, the events will show up in the page
 * adjacent to the calendar.
 *
 * Debug: Use addHoliday data to test before implementation of adding events
 */
void MainWindow::on_eventCalendar_clicked(const QDate &date)
{

    //ui->showEvent->setText("testing"); //sanity check for buttons

    /*
     * 1. Grab the information from the server. (requires global objects)
     *      Specific field names to grab:
     *          holidayName
     *          holidayStartDate
     *          holidayEndDate
     *
     * 2. Add information to calendar.
     *      Compare dates to that of the calendar.
     *      If they match, then "add" the dates.
     *
     * 3. Debug
     */



}

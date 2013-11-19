#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mynetwork.h"

#include <iostream>
#include <QDateTime>
#include <QDialogButtonBox>
#include <QAbstractButton>
#include <QDebug>

#include <QDebug>

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
 *When user clicks on the "Create" button, it sends the
 * information to the server
 */
void MainWindow::on_createButton_clicked()
{

    //Declare UI as strings or text
    QString dateStart = ui->dateStart->date().toString();
    QString dateEnd = ui->dateEnd->date().toString();
    QString semesterNameContents = ui->semesterNameEdit->text();

    //This will show the information sent to the server
    qDebug() << dateStart;
    qDebug() << dateEnd;
    qDebug() << semesterNameContents;

    //Send to the server
    MyNetwork *myPost = new MyNetwork;
    myPost->setPost("userID", userID);
    myPost->setPost("action","addSemester");
    myPost->setPost("semesterName", semesterNameContents);
    myPost->setPost("semesterStartDate", dateStart);
    myPost->setPost("semesterEndDate", dateEnd);

    connect(myPost, SIGNAL(donePost(MyNetwork *)),this,SLOT(sendSemesterName(MyNetwork *)));
    myPost->sendPost();

}//end void MainWindow::on_createButton_clicked()

/*
 * The information from the fields in the "Add new semester" form is sent to the server.
 */
void MainWindow::sendSemesterName(MyNetwork *myPost)
{

    QJsonDocument jsonResponse = QJsonDocument::fromJson(myPost->theResponse);
    QJsonObject jsonObject = jsonResponse.object();
    qDebug() << myPost->theResponse;

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

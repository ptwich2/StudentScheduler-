#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mynetwork.h"
#include <iostream>
#include <QDateTime>
#include <QTime>
#include <QDialogButtonBox>
#include <QAbstractButton>
#include <QCheckBox>

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

void MainWindow::on_createCourse_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
    QString courseName = ui->courseName->text();
    QString courseType = ui->courseType->currentText();
    int monday =  ui->monday->isChecked();
    int tuesday = ui->tuesday->isChecked();
    int wednesday = ui->wednesday->isChecked();
    int thursday = ui->thursday->isChecked();
    int friday = ui->friday->isChecked();
    int saturday =ui->saturday->isChecked();
    int sunday = ui->sunday->isChecked();
    QString startTime = ui->startTime->time().toString();
    QString endTime = ui->endTime->time().toString();

    qDebug() << courseName;
    qDebug() << courseType;
    qDebug() << saturday;
    qDebug() << sunday;
    qDebug() << startTime;
    qDebug() << endTime;
    qDebug() << userID;
    MyNetwork *myPost = new MyNetwork;


    myPost->setPost("userID",userID);
    myPost->setPost("action","addCourse");
    myPost->setPost("courseName", courseName);
    myPost->setPost("courseType", courseType);
    myPost->setPost("monday", QString::number(monday));
    myPost->setPost("tuesday",QString::number(tuesday));
    myPost->setPost("wednesday",QString::number(wednesday));
    myPost->setPost("thursday",QString::number(thursday));
    myPost->setPost("friday",QString::number(friday));
    myPost->setPost("saturday",QString::number(saturday));
    myPost->setPost("sunday",QString::number(sunday));
    myPost->setPost("startTime",startTime);
    myPost->setPost("endTime",endTime);


    connect(myPost, SIGNAL(donePost(MyNetwork *)),this,SLOT(sendClassName(MyNetwork *)));
    myPost->sendPost();

    /*Once the information is sent to the server, reset the fields*/

//    ui->courseName->clear();
//    ui->courseType->setCurrentIndex(0);
//    ui->monday->setCheckState(false);
//    ui->tuesday->setCheckState(false);
//    ui->wednesday->setCheckState(false);
//    ui->thursday->setCheckState(false);
//    ui->friday->setCheckState(false);
//    ui->saturday->setCheckState(false);
//    ui->sunday->setCheckState(false);
//    ui->startTime->setTime(QTime::currentTime());
//    ui->endTime->setTime(QTime::currentTime());

}

void MainWindow::sendClassName(MyNetwork *myPost)
{
    QJsonDocument jsonResponse  = QJsonDocument::fromJson(myPost->theResponse);
    QJsonObject jsonObject = jsonResponse.object();
    qDebug() << myPost->theResponse;
}





void MainWindow::on_calculateGPA_clicked()
{
    ui->tabWidget->setCurrentIndex(2);
    int gradeA = ui->gradeA->text().toInt();
    int gradeB = ui->gradeB->text().toInt();
    int gradeC = ui->gradeC->text().toInt();
    int gradeD = ui->gradeD->text().toInt();
    int gradeF = ui->gradeF->text().toInt();
    float GPA = ((gradeA *4) + (gradeB*3) + (gradeC*2) + (gradeD * 1) + (gradeF * 0)) / (gradeA + gradeB + gradeC + gradeD + gradeF);



    qDebug() << gradeA;

    MyNetwork *myPost = new MyNetwork;


//    myPost->setPost("userID",userID);
//    myPost->setPost("action","calculateGPA");
//    myPost->setPost("gradeA", gradeA);
//    myPost->setPost("gradeB", gradeB);
//    myPost ->setPost("gradeC", gradeC);
//    myPost ->setPost("gradeD", gradeD);
//    myPost ->setPost ("gradeF", gradeF);

    connect(myPost, SIGNAL(donePost(MyNetwork *)),this,SLOT(sendGPA(MyNetwork *)));
    myPost->sendPost();

}

//void MainWindow::sendGPA(MyNetwork *myPost)
//{
//    QJsonDocument jsonResponse  = QJsonDocument::fromJson(myPost->theResponse);
//    QJsonObject jsonObject = jsonResponse.object();
//    qDebug() << myPost->theResponse;
//}



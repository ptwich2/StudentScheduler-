#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mynetwork.h"
#include "event.h"

#include <iostream>
#include <QDateTime>
#include <QTime>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QToolBox>
#include <QAbstractButton>
#include <QCheckBox>

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

void MainWindow::setUserID(QString u)
{
    userID = u;
}

void MainWindow::setGlobalObject(QByteArray u)
{
    globalObjects = u;
}


void MainWindow::setHiUserText(){
    QJsonDocument jsonResponse  = QJsonDocument::fromJson(globalObjects);
    QJsonObject jsonObject = jsonResponse.object();
    qDebug() << "In main window.";
    QJsonValue theStatusValue = jsonObject.value("status");
    QJsonValue theInfoValue = jsonObject.value("userInfo");
    QJsonObject theInfoValueObject = theInfoValue.toObject();
    QJsonValue theUsername = theInfoValueObject["username"];
    QJsonValue theFirstName = theInfoValueObject["firstName"];
    QJsonValue theLastName = theInfoValueObject["lastName"];
    QJsonValue theEmail = theInfoValueObject["email"];

    QString hiText = "<table>";
    if(theFirstName.toString().count() > 1){
        hiText += "<tr><td>First name:</td><td style=\"padding-left:10px;\">"+theFirstName.toString()+"</td></tr>";
    }
    if(theLastName.toString().count() > 1){
        hiText += "<tr><td>Last name:</td><td style=\"padding-left:10px;\">"+theLastName.toString()+"</td></tr>";
    }
        hiText += "<tr><td>Username:</td><td style=\"padding-left:10px;\">"+theUsername.toString()+"</td></tr>"
                  "<tr><td>Email:</td><td style=\"padding-left:10px;\">"+ theEmail.toString()+" (not verify)</td></tr>"
                  "</table>";
    ui->profileMainText->setText(hiText);
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
        //go to add classes
        ui->tabWidget->setCurrentIndex(2);
    }
    else
    {
        //error, stay on the same page
        ui->notificationSemester->setText(theStatusValue.toString());
        ui->tabWidget->setCurrentIndex(1);

    }

}//end void MainWindow::sendSemesterName


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
    QJsonDocument jsonResponse = QJsonDocument::fromJson(myPost->theResponse);
    QJsonObject jsonObject = jsonResponse.object();
    qDebug() << myPost->theResponse;
    QJsonValue theStatusValue = jsonObject.value("status");
    QJsonValue theInfoValue = jsonObject.value("userInfo");
    QJsonObject theInfoValueObject = theInfoValue.toObject();

    //Declare value of the objects using our field names


    QJsonValue holidayNameContents = theInfoValueObject["holidayName"];
    QJsonValue holidayCommentsContents = theInfoValueObject["holidayComments"];
    QJsonValue holidayStartDate = theInfoValueObject["holidayStartDate"];
    QJsonValue holidayEndDate = theInfoValueObject["holidayEndDate"];


    //If the server confirms the information, then it sends back a message
    //Otherwise it sends an error message
    if(theStatusValue.toString().compare("Good") == 0)
    {
        //go to calander to display holida
        ui->tabWidget->setCurrentIndex(0);
    }
    else
    {
        //error, stay on the same page
        ui->notificationHoliday->setText(theStatusValue.toString());
        ui->tabWidget->setCurrentIndex(1);

    }

}

void MainWindow::resetBox()
{
    ui->holidayName->clear();
    ui->holidayComments->clear();
    ui->holidayStart->setDate(QDate::currentDate());
    ui->holidayEnd->setDate(QDate::currentDate());
}

void MainWindow::on_createCourse_clicked()
{

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

    ui->courseName->clear();
    ui->courseType->setCurrentIndex(0);
    ui->monday->setChecked(false);
    ui->tuesday->setChecked(false);
    ui->wednesday->setChecked(false);
    ui->thursday->setChecked(false);
    ui->friday->setChecked(false);
    ui->saturday->setChecked(false);
    ui->sunday->setChecked(false);
    ui->startTime->setTime(QTime::currentTime());
    ui->endTime->setTime(QTime::currentTime());



}

void MainWindow::sendClassName(MyNetwork *myPost)
{
//    QJsonDocument jsonResponse  = QJsonDocument::fromJson(myPost->theResponse);
//    QJsonObject jsonObject = jsonResponse.object();
//    qDebug() << myPost->theResponse;

    QJsonDocument jsonResponse = QJsonDocument::fromJson(myPost->theResponse);
    QJsonObject jsonObject = jsonResponse.object();
    qDebug() << myPost->theResponse;
    QJsonValue theStatusValue = jsonObject.value("status");
    QJsonValue theInfoValue = jsonObject.value("userInfo");
    QJsonObject theInfoValueObject = theInfoValue.toObject();

    //Declare value of the objects using our field names


    QJsonValue courseName = theInfoValueObject["courseName"];
    QJsonValue courseType = theInfoValueObject["courseType"];
    QJsonValue monday =  theInfoValueObject["monday"];
    QJsonValue tuesday =theInfoValueObject["tuesday"];
    QJsonValue wednesday = theInfoValueObject["wednesday"];
    QJsonValue thursday = theInfoValueObject["thursday"];
    QJsonValue friday = theInfoValueObject["friday"];
    QJsonValue saturday = theInfoValueObject["saturday"];
    QJsonValue sunday = theInfoValueObject["sunday"];
    QJsonValue startTime = theInfoValueObject["startTime"];
    QJsonValue endTime = theInfoValueObject["endTime"];



    //If the server confirms the information, then it sends back a message
    //Otherwise it sends an error message
    if(theStatusValue.toString().compare("Good") == 0)
    {
        //course created, go to add events
       ui->tabWidget->setCurrentIndex(3);
    }
    else
    {
        //error, stay on the same page
        ui->notificationCreateCourse->setText(theStatusValue.toString());
        ui->tabWidget->setCurrentIndex(2);
    }


}





void MainWindow::on_calculateGPA_clicked()
{

    int gradeA = ui->gradeA->text().toInt();
    int gradeB = ui->gradeB->text().toInt();
    int gradeC = ui->gradeC->text().toInt();
    int gradeD = ui->gradeD->text().toInt();
    int gradeF = ui->gradeF->text().toInt();
    int gradePoints = ((gradeA *4) + (gradeB*3) + (gradeC*2) + (gradeD * 1) + (gradeF * 0));
    int totalPoints = gradeA+gradeB+gradeC+gradeD+gradeF;


    float gpa = (gradePoints/totalPoints);
    QString temp = QString::number(gpa, 'f', 2);
    ui->gpa->setText(temp);

    MyNetwork *myPost = new MyNetwork;

    myPost->setPost("userID",userID);
    myPost->setPost("action","calculateGPA");
    myPost->setPost("gpa",temp);
    connect(myPost, SIGNAL(donePost(MyNetwork *)),this,SLOT(sendGPA(MyNetwork *)));
    myPost->sendPost();
}

void MainWindow::sendGPA(MyNetwork *myPost)
{
//    QJsonDocument jsonResponse  = QJsonDocument::fromJson(myPost->theResponse);
//    QJsonObject jsonObject = jsonResponse.object();
//    qDebug() << myPost->theResponse;
      QJsonDocument jsonResponse = QJsonDocument::fromJson(myPost->theResponse);
      QJsonObject jsonObject = jsonResponse.object();
      qDebug() << myPost->theResponse;
      QJsonValue theStatusValue = jsonObject.value("status");
      QJsonValue theInfoValue = jsonObject.value("userInfo");
      QJsonObject theInfoValueObject = theInfoValue.toObject();

      //Declare value of the objects using our field names
      QJsonValue gpa = theInfoValueObject["gpa"];
      //If the server confirms the information, then it sends back a message
      //Otherwise it sends an error message
      if(theStatusValue.toString().compare("Good") == 0)
      {
          //course created, go to add events
         ui->tabWidget->setCurrentIndex(5);
      }
      else
      {
          //error, stay on the same page
          ui->tabWidget->setCurrentIndex(5);
      }





}



void MainWindow::on_createEvent_clicked()
{
    QString eventName = ui->eventName->text();
    QString eventStartTime = ui->eventStartTime->time().toString();
    QString eventEndTime = ui->eventEndTime->time().toString();
    QString eventNotificationTime = ui->eventNotificationTime->time().toString();
    int sendNotification = ui->sendNotification->isChecked();

    MyNetwork *myPost = new MyNetwork;
    myPost->setPost("userID",userID);
    myPost->setPost("action","calculateGPA");
    myPost->setPost("eventName",eventName);
    myPost->setPost("eventStartTime",eventStartTime);
    myPost->setPost("eventEndTime",eventEndTime);
    myPost->setPost("eventNotificationTime",eventStartTime);
    myPost->setPost("sendNotification", QString::number(sendNotification));

    connect(myPost, SIGNAL(donePost(MyNetwork *)),this,SLOT(sendEvent(MyNetwork *)));
    myPost->sendPost();

}

void MainWindow::sendEvent(MyNetwork *myPost)
{
    QJsonDocument jsonResponse = QJsonDocument::fromJson(myPost->theResponse);
    QJsonObject jsonObject = jsonResponse.object();
    qDebug() << myPost->theResponse;
    QJsonValue theStatusValue = jsonObject.value("status");
    QJsonValue theInfoValue = jsonObject.value("userInfo");
    QJsonObject theInfoValueObject = theInfoValue.toObject();

    QJsonValue eventName = theInfoValueObject["eventName"];
    QJsonValue eventStartTime = theInfoValueObject["eventStartTime"];
    QJsonValue eventEndTime =  theInfoValueObject["eventEndTime"];
    QJsonValue eventNotificationTime =theInfoValueObject["eventNotificationTime"];
    QJsonValue sendNotification = theInfoValueObject["sendNotification"];


    //If the server confirms the information, then it sends back a message
    //Otherwise it sends an error message
    if(theStatusValue.toString().compare("Good") == 0)
    {
//        //event created, go to next page
           ui->tabWidget->setCurrentIndex(4);

    }
//    else
    {
//        //error, stay on the same page
        ui->notificationCreateCourse->setText(theStatusValue.toString());
        ui->tabWidget->setCurrentIndex(3);
    }

}

/*
 * When the user creates an event, it will show up on the calendar.
 * When a specific day is clicked, the events will show up in the page
 * adjacent to the calendar.
 *
 * Debug: Use addHoliday data to test before implementation of adding events
 */
void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    QJsonDocument jsonResponse  = QJsonDocument::fromJson(globalObjects);
    QJsonObject jsonObject = jsonResponse.object();

    QJsonValue theInfoValue = jsonObject.value("class");
    QJsonArray classes = theInfoValue.toArray();

    int dayOfWeekNum = date.dayOfWeek();
    QString output = "<h3>Your schedule for "+date.toString()+"</h3>";
    foreach(QJsonValue theClass, classes)
    {
        QJsonObject theClassInfo = theClass.toObject();
        QString className = theClassInfo["className"].toString();
        QString classType = theClassInfo["courseType"].toString();
        QString classID = theClassInfo["classID"].toString();
        int monday = theClassInfo["monday"].toString().toInt();
        int tuesday = theClassInfo["tuesday"].toString().toInt();
        int wednesday = theClassInfo["wednesday"].toString().toInt();
        int thursday = theClassInfo["thursday"].toString().toInt();
        int friday = theClassInfo["friday"].toString().toInt();
        int saturday = theClassInfo["saturday"].toString().toInt();
        int sunday = theClassInfo["sunday"].toString().toInt();
        QString startTime = theClassInfo["startTime"].toString();
        QString endTime = theClassInfo["endTime"].toString();

        QString outputLocal = "<a style=\"text-decoration:none; color:black;\" href=\""+classID+"\"><h4>"+className+"</h4>"
                              "<table>"
                                    "<tr><td>Type:</td><td style=\"padding-left:10px;\">"+classType+"</td></tr>"
                                    "<tr><td>Start Time:</td><td style=\"padding-left:10px;\">"+startTime+"</td></tr>"
                                    "<tr><td>End Time:</td><td style=\"padding-left:10px;\">"+endTime+"</td></tr>"
                              "</table></a>";

        switch(dayOfWeekNum){
            case 1:
            if(monday == 1){
                output+=outputLocal;
            }
            break;
            case 2:
            if(tuesday == 1){
                output+=outputLocal;
            }
            break;
            case 3:
            if(wednesday == 1){
                output+=outputLocal;
            }
            break;
            case 4:
            if(thursday == 1){
                output+=outputLocal;
            }
            break;
            case 5:
            if(friday == 1){
                output+=outputLocal;
            }
            break;
            case 6:
            if(saturday == 1){
                output+=outputLocal;
            }
            break;
            case 7:
            if(sunday == 1){
                output+=outputLocal;
            }
            break;
        }

        ui->eventText->setText(output);
    }

}

void MainWindow::on_eventText_linkActivated(const QString &link)
{
    Event event;
    event.setClassID(link);
    event.setUserID(userID);
    event.exec();
    qDebug() << link;
}

void MainWindow::on_eventText_linkHovered(const QString &link)
{

}
void MainWindow::updateGlobalObject(MyNetwork *myPost)
{
    QJsonDocument jsonResponse  = QJsonDocument::fromJson(myPost->theResponse);
    QJsonObject jsonObject = jsonResponse.object();
    this->setGlobalObject(myPost->theResponse);
    qDebug() << globalObjects;
}


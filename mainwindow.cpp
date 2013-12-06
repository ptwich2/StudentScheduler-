#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mynetwork.h"
#include "event.h"
#include "confirmation.h"

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
#include <QtGui/QTextCharFormat>
#include <QtGui/QTextCharFormat>


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
 * information to the server and then prompts with an
 * authentication message, "Semester successfully created!"
 *
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

    connect(myPost, SIGNAL(donePost(MyNetwork *)),this,SLOT(updateGlobalObject(MyNetwork *)));
    myPost->sendPost();

    MainWindow::confirmationWindow(1);
}//end createSemesterButton

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

    connect(myPost, SIGNAL(donePost(MyNetwork *)),this,SLOT(updateGlobalObject(MyNetwork *)));
    myPost->sendPost();

    MainWindow::confirmationWindow(2);
    MainWindow::colorCodeCalendar();
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


    connect(myPost, SIGNAL(donePost(MyNetwork *)),this,SLOT(updateGlobalObject(MyNetwork *)));
    myPost->sendPost();

    MainWindow::confirmationWindow(3);

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

void MainWindow::updateGlobalObject(MyNetwork *myPost)
{
    QJsonDocument jsonResponse  = QJsonDocument::fromJson(myPost->theResponse);
    QJsonObject jsonObject = jsonResponse.object();
    this->setGlobalObject(myPost->theResponse);
    qDebug() << globalObjects;
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



    qDebug() << GPA;

    MyNetwork *myPost = new MyNetwork;


//    myPost->setPost("userID",userID);
//    myPost->setPost("action","calculateGPA");
//    myPost->setPost("gradeA", gradeA);
//    myPost->setPost("gradeB", gradeB);
//    myPost ->setPost("gradeC", gradeC);
//    myPost ->setPost("gradeD", gradeD);
//    myPost ->setPost ("gradeF", gradeF);

    connect(myPost, SIGNAL(donePost(MyNetwork *)),this,SLOT(updateGlobalObject(MyNetwork *)));
    myPost->sendPost();

}

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

void MainWindow::confirmationWindow(int i)
{
    Confirmation confirmation;

    switch(i)
    {
        case 1:
            confirmation.createdSemester();
            confirmation.show();
            confirmation.raise();
            confirmation.exec();
            break;
        case 2:
            confirmation.createdHoliday();
            confirmation.show();
            confirmation.raise();
            confirmation.exec();
            break;
        case 3:
            confirmation.createdClass();
            confirmation.show();
            confirmation.raise();
            confirmation.exec();
            break;
        case 4:
            confirmation.createdEvent();
            confirmation.show();
            confirmation.raise();
            confirmation.exec();
            break;
        default:
            break;
     }
}

void MainWindow::colorCodeCalendar()
{
//    QJsonDocument jsonResponse  = QJsonDocument::fromJson(globalObjects);
//    QJsonObject jsonObject = jsonResponse.object();

//    QJsonValue theInfoValue = jsonObject.value("holidayStartDate");
//    QJsonArray holidays = theInfoValue.toArray();


    QStringList startDate;
    QJsonDocument jsonResponse  = QJsonDocument::fromJson(globalObjects);
    QJsonObject jsonObject = jsonResponse.object();
    QJsonArray holidays = jsonObject["holidays"].toArray();


    foreach(const QJsonValue & holiday, holidays)
    {
        QBrush brush;
        brush.setColor(Qt::green);
        QTextCharFormat cf = ui->calendarWidget->dateTextFormat( QDate::currentDate() );
        cf.setBackground(brush);
        ui->calendarWidget->setDateTextFormat( QDate::currentDate(), cf);
    }
}

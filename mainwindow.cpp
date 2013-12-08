#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mynetwork.h"
#include "event.h"
#include "confirmation.h"
#include "welcomepage.h"

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


MainWindow::MainWindow(QWidget *parent) :
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->scheduleWidget->setCurrentIndex(0);
    
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
 * authentication message.
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
    ui->scheduleWidget->setCurrentIndex(1);
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


    connect(myPost, SIGNAL(donePost(MyNetwork *)),this,SLOT(updateGlobalObject(MyNetwork *)));
    myPost->sendPost();


    ui->scheduleWidget->setCurrentIndex(4);
}

void MainWindow::updateGlobalObject(MyNetwork *myPost)
{
    QJsonDocument jsonResponse  = QJsonDocument::fromJson(myPost->theResponse);
    QJsonObject jsonObject = jsonResponse.object();
    this->setGlobalObject(myPost->theResponse);

}


void MainWindow::on_calculateGPA_clicked()
{

    int gradeA = ui->gradeA->text().toInt();
    int gradeB = ui->gradeB->text().toInt();
    int gradeC = ui->gradeC->text().toInt();
    int gradeD = ui->gradeD->text().toInt();
    int gradeF = ui->gradeF->text().toInt();
    int totalPoints = (gradeA + gradeB + gradeC + gradeD + gradeF);
    int gradePoints = (gradeA *4) + (gradeB*3) + (gradeC*2) + (gradeD * 1) + (gradeF * 0);
    float gpa = (gradePoints/totalPoints);
    QString temp = QString::number(gpa, 'f', 2);
    ui->gpa->setText(temp);

    MyNetwork *myPost = new MyNetwork;

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

/*
 * Marks the calendar based on holidays and events only.
 *
 * 1. Parse through the information on the server
 * 2. If an event and/or holiday exists, grab their dates
 * 3. Compare dates
 * 4. If comparison is correct, mark the calendar
 */
void MainWindow::calendarWidget()
{
    //Grabs information from the server
    QJsonDocument jsonResponse  = QJsonDocument::fromJson(globalObjects);
    QJsonObject jsonObject = jsonResponse.object();

    //Grab event & holiday information
    QJsonValue theInfoValue = jsonObject.value("calendarDates");
    QJsonArray theDateInfo = theInfoValue.toArray();


    //When parsing each event, grab their date and convert to string
    foreach(QJsonValue theDates, theDateInfo)
    {
        QJsonObject theEventHoliday = theDates.toObject();
        QString events = theEventHoliday["eventDate"].toString();
        QString holidayBegins = theEventHoliday["holidayStartDate"].toString();
        QString holidayEnds = theEventHoliday["holidayEndDate"].toString();

        //There should be a string comparison between the event & calendar
        //If there are no event dates, then calendar shouldn't be marked
        if( !events.isEmpty() || (!holidayBegins.isEmpty() && !holidayEnds.isEmpty()) )
        {
            //Set brush to the color red
            QBrush brush;
            brush.setColor( Qt::red);

            //Have the brush color mark dates
            QTextCharFormat cf = ui->calendarWidget->dateTextFormat( QDate::currentDate() );
            cf.setBackground( brush );
            ui->calendarWidget->setDateTextFormat( QDate::currentDate(), cf );

        }

    }
}


//FORWARD BUTTONS

void MainWindow::on_goToSchedule_clicked()
{
    ui->mainWidget->setCurrentIndex(1);
    ui->scheduleWidget->setCurrentIndex(0);
}

void MainWindow::on_goToCalculator_clicked()
{
    ui->mainWidget->setCurrentIndex(2);
}

void MainWindow::on_goToProfile_clicked()
{
    ui->mainWidget->setCurrentIndex(3);
}

void MainWindow::on_goToNewOrOld_clicked()
{
    int newSem = ui->createNewSemester->isChecked();
    int oldSem = ui->chooseFromOldSemesters->isChecked();
    QString oldSemName = ui->oldSemesters->currentText();

    if (newSem == 1){
        ui->scheduleWidget->setCurrentIndex(2);
    }
    if (oldSem == 1){
        ui->scheduleWidget->setCurrentIndex(1);
    }


}


void MainWindow::on_goToCreateOrOldClass_clicked()
{
    int newClass = ui->createNewCourse->isChecked();
    int oldClass = ui->chooseFromOldCourse->isChecked();
    QString oldClassName = ui->oldCourses->currentText();

    if (newClass == 1)
    {
        ui->scheduleWidget->setCurrentIndex(3);
    }
    else if (oldClass == 1){
        ui->scheduleWidget->setCurrentIndex(4);
    }

}






//MainWidget backs



void MainWindow::on_goToNewOrOldSemester_clicked()
{
    ui->scheduleWidget->setCurrentIndex(0);
}


void MainWindow::on_seeAll_clicked()
{
    ui->eventsWidget->setCurrentIndex(1);
}

void MainWindow::on_goToCalendar_clicked()
{
    ui->mainWidget->setCurrentIndex(0);
}

void MainWindow::on_seeAllEvents_clicked()
{
    ui->mainWidget->setCurrentIndex(1);
    ui->scheduleWidget->setCurrentIndex(4);
    ui->eventsWidget->setCurrentIndex(1);

}

void MainWindow::on_buttonBox_accepted()
{
    QString eventName = ui->eventName->text();
    QString time = ui->eventTimeEdit->time().toString();
    QString date = ui->eventDateEdit->date().toString();

    QString output ="<table>"
                  "<tr><td>Event Name:</td><td style=\"padding-left:10px;\">"+eventName+"</td></tr>"
                  "<tr><td>at </td><td style=\"padding-left:10px;\">"+time+"</td></tr>"
                  "<tr><td>on:</td><td style=\"padding-left:10px;\">"+date+"</td></tr>"
            "</table></a>";
      ui->eventText_2->setText(output);

}

void MainWindow::on_backButton_clicked()
{
    int currIndexMain = ui->mainWidget->currentIndex();
    int currIndexSchedule   =   ui->scheduleWidget->currentIndex();
    int currIndexEvents     =   ui->eventsWidget->currentIndex();

    if (currIndexMain == 0){
        this->hide();
        WelcomePage welcomePage;
        welcomePage.show();
        welcomePage.exec();

    }
    
    else if ( (currIndexMain == 1 || currIndexMain == 2 || currIndexMain == 3) &&
         (currIndexSchedule == 0 ) && (currIndexEvents == 0)){
        ui->mainWidget->setCurrentIndex(0);
    }
    if ((currIndexMain == 1) && (currIndexSchedule == 0)){
        ui->mainWidget->setCurrentIndex(0);
    }
    else if ((currIndexMain == 1)&&((currIndexSchedule == 1) || currIndexSchedule ==2)){
        ui->scheduleWidget->setCurrentIndex(0);
    }
    else if ((currIndexMain == 1) && (currIndexSchedule == 3)){
         ui->scheduleWidget->setCurrentIndex(1);
    }
    else if (((currIndexMain == 1) && (currIndexSchedule == 4 )) && ((currIndexSchedule == 0) || (currIndexSchedule == 1)) ) {
        ui->mainWidget->setCurrentIndex(0);

    }
}

#include "event.h"
#include "ui_event.h"
#include "mynetwork.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QDebug>

Event::Event(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Event)
{
    ui->setupUi(this);
}

void Event::setClassID(QString u){
    classID = u;
    ui->eventDateEdit->setDate(QDate::currentDate());
    ui->eventTimeEdit->setTime(QTime::currentTime());
}
void Event::setUserID(QString u){
    userID = u;

}

Event::~Event()
{
    delete ui;
}

void Event::on_buttonBox_accepted()
{

    //Sends to the server
    MyNetwork *myPost = new MyNetwork;
    myPost->setPost("userID", userID);
    myPost->setPost("action","addEvent");
    myPost->setPost("classID", classID);
    myPost->setPost("eventName", ui->eventName->text());
    myPost->setPost("eventDate", ui->eventDateEdit->text());
    myPost->setPost("eventTime", ui->eventTimeEdit->text());
    myPost->setPost("notifyH", ui->notifyH->text());
    myPost->setPost("notifyM", ui->notifyM->text());



    connect(myPost, SIGNAL(donePost(MyNetwork *)),this,SLOT(sendEvent(MyNetwork *)));
    myPost->sendPost();




}

void Event::sendEvent(MyNetwork *myPost)
{
    QJsonDocument jsonResponse  = QJsonDocument::fromJson(myPost->theResponse);
    QJsonObject jsonObject = jsonResponse.object();


}

#include "welcomepage.h"
#include "ui_welcomepage.h"
#include "mainwindow.h"
#include "mynetwork.h"
#include "confirmation.h"

#include <iostream>
#include <string>
#include <QUrl>
#include <QDebug>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QApplication>

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

WelcomePage::WelcomePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WelcomePage)
{
    ui->setupUi(this);

//    QString myNetworkStr(myPost->postData);
//    std::cout << "The response: " << myNetworkStr.toStdString() << std::endl;
}

WelcomePage::~WelcomePage()
{
    delete ui;
}

void WelcomePage::on_credits_clicked()
{

    ui->welcomeWidget->setCurrentIndex(4);
    ui->backButton->show();
}



void WelcomePage::on_forgetPassword_clicked()
{
 ui->welcomeWidget->setCurrentIndex(3);
 ui->backButton->show();
}

void WelcomePage::on_createAnAccount_clicked()
{
    ui->welcomeWidget->setCurrentIndex(1);
    ui->backButton->show();
}


void WelcomePage::on_submitInCreateAcc_clicked()
{
    QString username = ui->usernameInCreateAcc->text();
    QString password = ui->passwordInCreateAcc->text();
    QString email = ui->emailInCreateAcc->text();

    MyNetwork *myPost = new MyNetwork;
    myPost->setPost("action","SignUp");
    myPost->setPost("username",username);
    myPost->setPost("password",password);
    myPost->setPost("email",email);

    qDebug() << username;
    qDebug() << password;
    this->hide();

    connect(myPost, SIGNAL(donePost(MyNetwork *)),this,SLOT(enterMainWindow(MyNetwork *)));
    myPost->sendPost();



}

void WelcomePage::enterMainWindow(MyNetwork *myPost){

    QJsonDocument jsonResponse  = QJsonDocument::fromJson(myPost->theResponse);
    QJsonObject jsonObject = jsonResponse.object();
    QJsonValue theStatusValue = jsonObject.value("status");
    QJsonValue theInfoValue = jsonObject.value("userInfo");
    QJsonObject theInfoValueObject = theInfoValue.toObject();
    QJsonValue theUserID = theInfoValueObject["userID"];
    if(theStatusValue.toString().compare("Good") == 0){
        this->hide();
        MainWindow mainWindow;
        mainWindow.setUserID(theUserID.toString());
        mainWindow.setGlobalObject(myPost->theResponse);
        mainWindow.setHiUserText();
        mainWindow.show();
        mainWindow.setFixedSize(mainWindow.size());
        mainWindow.exec();
    }else{
        if(theStatusValue.toString().compare("") != 0){
            ui->Notifications->setText(theStatusValue.toString());
        }else{
            ui->Notifications->setText("The server is not available.");
        }
    }
}

void WelcomePage::on_signIn_clicked()
{
    ui->welcomeWidget->setCurrentIndex(2);

}

void WelcomePage::on_backButton_clicked()
{

    int currIndex = ui->welcomeWidget->currentIndex();

   if (currIndex == 1 || currIndex ==2 || currIndex == 4){
        ui->welcomeWidget->setCurrentIndex(0);

    }
    else if (currIndex ==3){
        ui->welcomeWidget->setCurrentIndex(2);
    }



    qDebug() << currIndex;

}

void WelcomePage::on_submitInSignIn_clicked()
{
    QString username = ui->usernameInSignIn->text();
    QString password = ui->passwordInSignIn->text();

    MyNetwork *myPost = new MyNetwork;
    myPost->setPost("action","signIn");
    myPost->setPost("username",username);
    myPost->setPost("password",password);

    connect(myPost, SIGNAL(donePost(MyNetwork *)),this,SLOT(enterMainWindow(MyNetwork *)));
    myPost->sendPost();

}

void WelcomePage::on_forgetPassword_2_clicked()
{
    ui->welcomeWidget->setCurrentIndex(3);
}

void WelcomePage::on_submitForgetPassword_clicked()
{
    QString email = ui->email->text();
    ui->Notifications->setText("An email will be sent to" + email);
}

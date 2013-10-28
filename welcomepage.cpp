#include "welcomepage.h"
#include "ui_welcomepage.h"
#include "mainwindow.h"
#include "mynetwork.h"

#include <iostream>
#include <string>
#include <QUrl>
#include <QDebug>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QApplication>

WelcomePage::WelcomePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WelcomePage)
{
    ui->setupUi(this);
    ui->forgetBox->hide();
    ui->createAnAccountBox->hide();

//    QString myNetworkStr(myPost->postData);
//    std::cout << "The response: " << myNetworkStr.toStdString() << std::endl;
}

WelcomePage::~WelcomePage()
{
    delete ui;
}

void WelcomePage::on_credits_clicked()
{
    ui->signInBox->hide();
    ui->forgetBox->hide();
    ui->createAnAccountBox->hide();

    ui->creditsBox->show();

    ui->creditsBox->setText("CS 340 Project Fall 2013<br/><br/><br/>Instructor:<br/> Luc Renambot <br/><br/><br/>Team Members:<br/>Bresia Prudente<br/>Saleha Amreen<br/>Andrey Melikhov<br/>Pongsit Twichpongtorn");
}

void WelcomePage::on_signIn_clicked()
{
    ui->creditsBox->hide();
    ui->forgetBox->hide();
    ui->createAnAccountBox->hide();

    ui->signInBox->show();
}


void WelcomePage::on_pushButton_clicked()
{
    QString username = ui->username->text();
    QString password = ui->password->text();

    MyNetwork *myPost = new MyNetwork;
    myPost->setPost("action","signIn");
    myPost->setPost("username",username);
    myPost->setPost("password",password);

    connect(myPost, SIGNAL(donePost(MyNetwork *)),this,SLOT(doThis1(MyNetwork *)));
    myPost->sendPost();
}

void WelcomePage::doThis1(MyNetwork *myPost){
    QString theResponse = myPost->theResponse;
    if(theResponse.compare("Good") == 0){
        this->hide();
        MainWindow mainWindow;
        //mainWindow.showInfo(responsStr);
        mainWindow.show();
        mainWindow.setFixedSize(mainWindow.size());
        mainWindow.exec();
    }else{
        ui->Notifications->setText("Username or password is not correct.");
    }
}

void WelcomePage::on_forgetPassword_clicked()
{
    ui->signInBox->hide();
    ui->creditsBox->hide();
    ui->createAnAccountBox->hide();

    ui->forgetBox->show();
}

void WelcomePage::on_createAnAccount_clicked()
{
    ui->signInBox->hide();
    ui->creditsBox->hide();
    ui->forgetBox->hide();

    ui->createAnAccountBox->show();
}

void WelcomePage::on_password_returnPressed()
{
    on_pushButton_clicked();
}

#include "welcomepage.h"
#include "ui_welcomepage.h"
#include "mainwindow.h"

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

void WelcomePage::MyPostRequest(const QString &auth,const QString &username,const QString &password)
{
    QUrl url("http://webservices.pongsit.com/cs340/index.php");
    QNetworkRequest request = QNetworkRequest(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QNetworkAccessManager * TheNetworkManager = new QNetworkAccessManager(this);

    QByteArray postData;
    postData.append("auth=").append(auth);
    postData.append("&").append("action=").append("signIn");
    postData.append("&").append("username=").append(username);
    postData.append("&").append("password=").append(password);

    connect(TheNetworkManager, SIGNAL(finished(QNetworkReply*)),this, SLOT(ReplyFinished(QNetworkReply *)));

    TheNetworkManager->post(request,postData);

}

void WelcomePage::ReplyFinished(QNetworkReply *reply)
{
    if(reply->error() == QNetworkReply::NoError){
        QByteArray response = reply->readAll();
        QString responsStr(response);
        //std::cout << "The response: " << responsStr.toStdString() << std::endl;
        if(responsStr.compare("Good") == 0){
            this->hide();
            MainWindow mainWindow;
            //mainWindow.showInfo(responsStr);
            mainWindow.show();
            mainWindow.setFixedSize(mainWindow.size());
            mainWindow.exec();
        }else{
            ui->Notifications->setText("Username or password is not correct.");
        }
    }else{
        ui->Notifications->setText("Cannot connect to the server. Please try again later.");
    }
}

void WelcomePage::on_pushButton_clicked()
{
    QString auth = "bsap";
    QString username = ui->username->text();
    QString password = ui->password->text();
    WelcomePage::MyPostRequest(auth,username,password);
    //std::cout << "The input: " << theText.toStdString() << std::endl;
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

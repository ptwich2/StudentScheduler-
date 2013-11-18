#include "myconnect.h"

#include <iostream>
#include <string>
#include <QUrl>
#include <QDebug>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QApplication>

MyConnect::MyConnect()
{
}

void MyConnect::MyPostRequest(const QString &name)
{
    QUrl url("http://webservices.pongsit.com/cs340/index.php");
    QNetworkRequest request = QNetworkRequest(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QNetworkAccessManager * TheNetworkManager = new QNetworkAccessManager(this);

    QByteArray postData;
    postData.append("auth").append("=").append(name);

    connect(TheNetworkManager, SIGNAL(finished(QNetworkReply*)),this, SLOT(replyFinished(QNetworkReply *)));

    TheNetworkManager->post(request,postData);

}

void MyConnect::replyFinished(QNetworkReply *reply)
{
//    QByteArray response = reply->readAll();
//    QString responsStr(response);
//    if(responsStr.compare("Good") == 0){
//        qDebug() << "The response: " << responsStr;
//        this->hide();
//        Page2 page2;
//        page2.setModal(true);
//        page2.showInfo(responsStr);
//        page2.exec();
//    }
}

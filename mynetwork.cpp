#include "mynetwork.h"

#include <iostream>
#include <string>
#include <QUrl>
#include <QDebug>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QApplication>

MyNetwork::MyNetwork()
{
    postData.append("auth=bsap");
    theResponse = "";
}

void MyNetwork::setPost(const QString &theKey,const QString &theValue)
{
    postData.append("&").append(theKey).append("=").append(theValue);
}

void MyNetwork::sendPost()
{
    QUrl url("http://webservices.pongsit.com/cs340/index.php");
    QNetworkRequest request = QNetworkRequest(url);
    //request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    request.setRawHeader("User-Agent", "Mozilla/5.0 (Windows NT 6.2; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/29.0.1547.2 Safari/537.36");
    QNetworkAccessManager * TheNetworkManager = new QNetworkAccessManager(this);
    connect(TheNetworkManager, SIGNAL(finished(QNetworkReply*)),this, SLOT(setResponse(QNetworkReply *)));
    //std::cout << "3: " << QString(postData).toStdString() << std::endl;
    TheNetworkManager->post(request,postData);
}

void MyNetwork::setResponse(QNetworkReply *reply)
{
    if(reply->error() == QNetworkReply::NoError){
        QByteArray response = reply->readAll();
        theResponse = response;
    }else{
        theResponse = "Cannot connect to the server.";
        qDebug() << reply->error();
    }
    emit donePost(this);
}


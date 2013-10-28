#ifndef MYNETWORK_H
#define MYNETWORK_H

#include <string>
#include <QNetworkReply>

class MyNetwork: public QObject
{
    Q_OBJECT

public:
    QByteArray postData;
    MyNetwork();
    void setPost(const QString &theKey,const QString &theValue);
    void sendPost();
    QString theResponse;
public slots:
    void setResponse(QNetworkReply *reply);
signals:
    QString donePost(MyNetwork *myPost);
};

#endif // MYNETWORK_H

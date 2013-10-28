#include "welcomepage.h"
#include <QApplication>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QDebug>

int main(int argc, char *argv[])
{
//    QString val;
//    QFile file;
//    file.setFileName("test.json");
//    file.open(QIODevice::ReadOnly | QIODevice::Text);
//    val = file.readAll();
//    file.close();
//    qWarning() << val;
//    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
//    QJsonObject sett2 = d.object();
//    QJsonValue value = sett2.value(QString("appName"));
//    qWarning() << value;
//    QJsonObject item = value.toObject();
//    qWarning() << "QJsonObject of description: " << item;

//    /* incase of string value get value and convert into string*/
//    qWarning() << "QJsonObject[appName] of description: " << item["description"];
//    QJsonValue subobj = item["description"];
//    qWarning() << subobj.toString();

//    /* incase of array get array and convert into string*/
//    qWarning() << "QJsonObject[appName] of value: " << item["imp"];
//    QJsonArray test = item["imp"].toArray();
//    qWarning() << test[1].toString();


    QApplication a(argc, argv);
    WelcomePage  w;
    w.show();
    w.setFixedSize(w.size());
    return a.exec();
}

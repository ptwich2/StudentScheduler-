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

    QApplication a(argc, argv);
    WelcomePage  w;
    w.show();
    w.setFixedSize(w.size());
    return a.exec();
}

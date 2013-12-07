#ifndef EVENT_H
#define EVENT_H

#include <QDialog>
#include "mynetwork.h"

namespace Ui {
class Event;
}

class Event : public QDialog
{
    Q_OBJECT

public:
    explicit Event(QWidget *parent = 0);

    void setClassID(QString u);
    QString classID;

    void setUserID(QString u);
    QString userID;


    ~Event();

private slots:
    void on_buttonBox_accepted();
    void sendEvent(MyNetwork *myPost);

private:
    Ui::Event *ui;
};

#endif // EVENT_H

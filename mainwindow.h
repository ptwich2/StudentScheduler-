#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QDateTime>
#include <QDialogButtonBox>
#include <QAbstractButton>

#include "mynetwork.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setHiUserText(QString hiText);
    void setUserID(QString u);
    QString userID;
    ~MainWindow();

private slots:
    void on_createButton_clicked();
    void sendSemesterName(MyNetwork *myPost);
    //void on_semesterChanges_clicked(QAbstractButton *button);
    
    void resetBox();
    void okBox();
    void sendHolidayName(MyNetwork *myPost);

    void on_eventCalendar_clicked(const QDate &date);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

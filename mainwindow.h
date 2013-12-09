#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mynetwork.h"
#include <QDialog>
#include <QDateTime>
#include <QDialogButtonBox>
#include <QAbstractButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setHiUserText();
    void setUserID(QString u);
    void setGlobalObject(QByteArray u);
    void confirmationWindow(int i);
    QByteArray globalObjects;
    QString userID;
    ~MainWindow();

private slots:
    void on_createButton_clicked();

    void resetBox();
    void okBox();

    void updateGlobalObject(MyNetwork *myPost);

    void on_createCourse_clicked();

    void on_calculateGPA_clicked();


    void on_calendarWidget_clicked(const QDate &date);

    void on_eventText_linkActivated(const QString &link);


    void colorCodeCalendar();

    void calendarWidget();





    void on_goToSchedule_clicked();

    void on_goToCalculator_clicked();

    void on_goToProfile_clicked();

    void on_goToNewOrOld_clicked();



    void on_goToNewOrOldSemester_clicked();



    void on_goToCreateOrOldClass_clicked();

    void on_seeAll_clicked();

    void on_goToCalendar_clicked();

    void on_seeAllEvents_clicked();

    void on_buttonBox_accepted();

    void on_backButton_clicked();


    void on_newEvent_clicked();

    void on_buttonBox_clicked();

    void on_seeCalendar_clicked();

    void on_butonBox_clicked();

    void on_createEvent_clicked();

    void on_go_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

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
    void on_holidayChanges_clicked(QAbstractButton *button);

    void on_createCourse_clicked();

    void on_calculateGPA_clicked();


    void on_calendarWidget_clicked(const QDate &date);

    void on_eventText_linkActivated(const QString &link);

    void on_eventText_linkHovered(const QString &link);

    void colorCodeCalendar();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

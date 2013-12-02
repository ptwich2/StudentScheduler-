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
<<<<<<< HEAD
    void sendClassName(MyNetwork *myPost);
    void on_holidayChanges_clicked(QAbstractButton *button);

    void on_createCourse_clicked();

    void on_pushButton_2_clicked();

    void on_calculateGPA_clicked();

    void on_calendarWidget_activated(const QDate &date);
=======
>>>>>>> a98cab4d496820da8cd161e91a9608171486ca40

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

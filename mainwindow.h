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
    ~MainWindow();

private slots:
    void createButton();
    void sendSemesterName(MyNetwork *myPost);
    //void on_semesterChanges_clicked(QAbstractButton *button);
    
    void resetBox();
    void okBox();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

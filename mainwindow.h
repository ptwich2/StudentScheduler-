#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
    ~MainWindow();

private slots:
    void on_createButton_click();
    //void dateStart();
    //void dateEnd();
    //void nameSemesterEdit();
    
    void resetBox();
    void okBox();

    void on_submit_clicked();

    void on_holidayChanges_customContextMenuRequested(const QPoint &pos);

    void on_createButton_clicked();

    void on_createSemester_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

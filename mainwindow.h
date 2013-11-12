#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
<<<<<<< HEAD
=======
#include <QDateTime>
>>>>>>> feature/bresia_branch

namespace Ui {
class MainWindow;
}

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
<<<<<<< HEAD
    void setHiUserText(QString hiText);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();
=======
    ~MainWindow();

private slots:
    void on_createButton_click();
    //void dateStart();
    //void dateEnd();
    //void nameSemesterEdit();
>>>>>>> feature/bresia_branch

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QDateTime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_createButton_click();
    //void dateStart();
    //void dateEnd();
    //void nameSemesterEdit();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

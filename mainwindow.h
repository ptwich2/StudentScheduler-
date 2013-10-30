#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>

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
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

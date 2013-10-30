#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
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
    ~MainWindow();

private slots:
    void resetBox();
    void okBox();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

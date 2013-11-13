#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QDateTime>
using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


/*
 * When user clicks on the "Create" button, it should
 * send the information to the server and then show the client
 * a message saying, "Semester successfully created!"
 *
 * It should also print out a string that includes the information
 * which the user will send to the server.
 */
void MainWindow::on_createButton_click()
{
    ui->notificationSemester->setText("Semester successfully created!");

    //Print out the information that the user inputs
    //cout << dateStart;
    //cout << dateEnd;
    //cout << nameSemesterEdit;

}

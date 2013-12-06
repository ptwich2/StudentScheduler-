#include <confirmation.h>
#include <ui_confirmation.h>

Confirmation::Confirmation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Confirmation)
{
    ui->setupUi(this);
}

void Confirmation::createdAccount()
{
    ui->successfulAdd->setText("Account has been successfully created");
}

void Confirmation::createdSemester()
{
    ui->successfulAdd->setText("Semester has been successfully created");
}

void Confirmation::createdHoliday()
{
    ui->successfulAdd->setText("Holiday has been successfully created");
}

void Confirmation::createdClass()
{
    ui->successfulAdd->setText("Class has been successfully created");
}

void Confirmation::createdEvent()
{
    ui->successfulAdd->setText("Event has been successfully created");
}


Confirmation::~Confirmation()
{
    delete ui;
}

void Confirmation::on_continueButton_clicked()
{
    this->hide();
}

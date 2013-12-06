#ifndef CONFIRMATION_H
#define CONFIRMATION_H

#include <QDialog>

namespace Ui {
class Confirmation;
}

class Confirmation : public QDialog
{
    Q_OBJECT

public:
    explicit Confirmation(QWidget *parent = 0);

    void createdAccount();
    void createdSemester();
    void createdHoliday();
    void createdClass();
    void createdEvent();

    ~Confirmation();

private slots:
    void on_continueButton_clicked();


private:
    Ui::Confirmation *ui;
};


#endif // CONFIRMATION_H

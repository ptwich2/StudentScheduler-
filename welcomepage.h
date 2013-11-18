#ifndef WELCOMEPAGE_H
#define WELCOMEPAGE_H

#include <QDialog>

#include <string>
#include <QNetworkReply>

#include "mynetwork.h"

namespace Ui {
class WelcomePage;
}

class WelcomePage : public QDialog
{
    Q_OBJECT

public:
    explicit WelcomePage(QWidget *parent = 0);
    ~WelcomePage();

private slots:
    void on_credits_clicked();

    void on_signIn_clicked();

    void on_pushButton_clicked();

    void on_forgetPassword_clicked();

    void on_createAnAccount_clicked();

    void on_password_returnPressed();

    void doThis1(MyNetwork *myPost);
    void doThis2(MyNetwork *myPost);
    void on_submitInCreateAcc_clicked();

private:
    Ui::WelcomePage *ui;
};

#endif // WELCOMEPAGE_H

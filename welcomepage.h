#ifndef WELCOMEPAGE_H
#define WELCOMEPAGE_H

#include <QDialog>

#include <string>
#include <QNetworkReply>

namespace Ui {
class WelcomePage;
}

class WelcomePage : public QDialog
{
    Q_OBJECT

public:
    explicit WelcomePage(QWidget *parent = 0);
    void MyPostRequest(const QString &auth,const QString &username,const QString &password);
    ~WelcomePage();

private slots:
    void on_credits_clicked();

    void on_signIn_clicked();

    void ReplyFinished(QNetworkReply *reply);

    void on_pushButton_clicked();

    void on_forgetPassword_clicked();

    void on_createAnAccount_clicked();

    void on_password_returnPressed();

private:
    Ui::WelcomePage *ui;
};

#endif // WELCOMEPAGE_H

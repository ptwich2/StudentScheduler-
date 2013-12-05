/********************************************************************************
** Form generated from reading UI file 'welcomepage.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOMEPAGE_H
#define UI_WELCOMEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_WelcomePage
{
public:
    QLabel *label_3;
    QPushButton *credits;
    QLabel *creditsBox;
    QLabel *label_2;
    QPushButton *forgetPassword;
    QPushButton *signIn;
    QPushButton *createAnAccount;
    QGroupBox *signInBox;
    QLabel *label_4;
    QPushButton *pushButton;
    QLabel *label_5;
    QLineEdit *username;
    QLineEdit *password;
    QGroupBox *forgetBox;
    QPushButton *submitForgetPassword;
    QLabel *label_9;
    QLineEdit *email;
    QGroupBox *createAnAccountBox;
    QLabel *label_8;
    QPushButton *submitInCreateAcc;
    QLabel *label_10;
    QLineEdit *usernameInCreateAcc;
    QLineEdit *password_3;
    QLineEdit *emailInCreateAcc;
    QLabel *label_11;
    QLabel *Notifications;

    void setupUi(QDialog *WelcomePage)
    {
        if (WelcomePage->objectName().isEmpty())
            WelcomePage->setObjectName(QStringLiteral("WelcomePage"));
        WelcomePage->resize(640, 480);
        label_3 = new QLabel(WelcomePage);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 80, 421, 31));
        QFont font;
        font.setPointSize(16);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        credits = new QPushButton(WelcomePage);
        credits->setObjectName(QStringLiteral("credits"));
        credits->setGeometry(QRect(440, 290, 151, 32));
        credits->setAutoDefault(false);
        creditsBox = new QLabel(WelcomePage);
        creditsBox->setObjectName(QStringLiteral("creditsBox"));
        creditsBox->setGeometry(QRect(40, 150, 371, 291));
        creditsBox->setFont(font);
        creditsBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_2 = new QLabel(WelcomePage);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 30, 371, 41));
        QFont font1;
        font1.setPointSize(30);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        forgetPassword = new QPushButton(WelcomePage);
        forgetPassword->setObjectName(QStringLiteral("forgetPassword"));
        forgetPassword->setGeometry(QRect(440, 240, 151, 32));
        forgetPassword->setAutoDefault(false);
        signIn = new QPushButton(WelcomePage);
        signIn->setObjectName(QStringLiteral("signIn"));
        signIn->setGeometry(QRect(440, 190, 151, 32));
        signIn->setAutoDefault(false);
        signIn->setDefault(false);
        createAnAccount = new QPushButton(WelcomePage);
        createAnAccount->setObjectName(QStringLiteral("createAnAccount"));
        createAnAccount->setGeometry(QRect(440, 140, 151, 32));
        createAnAccount->setAutoDefault(false);
        signInBox = new QGroupBox(WelcomePage);
        signInBox->setObjectName(QStringLiteral("signInBox"));
        signInBox->setGeometry(QRect(40, 140, 381, 301));
        label_4 = new QLabel(signInBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 100, 81, 16));
        label_4->setFont(font);
        pushButton = new QPushButton(signInBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(130, 150, 114, 32));
        pushButton->setAutoDefault(false);
        label_5 = new QLabel(signInBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 50, 81, 16));
        label_5->setFont(font);
        username = new QLineEdit(signInBox);
        username->setObjectName(QStringLiteral("username"));
        username->setGeometry(QRect(130, 50, 221, 21));
        password = new QLineEdit(signInBox);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(130, 100, 221, 21));
        password->setEchoMode(QLineEdit::Password);
        label_4->raise();
        pushButton->raise();
        label_5->raise();
        username->raise();
        password->raise();
        forgetBox = new QGroupBox(WelcomePage);
        forgetBox->setObjectName(QStringLiteral("forgetBox"));
        forgetBox->setGeometry(QRect(40, 140, 381, 301));
        submitForgetPassword = new QPushButton(forgetBox);
        submitForgetPassword->setObjectName(QStringLiteral("submitForgetPassword"));
        submitForgetPassword->setGeometry(QRect(130, 100, 114, 32));
        submitForgetPassword->setAutoDefault(false);
        label_9 = new QLabel(forgetBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 50, 81, 16));
        label_9->setFont(font);
        email = new QLineEdit(forgetBox);
        email->setObjectName(QStringLiteral("email"));
        email->setGeometry(QRect(130, 50, 221, 21));
        submitForgetPassword->raise();
        label_9->raise();
        email->raise();
        createAnAccountBox = new QGroupBox(WelcomePage);
        createAnAccountBox->setObjectName(QStringLiteral("createAnAccountBox"));
        createAnAccountBox->setGeometry(QRect(40, 140, 381, 301));
        label_8 = new QLabel(createAnAccountBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 100, 81, 16));
        label_8->setFont(font);
        submitInCreateAcc = new QPushButton(createAnAccountBox);
        submitInCreateAcc->setObjectName(QStringLiteral("submitInCreateAcc"));
        submitInCreateAcc->setGeometry(QRect(130, 190, 110, 32));
        submitInCreateAcc->setAutoDefault(false);
        label_10 = new QLabel(createAnAccountBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(20, 50, 81, 16));
        label_10->setFont(font);
        usernameInCreateAcc = new QLineEdit(createAnAccountBox);
        usernameInCreateAcc->setObjectName(QStringLiteral("usernameInCreateAcc"));
        usernameInCreateAcc->setGeometry(QRect(130, 50, 221, 21));
        password_3 = new QLineEdit(createAnAccountBox);
        password_3->setObjectName(QStringLiteral("password_3"));
        password_3->setGeometry(QRect(130, 100, 221, 21));
        password_3->setEchoMode(QLineEdit::Password);
        emailInCreateAcc = new QLineEdit(createAnAccountBox);
        emailInCreateAcc->setObjectName(QStringLiteral("emailInCreateAcc"));
        emailInCreateAcc->setGeometry(QRect(130, 150, 221, 21));
        emailInCreateAcc->setEchoMode(QLineEdit::Normal);
        label_11 = new QLabel(createAnAccountBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(20, 150, 81, 16));
        label_11->setFont(font);
        Notifications = new QLabel(WelcomePage);
        Notifications->setObjectName(QStringLiteral("Notifications"));
        Notifications->setGeometry(QRect(50, 380, 361, 20));
        Notifications->setFont(font);
        Notifications->setAlignment(Qt::AlignCenter);
        label_3->raise();
        credits->raise();
        creditsBox->raise();
        label_2->raise();
        forgetPassword->raise();
        signIn->raise();
        createAnAccount->raise();
        createAnAccountBox->raise();
        forgetBox->raise();
        signInBox->raise();
        Notifications->raise();

        retranslateUi(WelcomePage);

        QMetaObject::connectSlotsByName(WelcomePage);
    } // setupUi

    void retranslateUi(QDialog *WelcomePage)
    {
        WelcomePage->setWindowTitle(QApplication::translate("WelcomePage", "Scheduler", 0));
        label_3->setText(QApplication::translate("WelcomePage", "The app designed by students for students.", 0));
        credits->setText(QApplication::translate("WelcomePage", "Credits", 0));
        creditsBox->setText(QApplication::translate("WelcomePage", "<html><head/><body><p><br/></p></body></html>", 0));
        label_2->setText(QApplication::translate("WelcomePage", "Welcome to Scheduler", 0));
        forgetPassword->setText(QApplication::translate("WelcomePage", "Forget Password", 0));
        signIn->setText(QApplication::translate("WelcomePage", "Sign In", 0));
        createAnAccount->setText(QApplication::translate("WelcomePage", "Create an account", 0));
        signInBox->setTitle(QString());
        label_4->setText(QApplication::translate("WelcomePage", "Password", 0));
        pushButton->setText(QApplication::translate("WelcomePage", "Submit", 0));
        label_5->setText(QApplication::translate("WelcomePage", "Username", 0));
        forgetBox->setTitle(QString());
        submitForgetPassword->setText(QApplication::translate("WelcomePage", "Submit", 0));
        label_9->setText(QApplication::translate("WelcomePage", "Email", 0));
        createAnAccountBox->setTitle(QString());
        label_8->setText(QApplication::translate("WelcomePage", "Password", 0));
        submitInCreateAcc->setText(QApplication::translate("WelcomePage", "Submit", 0));
        label_10->setText(QApplication::translate("WelcomePage", "Username", 0));
        label_11->setText(QApplication::translate("WelcomePage", "Email", 0));
        Notifications->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WelcomePage: public Ui_WelcomePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOMEPAGE_H

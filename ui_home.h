/********************************************************************************
** Form generated from reading UI file 'home.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOME_H
#define UI_HOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Home
{
public:
    QWidget *centralWidget;
    QTabWidget *content;
    QWidget *HomeTab;
    QLabel *label;
    QWidget *tab;
    QLabel *label_4;
    QWidget *LogInTab;
    QLabel *profileInfo;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Home)
    {
        if (Home->objectName().isEmpty())
            Home->setObjectName(QStringLiteral("Home"));
        Home->resize(640, 480);
        centralWidget = new QWidget(Home);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        content = new QTabWidget(centralWidget);
        content->setObjectName(QStringLiteral("content"));
        content->setGeometry(QRect(10, 10, 621, 441));
        HomeTab = new QWidget();
        HomeTab->setObjectName(QStringLiteral("HomeTab"));
        HomeTab->setCursor(QCursor(Qt::ArrowCursor));
        label = new QLabel(HomeTab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 50, 611, 81));
        QFont font;
        font.setPointSize(30);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        content->addTab(HomeTab, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 150, 611, 71));
        label_4->setAlignment(Qt::AlignCenter);
        content->addTab(tab, QString());
        LogInTab = new QWidget();
        LogInTab->setObjectName(QStringLiteral("LogInTab"));
        LogInTab->setEnabled(false);
        profileInfo = new QLabel(LogInTab);
        profileInfo->setObjectName(QStringLiteral("profileInfo"));
        profileInfo->setGeometry(QRect(50, 70, 541, 291));
        profileInfo->setAutoFillBackground(false);
        profileInfo->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        content->addTab(LogInTab, QString());
        Home->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Home);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Home->setStatusBar(statusBar);

        retranslateUi(Home);

        content->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Home);
    } // setupUi

    void retranslateUi(QMainWindow *Home)
    {
        Home->setWindowTitle(QApplication::translate("Home", "Home", 0));
#ifndef QT_NO_WHATSTHIS
        HomeTab->setWhatsThis(QApplication::translate("Home", "<html><head/><body><p>This is the first tab.</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        label->setText(QApplication::translate("Home", "Welcome to Scheduler", 0));
        content->setTabText(content->indexOf(HomeTab), QApplication::translate("Home", "Home", 0));
        label_4->setText(QApplication::translate("Home", "The app designed by students for students like you.", 0));
        content->setTabText(content->indexOf(tab), QApplication::translate("Home", "Page", 0));
        profileInfo->setText(QString());
        content->setTabText(content->indexOf(LogInTab), QApplication::translate("Home", "Log In", 0));
    } // retranslateUi

};

namespace Ui {
    class Home: public Ui_Home {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOME_H

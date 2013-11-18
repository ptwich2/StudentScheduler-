/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWebKitWidgets/QWebView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QTabWidget *tabWidget;
    QWidget *homeTab;
    QLabel *hiUser;
    QWidget *addNew;
    QToolBox *toolBox;
    QWidget *addSemester;
    QFormLayout *formLayout_3;
    QLabel *startDate;
    QDateEdit *dateStart;
    QLabel *endDate;
    QDateEdit *dateEnd;
    QLabel *semesterName;
    QLineEdit *semesterNameEdit;
    QLabel *notificationSemester;
    QPushButton *createSemester;
    QWidget *addHolidays;
    QFormLayout *formLayout_2;
    QLabel *label_5;
    QLineEdit *holidayName;
    QLabel *label_2;
    QDateEdit *holidayStart;
    QLabel *label_3;
    QDateEdit *holidayEnd;
    QLabel *label_4;
    QTextEdit *holidayComments;
    QDialogButtonBox *holidayChanges;
    QWidget *courseTab;
    QPushButton *pushButton_2;
    QToolBox *toolBox_2;
    QWidget *course;
    QFormLayout *formLayout_8;
    QLabel *label_19;
    QLineEdit *cName;
    QLabel *label_20;
    QComboBox *cType;
    QWidget *days;
    QFormLayout *formLayout_7;
    QCheckBox *mon;
    QCheckBox *tue;
    QCheckBox *wed;
    QCheckBox *thur;
    QCheckBox *fri;
    QCheckBox *sat;
    QCheckBox *sun;
    QWidget *timings;
    QTimeEdit *eTime;
    QTimeEdit *sTime;
    QLabel *label_17;
    QLabel *label_18;
    QPushButton *createCourse;
    QWidget *tab;
    QWebView *webView;
    QWidget *profileTab;
    QLabel *profileMainText;
    QPushButton *pushButton;

    void setupUi(QDialog *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(900, 506);
        MainWindow->setSizeGripEnabled(false);
        MainWindow->setModal(false);
        tabWidget = new QTabWidget(MainWindow);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 20, 861, 461));
        QFont font;
        font.setPointSize(13);
        tabWidget->setFont(font);
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        homeTab = new QWidget();
        homeTab->setObjectName(QStringLiteral("homeTab"));
        hiUser = new QLabel(homeTab);
        hiUser->setObjectName(QStringLiteral("hiUser"));
        hiUser->setGeometry(QRect(20, 20, 501, 121));
        tabWidget->addTab(homeTab, QString());
        addNew = new QWidget();
        addNew->setObjectName(QStringLiteral("addNew"));
        toolBox = new QToolBox(addNew);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setGeometry(QRect(20, 20, 821, 301));
        addSemester = new QWidget();
        addSemester->setObjectName(QStringLiteral("addSemester"));
        addSemester->setGeometry(QRect(0, 0, 821, 231));
        formLayout_3 = new QFormLayout(addSemester);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        startDate = new QLabel(addSemester);
        startDate->setObjectName(QStringLiteral("startDate"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, startDate);

        dateStart = new QDateEdit(addSemester);
        dateStart->setObjectName(QStringLiteral("dateStart"));
        dateStart->setDateTime(QDateTime(QDate(2013, 1, 1), QTime(0, 0, 0)));
        dateStart->setCalendarPopup(true);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, dateStart);

        endDate = new QLabel(addSemester);
        endDate->setObjectName(QStringLiteral("endDate"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, endDate);

        dateEnd = new QDateEdit(addSemester);
        dateEnd->setObjectName(QStringLiteral("dateEnd"));
        dateEnd->setDateTime(QDateTime(QDate(2013, 1, 1), QTime(0, 0, 0)));
        dateEnd->setCalendarPopup(true);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, dateEnd);

        semesterName = new QLabel(addSemester);
        semesterName->setObjectName(QStringLiteral("semesterName"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, semesterName);

        semesterNameEdit = new QLineEdit(addSemester);
        semesterNameEdit->setObjectName(QStringLiteral("semesterNameEdit"));
        semesterNameEdit->setAutoFillBackground(false);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, semesterNameEdit);

        notificationSemester = new QLabel(addSemester);
        notificationSemester->setObjectName(QStringLiteral("notificationSemester"));

        formLayout_3->setWidget(4, QFormLayout::SpanningRole, notificationSemester);

        createSemester = new QPushButton(addSemester);
        createSemester->setObjectName(QStringLiteral("createSemester"));

        formLayout_3->setWidget(3, QFormLayout::FieldRole, createSemester);

        toolBox->addItem(addSemester, QStringLiteral("Add New Semester"));
        addHolidays = new QWidget();
        addHolidays->setObjectName(QStringLiteral("addHolidays"));
        addHolidays->setGeometry(QRect(0, 0, 239, 223));
        formLayout_2 = new QFormLayout(addHolidays);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_5 = new QLabel(addHolidays);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_5);

        holidayName = new QLineEdit(addHolidays);
        holidayName->setObjectName(QStringLiteral("holidayName"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, holidayName);

        label_2 = new QLabel(addHolidays);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_2);

        holidayStart = new QDateEdit(addHolidays);
        holidayStart->setObjectName(QStringLiteral("holidayStart"));
        holidayStart->setDateTime(QDateTime(QDate(2013, 1, 1), QTime(0, 0, 0)));
        holidayStart->setMinimumDateTime(QDateTime(QDate(1752, 9, 14), QTime(0, 0, 0)));
        holidayStart->setCalendarPopup(true);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, holidayStart);

        label_3 = new QLabel(addHolidays);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_3);

        holidayEnd = new QDateEdit(addHolidays);
        holidayEnd->setObjectName(QStringLiteral("holidayEnd"));
        holidayEnd->setDateTime(QDateTime(QDate(2013, 1, 1), QTime(0, 0, 0)));
        holidayEnd->setCalendarPopup(true);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, holidayEnd);

        label_4 = new QLabel(addHolidays);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_4);

        holidayComments = new QTextEdit(addHolidays);
        holidayComments->setObjectName(QStringLiteral("holidayComments"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, holidayComments);

        holidayChanges = new QDialogButtonBox(addHolidays);
        holidayChanges->setObjectName(QStringLiteral("holidayChanges"));
        holidayChanges->setStandardButtons(QDialogButtonBox::Ok|QDialogButtonBox::Reset);
        holidayChanges->setCenterButtons(true);

        formLayout_2->setWidget(4, QFormLayout::SpanningRole, holidayChanges);

        toolBox->addItem(addHolidays, QStringLiteral("Add New Holidays"));
        tabWidget->addTab(addNew, QString());
        courseTab = new QWidget();
        courseTab->setObjectName(QStringLiteral("courseTab"));
        pushButton_2 = new QPushButton(courseTab);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(40, 20, 91, 41));
        toolBox_2 = new QToolBox(courseTab);
        toolBox_2->setObjectName(QStringLiteral("toolBox_2"));
        toolBox_2->setGeometry(QRect(40, 20, 771, 341));
        course = new QWidget();
        course->setObjectName(QStringLiteral("course"));
        course->setGeometry(QRect(0, 0, 228, 96));
        formLayout_8 = new QFormLayout(course);
        formLayout_8->setObjectName(QStringLiteral("formLayout_8"));
        formLayout_8->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_19 = new QLabel(course);
        label_19->setObjectName(QStringLiteral("label_19"));

        formLayout_8->setWidget(3, QFormLayout::LabelRole, label_19);

        cName = new QLineEdit(course);
        cName->setObjectName(QStringLiteral("cName"));

        formLayout_8->setWidget(3, QFormLayout::FieldRole, cName);

        label_20 = new QLabel(course);
        label_20->setObjectName(QStringLiteral("label_20"));

        formLayout_8->setWidget(4, QFormLayout::LabelRole, label_20);

        cType = new QComboBox(course);
        cType->setObjectName(QStringLiteral("cType"));

        formLayout_8->setWidget(4, QFormLayout::FieldRole, cType);

        toolBox_2->addItem(course, QStringLiteral("Course"));
        days = new QWidget();
        days->setObjectName(QStringLiteral("days"));
        days->setGeometry(QRect(0, 0, 131, 229));
        formLayout_7 = new QFormLayout(days);
        formLayout_7->setObjectName(QStringLiteral("formLayout_7"));
        mon = new QCheckBox(days);
        mon->setObjectName(QStringLiteral("mon"));

        formLayout_7->setWidget(0, QFormLayout::LabelRole, mon);

        tue = new QCheckBox(days);
        tue->setObjectName(QStringLiteral("tue"));

        formLayout_7->setWidget(1, QFormLayout::LabelRole, tue);

        wed = new QCheckBox(days);
        wed->setObjectName(QStringLiteral("wed"));

        formLayout_7->setWidget(2, QFormLayout::LabelRole, wed);

        thur = new QCheckBox(days);
        thur->setObjectName(QStringLiteral("thur"));

        formLayout_7->setWidget(3, QFormLayout::LabelRole, thur);

        fri = new QCheckBox(days);
        fri->setObjectName(QStringLiteral("fri"));

        formLayout_7->setWidget(4, QFormLayout::LabelRole, fri);

        sat = new QCheckBox(days);
        sat->setObjectName(QStringLiteral("sat"));

        formLayout_7->setWidget(5, QFormLayout::LabelRole, sat);

        sun = new QCheckBox(days);
        sun->setObjectName(QStringLiteral("sun"));

        formLayout_7->setWidget(6, QFormLayout::LabelRole, sun);

        toolBox_2->addItem(days, QStringLiteral("Days"));
        timings = new QWidget();
        timings->setObjectName(QStringLiteral("timings"));
        timings->setGeometry(QRect(0, 0, 771, 236));
        eTime = new QTimeEdit(timings);
        eTime->setObjectName(QStringLiteral("eTime"));
        eTime->setGeometry(QRect(100, 50, 250, 27));
        sTime = new QTimeEdit(timings);
        sTime->setObjectName(QStringLiteral("sTime"));
        sTime->setGeometry(QRect(100, 10, 250, 27));
        label_17 = new QLabel(timings);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(10, 10, 81, 16));
        label_18 = new QLabel(timings);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(10, 40, 81, 16));
        createCourse = new QPushButton(timings);
        createCourse->setObjectName(QStringLiteral("createCourse"));
        createCourse->setGeometry(QRect(350, 150, 250, 29));
        toolBox_2->addItem(timings, QStringLiteral("Timings"));
        tabWidget->addTab(courseTab, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        webView = new QWebView(tab);
        webView->setObjectName(QStringLiteral("webView"));
        webView->setGeometry(QRect(110, 20, 441, 311));
        webView->setUrl(QUrl(QStringLiteral("https://mail.google.com/intl/en/mail/help/about.html")));
        tabWidget->addTab(tab, QString());
        profileTab = new QWidget();
        profileTab->setObjectName(QStringLiteral("profileTab"));
        profileMainText = new QLabel(profileTab);
        profileMainText->setObjectName(QStringLiteral("profileMainText"));
        profileMainText->setGeometry(QRect(30, 30, 791, 331));
        QFont font1;
        font1.setPointSize(16);
        profileMainText->setFont(font1);
        profileMainText->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        pushButton = new QPushButton(profileTab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 380, 114, 32));
        pushButton->setAutoDefault(false);
        tabWidget->addTab(profileTab, QString());

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        toolBox->setCurrentIndex(0);
        toolBox_2->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QDialog *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Scheduler", 0));
        hiUser->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(homeTab), QApplication::translate("MainWindow", "Home", 0));
        startDate->setText(QApplication::translate("MainWindow", "Start Date", 0));
        endDate->setText(QApplication::translate("MainWindow", "End Date", 0));
        semesterName->setText(QApplication::translate("MainWindow", "Name of Semester", 0));
        notificationSemester->setText(QString());
        createSemester->setText(QApplication::translate("MainWindow", "Create", 0));
        toolBox->setItemText(toolBox->indexOf(addSemester), QApplication::translate("MainWindow", "Add New Semester", 0));
        label_5->setText(QApplication::translate("MainWindow", "Holiday Name", 0));
        label_2->setText(QApplication::translate("MainWindow", "Start:", 0));
        holidayStart->setDisplayFormat(QApplication::translate("MainWindow", "M/d/yy", 0));
        label_3->setText(QApplication::translate("MainWindow", "End:", 0));
        label_4->setText(QApplication::translate("MainWindow", "Comments", 0));
        toolBox->setItemText(toolBox->indexOf(addHolidays), QApplication::translate("MainWindow", "Add New Holidays", 0));
        tabWidget->setTabText(tabWidget->indexOf(addNew), QApplication::translate("MainWindow", "Add New", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "PushButton", 0));
        label_19->setText(QApplication::translate("MainWindow", "Course Name", 0));
        label_20->setText(QApplication::translate("MainWindow", "Couse Type", 0));
        cType->clear();
        cType->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Lecture", 0)
         << QApplication::translate("MainWindow", "Discussion", 0)
         << QApplication::translate("MainWindow", "Lab", 0)
        );
        toolBox_2->setItemText(toolBox_2->indexOf(course), QApplication::translate("MainWindow", "Course", 0));
        mon->setText(QApplication::translate("MainWindow", "Monday", 0));
        tue->setText(QApplication::translate("MainWindow", "Tuesday", 0));
        wed->setText(QApplication::translate("MainWindow", "Wednesday", 0));
        thur->setText(QApplication::translate("MainWindow", "Thursday", 0));
        fri->setText(QApplication::translate("MainWindow", "Friday", 0));
        sat->setText(QApplication::translate("MainWindow", "Saturday", 0));
        sun->setText(QApplication::translate("MainWindow", "Sunday", 0));
        toolBox_2->setItemText(toolBox_2->indexOf(days), QApplication::translate("MainWindow", "Days", 0));
        label_17->setText(QApplication::translate("MainWindow", "Start Time", 0));
        label_18->setText(QApplication::translate("MainWindow", "End Time", 0));
        createCourse->setText(QApplication::translate("MainWindow", "Create Course", 0));
        toolBox_2->setItemText(toolBox_2->indexOf(timings), QApplication::translate("MainWindow", "Timings", 0));
        tabWidget->setTabText(tabWidget->indexOf(courseTab), QApplication::translate("MainWindow", "Courses", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Communication", 0));
        profileMainText->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", "Edit", 0));
        tabWidget->setTabText(tabWidget->indexOf(profileTab), QApplication::translate("MainWindow", "Profile", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

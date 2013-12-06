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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
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
    QCalendarWidget *calendarWidget;
    QWidget *addNew;
    QToolBox *toolBox;
    QWidget *addSemester;
    QGridLayout *gridLayout_3;
    QLabel *startDate;
    QDateEdit *dateStart;
    QLabel *endDate;
    QDateEdit *dateEnd;
    QLabel *semesterName;
    QLineEdit *semesterNameEdit;
    QPushButton *createButton;
    QLabel *notificationSemester;
    QWidget *addHolidays;
    QFormLayout *formLayout_5;
    QLabel *label_5;
    QLineEdit *holidayName;
    QLabel *label_2;
    QDateEdit *holidayStart;
    QLabel *label_3;
    QDateEdit *holidayEnd;
    QLabel *label_4;
    QTextEdit *holidayComments;
    QDialogButtonBox *holidayChanges;
    QWidget *addNewClass;
    QToolBox *toolBox_2;
    QWidget *course;
    QFormLayout *formLayout_3;
    QLabel *label;
    QLineEdit *courseName;
    QLabel *label_6;
    QComboBox *courseType;
    QWidget *days;
    QFormLayout *formLayout_2;
    QCheckBox *monday;
    QCheckBox *tuesday;
    QCheckBox *wednesday;
    QCheckBox *thursday;
    QCheckBox *friday;
    QCheckBox *saturday;
    QCheckBox *sunday;
    QWidget *timings;
    QFormLayout *formLayout;
    QLabel *label_7;
    QTimeEdit *startTime;
    QLabel *label_8;
    QTimeEdit *endTime;
    QPushButton *createCourse;
    QLabel *notificationCreateCourse;
    QWidget *Classes;
    QCheckBox *sendNotification;
    QLabel *label_25;
    QLineEdit *eventName;
    QLabel *label_26;
    QTimeEdit *eventStartTime;
    QLabel *label_24;
    QTimeEdit *eventEndTime;
    QPushButton *createEvent;
    QTimeEdit *eventNotificationTime;
    QWidget *tab;
    QToolBox *classEvents;
    QWidget *page;
    QWidget *widget;
    QLabel *label_27;
    QWidget *GPA;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLineEdit *gradeA;
    QLineEdit *gradeB;
    QLineEdit *gradeC;
    QLineEdit *gradeD;
    QLineEdit *gradeF;
    QPushButton *calculateGPA;
    QLabel *label_12;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_13;
    QLabel *gpa;
    QWidget *profileTab;
    QLabel *profileMainText;
    QPushButton *pushButton;

    void setupUi(QDialog *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(762, 429);
        MainWindow->setSizeGripEnabled(false);
        MainWindow->setModal(false);
        tabWidget = new QTabWidget(MainWindow);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 701, 411));
        QFont font;
        font.setPointSize(13);
        tabWidget->setFont(font);
        homeTab = new QWidget();
        homeTab->setObjectName(QStringLiteral("homeTab"));
        calendarWidget = new QCalendarWidget(homeTab);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setGeometry(QRect(10, 10, 351, 311));
        tabWidget->addTab(homeTab, QString());
        addNew = new QWidget();
        addNew->setObjectName(QStringLiteral("addNew"));
        toolBox = new QToolBox(addNew);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setGeometry(QRect(20, 20, 661, 301));
        addSemester = new QWidget();
        addSemester->setObjectName(QStringLiteral("addSemester"));
        addSemester->setGeometry(QRect(0, 0, 661, 231));
        gridLayout_3 = new QGridLayout(addSemester);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        startDate = new QLabel(addSemester);
        startDate->setObjectName(QStringLiteral("startDate"));

        gridLayout_3->addWidget(startDate, 0, 0, 1, 1);

        dateStart = new QDateEdit(addSemester);
        dateStart->setObjectName(QStringLiteral("dateStart"));
        dateStart->setDateTime(QDateTime(QDate(2013, 1, 1), QTime(0, 0, 0)));
        dateStart->setCalendarPopup(true);

        gridLayout_3->addWidget(dateStart, 0, 1, 1, 1);

        endDate = new QLabel(addSemester);
        endDate->setObjectName(QStringLiteral("endDate"));

        gridLayout_3->addWidget(endDate, 1, 0, 1, 1);

        dateEnd = new QDateEdit(addSemester);
        dateEnd->setObjectName(QStringLiteral("dateEnd"));
        dateEnd->setDateTime(QDateTime(QDate(2013, 1, 1), QTime(0, 0, 0)));
        dateEnd->setCalendarPopup(true);

        gridLayout_3->addWidget(dateEnd, 1, 1, 1, 1);

        semesterName = new QLabel(addSemester);
        semesterName->setObjectName(QStringLiteral("semesterName"));

        gridLayout_3->addWidget(semesterName, 2, 0, 1, 1);

        semesterNameEdit = new QLineEdit(addSemester);
        semesterNameEdit->setObjectName(QStringLiteral("semesterNameEdit"));
        semesterNameEdit->setAutoFillBackground(false);

        gridLayout_3->addWidget(semesterNameEdit, 2, 1, 1, 1);

        createButton = new QPushButton(addSemester);
        createButton->setObjectName(QStringLiteral("createButton"));

        gridLayout_3->addWidget(createButton, 3, 1, 1, 1);

        notificationSemester = new QLabel(addSemester);
        notificationSemester->setObjectName(QStringLiteral("notificationSemester"));

        gridLayout_3->addWidget(notificationSemester, 4, 0, 1, 1);

        toolBox->addItem(addSemester, QStringLiteral("Add New Semester"));
        addHolidays = new QWidget();
        addHolidays->setObjectName(QStringLiteral("addHolidays"));
        addHolidays->setGeometry(QRect(0, 0, 661, 231));
        formLayout_5 = new QFormLayout(addHolidays);
        formLayout_5->setObjectName(QStringLiteral("formLayout_5"));
        label_5 = new QLabel(addHolidays);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, label_5);

        holidayName = new QLineEdit(addHolidays);
        holidayName->setObjectName(QStringLiteral("holidayName"));

        formLayout_5->setWidget(0, QFormLayout::FieldRole, holidayName);

        label_2 = new QLabel(addHolidays);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout_5->setWidget(1, QFormLayout::LabelRole, label_2);

        holidayStart = new QDateEdit(addHolidays);
        holidayStart->setObjectName(QStringLiteral("holidayStart"));
        holidayStart->setDateTime(QDateTime(QDate(2013, 1, 1), QTime(0, 0, 0)));
        holidayStart->setMinimumDateTime(QDateTime(QDate(1752, 9, 14), QTime(0, 0, 0)));
        holidayStart->setCalendarPopup(true);

        formLayout_5->setWidget(1, QFormLayout::FieldRole, holidayStart);

        label_3 = new QLabel(addHolidays);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout_5->setWidget(2, QFormLayout::LabelRole, label_3);

        holidayEnd = new QDateEdit(addHolidays);
        holidayEnd->setObjectName(QStringLiteral("holidayEnd"));
        holidayEnd->setDateTime(QDateTime(QDate(2013, 1, 1), QTime(0, 0, 0)));
        holidayEnd->setCalendarPopup(true);

        formLayout_5->setWidget(2, QFormLayout::FieldRole, holidayEnd);

        label_4 = new QLabel(addHolidays);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout_5->setWidget(3, QFormLayout::LabelRole, label_4);

        holidayComments = new QTextEdit(addHolidays);
        holidayComments->setObjectName(QStringLiteral("holidayComments"));

        formLayout_5->setWidget(3, QFormLayout::FieldRole, holidayComments);

        holidayChanges = new QDialogButtonBox(addHolidays);
        holidayChanges->setObjectName(QStringLiteral("holidayChanges"));
        holidayChanges->setStandardButtons(QDialogButtonBox::Ok|QDialogButtonBox::Reset);
        holidayChanges->setCenterButtons(true);

        formLayout_5->setWidget(4, QFormLayout::SpanningRole, holidayChanges);

        toolBox->addItem(addHolidays, QStringLiteral("Add New Holidays"));
        tabWidget->addTab(addNew, QString());
        addNewClass = new QWidget();
        addNewClass->setObjectName(QStringLiteral("addNewClass"));
        toolBox_2 = new QToolBox(addNewClass);
        toolBox_2->setObjectName(QStringLiteral("toolBox_2"));
        toolBox_2->setGeometry(QRect(10, 10, 701, 341));
        course = new QWidget();
        course->setObjectName(QStringLiteral("course"));
        course->setGeometry(QRect(0, 0, 228, 78));
        formLayout_3 = new QFormLayout(course);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        label = new QLabel(course);
        label->setObjectName(QStringLiteral("label"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label);

        courseName = new QLineEdit(course);
        courseName->setObjectName(QStringLiteral("courseName"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, courseName);

        label_6 = new QLabel(course);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_6);

        courseType = new QComboBox(course);
        courseType->setObjectName(QStringLiteral("courseType"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, courseType);

        toolBox_2->addItem(course, QStringLiteral("Course"));
        days = new QWidget();
        days->setObjectName(QStringLiteral("days"));
        days->setGeometry(QRect(0, 0, 131, 229));
        formLayout_2 = new QFormLayout(days);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        monday = new QCheckBox(days);
        monday->setObjectName(QStringLiteral("monday"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, monday);

        tuesday = new QCheckBox(days);
        tuesday->setObjectName(QStringLiteral("tuesday"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, tuesday);

        wednesday = new QCheckBox(days);
        wednesday->setObjectName(QStringLiteral("wednesday"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, wednesday);

        thursday = new QCheckBox(days);
        thursday->setObjectName(QStringLiteral("thursday"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, thursday);

        friday = new QCheckBox(days);
        friday->setObjectName(QStringLiteral("friday"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, friday);

        saturday = new QCheckBox(days);
        saturday->setObjectName(QStringLiteral("saturday"));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, saturday);

        sunday = new QCheckBox(days);
        sunday->setObjectName(QStringLiteral("sunday"));

        formLayout_2->setWidget(6, QFormLayout::LabelRole, sunday);

        toolBox_2->addItem(days, QStringLiteral("Days"));
        timings = new QWidget();
        timings->setObjectName(QStringLiteral("timings"));
        timings->setGeometry(QRect(0, 0, 701, 236));
        formLayout = new QFormLayout(timings);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_7 = new QLabel(timings);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_7);

        startTime = new QTimeEdit(timings);
        startTime->setObjectName(QStringLiteral("startTime"));

        formLayout->setWidget(0, QFormLayout::FieldRole, startTime);

        label_8 = new QLabel(timings);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_8);

        endTime = new QTimeEdit(timings);
        endTime->setObjectName(QStringLiteral("endTime"));

        formLayout->setWidget(1, QFormLayout::FieldRole, endTime);

        createCourse = new QPushButton(timings);
        createCourse->setObjectName(QStringLiteral("createCourse"));

        formLayout->setWidget(2, QFormLayout::FieldRole, createCourse);

        toolBox_2->addItem(timings, QStringLiteral("Timings"));
        notificationCreateCourse = new QLabel(addNewClass);
        notificationCreateCourse->setObjectName(QStringLiteral("notificationCreateCourse"));
        notificationCreateCourse->setGeometry(QRect(40, 390, 561, 16));
        tabWidget->addTab(addNewClass, QString());
        Classes = new QWidget();
        Classes->setObjectName(QStringLiteral("Classes"));
        sendNotification = new QCheckBox(Classes);
        sendNotification->setObjectName(QStringLiteral("sendNotification"));
        sendNotification->setGeometry(QRect(21, 161, 173, 25));
        label_25 = new QLabel(Classes);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(21, 72, 173, 27));
        eventName = new QLineEdit(Classes);
        eventName->setObjectName(QStringLiteral("eventName"));
        eventName->setGeometry(QRect(200, 28, 430, 27));
        label_26 = new QLabel(Classes);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(21, 116, 173, 27));
        eventStartTime = new QTimeEdit(Classes);
        eventStartTime->setObjectName(QStringLiteral("eventStartTime"));
        eventStartTime->setGeometry(QRect(200, 72, 430, 27));
        label_24 = new QLabel(Classes);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(21, 28, 173, 27));
        eventEndTime = new QTimeEdit(Classes);
        eventEndTime->setObjectName(QStringLiteral("eventEndTime"));
        eventEndTime->setGeometry(QRect(200, 116, 430, 27));
        createEvent = new QPushButton(Classes);
        createEvent->setObjectName(QStringLiteral("createEvent"));
        createEvent->setGeometry(QRect(21, 204, 173, 29));
        eventNotificationTime = new QTimeEdit(Classes);
        eventNotificationTime->setObjectName(QStringLiteral("eventNotificationTime"));
        eventNotificationTime->setGeometry(QRect(200, 160, 430, 27));
        tabWidget->addTab(Classes, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        classEvents = new QToolBox(tab);
        classEvents->setObjectName(QStringLiteral("classEvents"));
        classEvents->setGeometry(QRect(9, 36, 621, 311));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 621, 241));
        classEvents->addItem(page, QStringLiteral(""));
        widget = new QWidget();
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 100, 30));
        classEvents->addItem(widget, QStringLiteral(""));
        label_27 = new QLabel(tab);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(9, 9, 94, 21));
        tabWidget->addTab(tab, QString());
        GPA = new QWidget();
        GPA->setObjectName(QStringLiteral("GPA"));
        label_9 = new QLabel(GPA);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(9, 9, 694, 42));
        label_10 = new QLabel(GPA);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(9, 57, 52, 21));
        label_11 = new QLabel(GPA);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(67, 57, 84, 21));
        label_14 = new QLabel(GPA);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(9, 85, 16, 21));
        label_15 = new QLabel(GPA);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(9, 118, 16, 21));
        label_16 = new QLabel(GPA);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(9, 151, 16, 21));
        label_17 = new QLabel(GPA);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(9, 184, 16, 21));
        label_18 = new QLabel(GPA);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(9, 217, 16, 21));
        gradeA = new QLineEdit(GPA);
        gradeA->setObjectName(QStringLiteral("gradeA"));
        gradeA->setGeometry(QRect(67, 85, 167, 27));
        gradeB = new QLineEdit(GPA);
        gradeB->setObjectName(QStringLiteral("gradeB"));
        gradeB->setGeometry(QRect(67, 118, 167, 27));
        gradeC = new QLineEdit(GPA);
        gradeC->setObjectName(QStringLiteral("gradeC"));
        gradeC->setGeometry(QRect(67, 151, 167, 27));
        gradeD = new QLineEdit(GPA);
        gradeD->setObjectName(QStringLiteral("gradeD"));
        gradeD->setGeometry(QRect(67, 184, 167, 27));
        gradeF = new QLineEdit(GPA);
        gradeF->setObjectName(QStringLiteral("gradeF"));
        gradeF->setGeometry(QRect(67, 217, 167, 27));
        calculateGPA = new QPushButton(GPA);
        calculateGPA->setObjectName(QStringLiteral("calculateGPA"));
        calculateGPA->setGeometry(QRect(67, 250, 112, 29));
        label_12 = new QLabel(GPA);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(260, 60, 100, 21));
        label_19 = new QLabel(GPA);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(260, 88, 16, 21));
        label_20 = new QLabel(GPA);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(260, 121, 16, 21));
        label_21 = new QLabel(GPA);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(260, 154, 16, 21));
        label_22 = new QLabel(GPA);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(260, 187, 16, 21));
        label_23 = new QLabel(GPA);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(260, 220, 16, 21));
        label_13 = new QLabel(GPA);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(30, 300, 101, 31));
        gpa = new QLabel(GPA);
        gpa->setObjectName(QStringLiteral("gpa"));
        gpa->setGeometry(QRect(130, 310, 46, 13));
        tabWidget->addTab(GPA, QString());
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

        tabWidget->setCurrentIndex(6);
        toolBox->setCurrentIndex(1);
        toolBox_2->setCurrentIndex(2);
        classEvents->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QDialog *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Scheduler", 0));
        tabWidget->setTabText(tabWidget->indexOf(homeTab), QApplication::translate("MainWindow", "Home", 0));
        startDate->setText(QApplication::translate("MainWindow", "Start Date", 0));
        endDate->setText(QApplication::translate("MainWindow", "End Date", 0));
        semesterName->setText(QApplication::translate("MainWindow", "Name of Semester", 0));
        createButton->setText(QApplication::translate("MainWindow", "Create", 0));
        notificationSemester->setText(QString());
        toolBox->setItemText(toolBox->indexOf(addSemester), QApplication::translate("MainWindow", "Add New Semester", 0));
        label_5->setText(QApplication::translate("MainWindow", "Holiday Name", 0));
        label_2->setText(QApplication::translate("MainWindow", "Start:", 0));
        holidayStart->setDisplayFormat(QApplication::translate("MainWindow", "M/d/yy", 0));
        label_3->setText(QApplication::translate("MainWindow", "End:", 0));
        label_4->setText(QApplication::translate("MainWindow", "Comments", 0));
        toolBox->setItemText(toolBox->indexOf(addHolidays), QApplication::translate("MainWindow", "Add New Holidays", 0));
        tabWidget->setTabText(tabWidget->indexOf(addNew), QApplication::translate("MainWindow", "Add New", 0));
        label->setText(QApplication::translate("MainWindow", "Course Name", 0));
        label_6->setText(QApplication::translate("MainWindow", "Course Type", 0));
        courseType->clear();
        courseType->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Lecture", 0)
         << QApplication::translate("MainWindow", "Discussion", 0)
         << QApplication::translate("MainWindow", "Lab", 0)
        );
        toolBox_2->setItemText(toolBox_2->indexOf(course), QApplication::translate("MainWindow", "Course", 0));
        monday->setText(QApplication::translate("MainWindow", "Monday", 0));
        tuesday->setText(QApplication::translate("MainWindow", "Tuesday", 0));
        wednesday->setText(QApplication::translate("MainWindow", "Wednesday", 0));
        thursday->setText(QApplication::translate("MainWindow", "Thursdaty", 0));
        friday->setText(QApplication::translate("MainWindow", "Friday", 0));
        saturday->setText(QApplication::translate("MainWindow", "Saturday", 0));
        sunday->setText(QApplication::translate("MainWindow", "Sunday", 0));
        toolBox_2->setItemText(toolBox_2->indexOf(days), QApplication::translate("MainWindow", "Days", 0));
        label_7->setText(QApplication::translate("MainWindow", "Start Time", 0));
        label_8->setText(QApplication::translate("MainWindow", "End Time", 0));
        createCourse->setText(QApplication::translate("MainWindow", "Create Course", 0));
        toolBox_2->setItemText(toolBox_2->indexOf(timings), QApplication::translate("MainWindow", "Timings", 0));
        notificationCreateCourse->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(addNewClass), QApplication::translate("MainWindow", "Add New Class", 0));
        sendNotification->setText(QApplication::translate("MainWindow", "Send Notification at ", 0));
        label_25->setText(QApplication::translate("MainWindow", "Start Time", 0));
        label_26->setText(QApplication::translate("MainWindow", "End Time", 0));
        label_24->setText(QApplication::translate("MainWindow", "Event Name", 0));
        createEvent->setText(QApplication::translate("MainWindow", "Create Event", 0));
        tabWidget->setTabText(tabWidget->indexOf(Classes), QApplication::translate("MainWindow", "Classes", 0));
        classEvents->setItemText(classEvents->indexOf(page), QString());
        classEvents->setItemText(classEvents->indexOf(widget), QString());
        label_27->setText(QApplication::translate("MainWindow", "Class Events", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Events", 0));
        label_9->setText(QApplication::translate("MainWindow", "To use the GPA calculator, total the number of hours you received for each letter grade.\n"
"For example, if you had three 3 hour courses of A you would enter 9 in the total hours column", 0));
        label_10->setText(QApplication::translate("MainWindow", "Grades", 0));
        label_11->setText(QApplication::translate("MainWindow", "Total Hours", 0));
        label_14->setText(QApplication::translate("MainWindow", "A", 0));
        label_15->setText(QApplication::translate("MainWindow", "B", 0));
        label_16->setText(QApplication::translate("MainWindow", "C", 0));
        label_17->setText(QApplication::translate("MainWindow", "D", 0));
        label_18->setText(QApplication::translate("MainWindow", "F", 0));
        calculateGPA->setText(QApplication::translate("MainWindow", "Calculate GPA", 0));
        label_12->setText(QApplication::translate("MainWindow", "Grade Weight", 0));
        label_19->setText(QApplication::translate("MainWindow", "4", 0));
        label_20->setText(QApplication::translate("MainWindow", "3", 0));
        label_21->setText(QApplication::translate("MainWindow", "2", 0));
        label_22->setText(QApplication::translate("MainWindow", "1", 0));
        label_23->setText(QApplication::translate("MainWindow", "0", 0));
        label_13->setText(QApplication::translate("MainWindow", "Your GPA is:", 0));
        gpa->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(GPA), QApplication::translate("MainWindow", "GPA Calculator", 0));
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

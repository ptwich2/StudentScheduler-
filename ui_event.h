/********************************************************************************
** Form generated from reading UI file 'event.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENT_H
#define UI_EVENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_Event
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *eventMainText;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *eventName;
    QLabel *label_4;
    QDateEdit *eventDateEdit;
    QTimeEdit *eventTimeEdit;
    QLabel *label_5;
    QSpinBox *notifyH;
    QSpinBox *notifyM;
    QLabel *label_6;
    QLabel *label_7;

    void setupUi(QDialog *Event)
    {
        if (Event->objectName().isEmpty())
            Event->setObjectName(QStringLiteral("Event"));
        Event->resize(363, 280);
        buttonBox = new QDialogButtonBox(Event);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(20, 230, 301, 32));
        buttonBox->setFocusPolicy(Qt::NoFocus);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        eventMainText = new QLabel(Event);
        eventMainText->setObjectName(QStringLiteral("eventMainText"));
        eventMainText->setGeometry(QRect(20, 10, 281, 41));
        QFont font;
        font.setPointSize(20);
        eventMainText->setFont(font);
        label_2 = new QLabel(Event);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 60, 51, 41));
        QFont font1;
        font1.setPointSize(16);
        label_2->setFont(font1);
        label_3 = new QLabel(Event);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 140, 51, 41));
        label_3->setFont(font1);
        eventName = new QLineEdit(Event);
        eventName->setObjectName(QStringLiteral("eventName"));
        eventName->setGeometry(QRect(80, 70, 201, 21));
        label_4 = new QLabel(Event);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 100, 51, 41));
        label_4->setFont(font1);
        eventDateEdit = new QDateEdit(Event);
        eventDateEdit->setObjectName(QStringLiteral("eventDateEdit"));
        eventDateEdit->setGeometry(QRect(80, 110, 110, 24));
        eventDateEdit->setFocusPolicy(Qt::NoFocus);
        eventDateEdit->setCalendarPopup(true);
        eventDateEdit->setCurrentSectionIndex(0);
        eventTimeEdit = new QTimeEdit(Event);
        eventTimeEdit->setObjectName(QStringLiteral("eventTimeEdit"));
        eventTimeEdit->setGeometry(QRect(80, 150, 118, 24));
        eventTimeEdit->setCalendarPopup(true);
        label_5 = new QLabel(Event);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 180, 51, 41));
        label_5->setFont(font1);
        notifyH = new QSpinBox(Event);
        notifyH->setObjectName(QStringLiteral("notifyH"));
        notifyH->setGeometry(QRect(80, 190, 49, 24));
        notifyM = new QSpinBox(Event);
        notifyM->setObjectName(QStringLiteral("notifyM"));
        notifyM->setGeometry(QRect(160, 190, 49, 24));
        label_6 = new QLabel(Event);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(140, 180, 16, 41));
        label_6->setFont(font1);
        label_7 = new QLabel(Event);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(220, 180, 111, 41));
        label_7->setFont(font1);

        retranslateUi(Event);
        QObject::connect(buttonBox, SIGNAL(accepted()), Event, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Event, SLOT(reject()));

        QMetaObject::connectSlotsByName(Event);
    } // setupUi

    void retranslateUi(QDialog *Event)
    {
        Event->setWindowTitle(QApplication::translate("Event", "Dialog", 0));
        eventMainText->setText(QApplication::translate("Event", "Add Event", 0));
        label_2->setText(QApplication::translate("Event", "Name", 0));
        label_3->setText(QApplication::translate("Event", "Time", 0));
        label_4->setText(QApplication::translate("Event", "Date", 0));
        label_5->setText(QApplication::translate("Event", "Notify", 0));
        label_6->setText(QApplication::translate("Event", "h", 0));
        label_7->setText(QApplication::translate("Event", "m    before", 0));
    } // retranslateUi

};

namespace Ui {
    class Event: public Ui_Event {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENT_H

/********************************************************************************
** Form generated from reading UI file 'lab11activity.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAB11ACTIVITY_H
#define UI_LAB11ACTIVITY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lab11Activity
{
public:
    QTextEdit *textEdit;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;

    void setupUi(QWidget *Lab11Activity)
    {
        if (Lab11Activity->objectName().isEmpty())
            Lab11Activity->setObjectName(QStringLiteral("Lab11Activity"));
        Lab11Activity->resize(454, 478);
        textEdit = new QTextEdit(Lab11Activity);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(30, 80, 391, 381));
        widget = new QWidget(Lab11Activity);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 40, 391, 20));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton = new QRadioButton(widget);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setChecked(true);

        horizontalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(widget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        horizontalLayout->addWidget(radioButton_2);

        radioButton->raise();
        radioButton_2->raise();
        radioButton->raise();
        textEdit->raise();

        retranslateUi(Lab11Activity);

        QMetaObject::connectSlotsByName(Lab11Activity);
    } // setupUi

    void retranslateUi(QWidget *Lab11Activity)
    {
        Lab11Activity->setWindowTitle(QApplication::translate("Lab11Activity", "Form", Q_NULLPTR));
        radioButton->setText(QApplication::translate("Lab11Activity", "Sorted", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("Lab11Activity", "Suffled", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Lab11Activity: public Ui_Lab11Activity {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAB11ACTIVITY_H

/********************************************************************************
** Form generated from reading UI file 'seeadoptionlist.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEEADOPTIONLIST_H
#define UI_SEEADOPTIONLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SeeAdoptionList
{
public:
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *csv_button;
    QPushButton *html_button;

    void setupUi(QWidget *SeeAdoptionList)
    {
        if (SeeAdoptionList->objectName().isEmpty())
            SeeAdoptionList->setObjectName(QStringLiteral("SeeAdoptionList"));
        SeeAdoptionList->resize(534, 304);
        label = new QLabel(SeeAdoptionList);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 40, 461, 20));
        widget = new QWidget(SeeAdoptionList);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 140, 491, 61));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        csv_button = new QPushButton(widget);
        csv_button->setObjectName(QStringLiteral("csv_button"));

        horizontalLayout->addWidget(csv_button);

        html_button = new QPushButton(widget);
        html_button->setObjectName(QStringLiteral("html_button"));

        horizontalLayout->addWidget(html_button);


        retranslateUi(SeeAdoptionList);

        QMetaObject::connectSlotsByName(SeeAdoptionList);
    } // setupUi

    void retranslateUi(QWidget *SeeAdoptionList)
    {
        SeeAdoptionList->setWindowTitle(QApplication::translate("SeeAdoptionList", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("SeeAdoptionList", "Choose the format that you would like to preview the adoption list in:", Q_NULLPTR));
        csv_button->setText(QApplication::translate("SeeAdoptionList", "CSV", Q_NULLPTR));
        html_button->setText(QApplication::translate("SeeAdoptionList", "HTML", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SeeAdoptionList: public Ui_SeeAdoptionList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEEADOPTIONLIST_H

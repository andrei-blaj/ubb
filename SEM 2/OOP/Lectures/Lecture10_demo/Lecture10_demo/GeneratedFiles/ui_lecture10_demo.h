/********************************************************************************
** Form generated from reading UI file 'lecture10_demo.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LECTURE10_DEMO_H
#define UI_LECTURE10_DEMO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lecture10_demoClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Lecture10_demoClass)
    {
        if (Lecture10_demoClass->objectName().isEmpty())
            Lecture10_demoClass->setObjectName(QStringLiteral("Lecture10_demoClass"));
        Lecture10_demoClass->resize(600, 400);
        menuBar = new QMenuBar(Lecture10_demoClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        Lecture10_demoClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Lecture10_demoClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Lecture10_demoClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Lecture10_demoClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Lecture10_demoClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Lecture10_demoClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Lecture10_demoClass->setStatusBar(statusBar);

        retranslateUi(Lecture10_demoClass);

        QMetaObject::connectSlotsByName(Lecture10_demoClass);
    } // setupUi

    void retranslateUi(QMainWindow *Lecture10_demoClass)
    {
        Lecture10_demoClass->setWindowTitle(QApplication::translate("Lecture10_demoClass", "Lecture10_demo", 0));
    } // retranslateUi

};

namespace Ui {
    class Lecture10_demoClass: public Ui_Lecture10_demoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LECTURE10_DEMO_H

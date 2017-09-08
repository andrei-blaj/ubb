/********************************************************************************
** Form generated from reading UI file 'lecture12_demo_observer.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LECTURE12_DEMO_OBSERVER_H
#define UI_LECTURE12_DEMO_OBSERVER_H

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

class Ui_Lecture12_demo_ObserverClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Lecture12_demo_ObserverClass)
    {
        if (Lecture12_demo_ObserverClass->objectName().isEmpty())
            Lecture12_demo_ObserverClass->setObjectName(QStringLiteral("Lecture12_demo_ObserverClass"));
        Lecture12_demo_ObserverClass->resize(600, 400);
        menuBar = new QMenuBar(Lecture12_demo_ObserverClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        Lecture12_demo_ObserverClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Lecture12_demo_ObserverClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Lecture12_demo_ObserverClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Lecture12_demo_ObserverClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Lecture12_demo_ObserverClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Lecture12_demo_ObserverClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Lecture12_demo_ObserverClass->setStatusBar(statusBar);

        retranslateUi(Lecture12_demo_ObserverClass);

        QMetaObject::connectSlotsByName(Lecture12_demo_ObserverClass);
    } // setupUi

    void retranslateUi(QMainWindow *Lecture12_demo_ObserverClass)
    {
        Lecture12_demo_ObserverClass->setWindowTitle(QApplication::translate("Lecture12_demo_ObserverClass", "Lecture12_demo_Observer", 0));
    } // retranslateUi

};

namespace Ui {
    class Lecture12_demo_ObserverClass: public Ui_Lecture12_demo_ObserverClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LECTURE12_DEMO_OBSERVER_H

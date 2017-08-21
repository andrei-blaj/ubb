/********************************************************************************
** Form generated from reading UI file 'lecture9_demo_widgets.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LECTURE9_DEMO_WIDGETS_H
#define UI_LECTURE9_DEMO_WIDGETS_H

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

class Ui_Lecture9_demo_widgetsClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Lecture9_demo_widgetsClass)
    {
        if (Lecture9_demo_widgetsClass->objectName().isEmpty())
            Lecture9_demo_widgetsClass->setObjectName(QStringLiteral("Lecture9_demo_widgetsClass"));
        Lecture9_demo_widgetsClass->resize(600, 400);
        menuBar = new QMenuBar(Lecture9_demo_widgetsClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        Lecture9_demo_widgetsClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Lecture9_demo_widgetsClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Lecture9_demo_widgetsClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Lecture9_demo_widgetsClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Lecture9_demo_widgetsClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Lecture9_demo_widgetsClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Lecture9_demo_widgetsClass->setStatusBar(statusBar);

        retranslateUi(Lecture9_demo_widgetsClass);

        QMetaObject::connectSlotsByName(Lecture9_demo_widgetsClass);
    } // setupUi

    void retranslateUi(QMainWindow *Lecture9_demo_widgetsClass)
    {
        Lecture9_demo_widgetsClass->setWindowTitle(QApplication::translate("Lecture9_demo_widgetsClass", "Lecture9_demo_widgets", 0));
    } // retranslateUi

};

namespace Ui {
    class Lecture9_demo_widgetsClass: public Ui_Lecture9_demo_widgetsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LECTURE9_DEMO_WIDGETS_H

/********************************************************************************
** Form generated from reading UI file 'lecture10_demo_notepad.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LECTURE10_DEMO_NOTEPAD_H
#define UI_LECTURE10_DEMO_NOTEPAD_H

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

class Ui_Lecture10_demo_NotepadClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Lecture10_demo_NotepadClass)
    {
        if (Lecture10_demo_NotepadClass->objectName().isEmpty())
            Lecture10_demo_NotepadClass->setObjectName(QStringLiteral("Lecture10_demo_NotepadClass"));
        Lecture10_demo_NotepadClass->resize(600, 400);
        menuBar = new QMenuBar(Lecture10_demo_NotepadClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        Lecture10_demo_NotepadClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Lecture10_demo_NotepadClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Lecture10_demo_NotepadClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Lecture10_demo_NotepadClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Lecture10_demo_NotepadClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Lecture10_demo_NotepadClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Lecture10_demo_NotepadClass->setStatusBar(statusBar);

        retranslateUi(Lecture10_demo_NotepadClass);

        QMetaObject::connectSlotsByName(Lecture10_demo_NotepadClass);
    } // setupUi

    void retranslateUi(QMainWindow *Lecture10_demo_NotepadClass)
    {
        Lecture10_demo_NotepadClass->setWindowTitle(QApplication::translate("Lecture10_demo_NotepadClass", "Lecture10_demo_Notepad", 0));
    } // retranslateUi

};

namespace Ui {
    class Lecture10_demo_NotepadClass: public Ui_Lecture10_demo_NotepadClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LECTURE10_DEMO_NOTEPAD_H

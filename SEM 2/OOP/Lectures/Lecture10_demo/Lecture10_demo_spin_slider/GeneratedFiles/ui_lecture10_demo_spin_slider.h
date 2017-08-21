/********************************************************************************
** Form generated from reading UI file 'lecture10_demo_spin_slider.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LECTURE10_DEMO_SPIN_SLIDER_H
#define UI_LECTURE10_DEMO_SPIN_SLIDER_H

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

class Ui_Lecture10_demo_spin_sliderClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Lecture10_demo_spin_sliderClass)
    {
        if (Lecture10_demo_spin_sliderClass->objectName().isEmpty())
            Lecture10_demo_spin_sliderClass->setObjectName(QStringLiteral("Lecture10_demo_spin_sliderClass"));
        Lecture10_demo_spin_sliderClass->resize(600, 400);
        menuBar = new QMenuBar(Lecture10_demo_spin_sliderClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        Lecture10_demo_spin_sliderClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Lecture10_demo_spin_sliderClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Lecture10_demo_spin_sliderClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Lecture10_demo_spin_sliderClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Lecture10_demo_spin_sliderClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Lecture10_demo_spin_sliderClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Lecture10_demo_spin_sliderClass->setStatusBar(statusBar);

        retranslateUi(Lecture10_demo_spin_sliderClass);

        QMetaObject::connectSlotsByName(Lecture10_demo_spin_sliderClass);
    } // setupUi

    void retranslateUi(QMainWindow *Lecture10_demo_spin_sliderClass)
    {
        Lecture10_demo_spin_sliderClass->setWindowTitle(QApplication::translate("Lecture10_demo_spin_sliderClass", "Lecture10_demo_spin_slider", 0));
    } // retranslateUi

};

namespace Ui {
    class Lecture10_demo_spin_sliderClass: public Ui_Lecture10_demo_spin_sliderClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LECTURE10_DEMO_SPIN_SLIDER_H

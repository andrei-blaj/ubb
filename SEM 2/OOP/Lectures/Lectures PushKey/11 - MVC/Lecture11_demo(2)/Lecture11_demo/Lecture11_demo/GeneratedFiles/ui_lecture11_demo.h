/********************************************************************************
** Form generated from reading UI file 'lecture11_demo.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LECTURE11_DEMO_H
#define UI_LECTURE11_DEMO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lecture11_demoClass
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *GenesWidgetButton;
    QPushButton *GenesViewButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Lecture11_demoClass)
    {
        if (Lecture11_demoClass->objectName().isEmpty())
            Lecture11_demoClass->setObjectName(QStringLiteral("Lecture11_demoClass"));
        Lecture11_demoClass->resize(325, 164);
        centralWidget = new QWidget(Lecture11_demoClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 283, 90));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        GenesWidgetButton = new QPushButton(layoutWidget);
        GenesWidgetButton->setObjectName(QStringLiteral("GenesWidgetButton"));
        QFont font;
        font.setPointSize(20);
        GenesWidgetButton->setFont(font);

        verticalLayout->addWidget(GenesWidgetButton);

        GenesViewButton = new QPushButton(layoutWidget);
        GenesViewButton->setObjectName(QStringLiteral("GenesViewButton"));
        GenesViewButton->setFont(font);

        verticalLayout->addWidget(GenesViewButton);

        Lecture11_demoClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Lecture11_demoClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 325, 21));
        Lecture11_demoClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Lecture11_demoClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Lecture11_demoClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Lecture11_demoClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Lecture11_demoClass->setStatusBar(statusBar);

        retranslateUi(Lecture11_demoClass);

        QMetaObject::connectSlotsByName(Lecture11_demoClass);
    } // setupUi

    void retranslateUi(QMainWindow *Lecture11_demoClass)
    {
        Lecture11_demoClass->setWindowTitle(QApplication::translate("Lecture11_demoClass", "Lecture11_demo", 0));
        GenesWidgetButton->setText(QApplication::translate("Lecture11_demoClass", "Genes widget", 0));
        GenesViewButton->setText(QApplication::translate("Lecture11_demoClass", "Genes view with model", 0));
    } // retranslateUi

};

namespace Ui {
    class Lecture11_demoClass: public Ui_Lecture11_demoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LECTURE11_DEMO_H

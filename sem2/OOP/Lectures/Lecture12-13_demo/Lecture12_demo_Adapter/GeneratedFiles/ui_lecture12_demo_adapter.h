/********************************************************************************
** Form generated from reading UI file 'lecture12_demo_adapter.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LECTURE12_DEMO_ADAPTER_H
#define UI_LECTURE12_DEMO_ADAPTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lecture12_demo_AdapterClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QListWidget *housesListWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *payPalButton;
    QPushButton *skrillButton;
    QPushButton *goCardlessButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Lecture12_demo_AdapterClass)
    {
        if (Lecture12_demo_AdapterClass->objectName().isEmpty())
            Lecture12_demo_AdapterClass->setObjectName(QStringLiteral("Lecture12_demo_AdapterClass"));
        Lecture12_demo_AdapterClass->resize(556, 364);
        centralWidget = new QWidget(Lecture12_demo_AdapterClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        housesListWidget = new QListWidget(centralWidget);
        housesListWidget->setObjectName(QStringLiteral("housesListWidget"));

        verticalLayout->addWidget(housesListWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        payPalButton = new QPushButton(centralWidget);
        payPalButton->setObjectName(QStringLiteral("payPalButton"));
        QFont font;
        font.setPointSize(18);
        payPalButton->setFont(font);

        horizontalLayout->addWidget(payPalButton);

        skrillButton = new QPushButton(centralWidget);
        skrillButton->setObjectName(QStringLiteral("skrillButton"));
        skrillButton->setFont(font);

        horizontalLayout->addWidget(skrillButton);

        goCardlessButton = new QPushButton(centralWidget);
        goCardlessButton->setObjectName(QStringLiteral("goCardlessButton"));
        goCardlessButton->setFont(font);

        horizontalLayout->addWidget(goCardlessButton);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);

        Lecture12_demo_AdapterClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Lecture12_demo_AdapterClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 556, 21));
        Lecture12_demo_AdapterClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Lecture12_demo_AdapterClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Lecture12_demo_AdapterClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Lecture12_demo_AdapterClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Lecture12_demo_AdapterClass->setStatusBar(statusBar);

        retranslateUi(Lecture12_demo_AdapterClass);

        QMetaObject::connectSlotsByName(Lecture12_demo_AdapterClass);
    } // setupUi

    void retranslateUi(QMainWindow *Lecture12_demo_AdapterClass)
    {
        Lecture12_demo_AdapterClass->setWindowTitle(QApplication::translate("Lecture12_demo_AdapterClass", "Lecture12_demo_Adapter", 0));
        payPalButton->setText(QApplication::translate("Lecture12_demo_AdapterClass", "PayPal", 0));
        skrillButton->setText(QApplication::translate("Lecture12_demo_AdapterClass", "Skrill", 0));
        goCardlessButton->setText(QApplication::translate("Lecture12_demo_AdapterClass", "GoCardless", 0));
    } // retranslateUi

};

namespace Ui {
    class Lecture12_demo_AdapterClass: public Ui_Lecture12_demo_AdapterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LECTURE12_DEMO_ADAPTER_H

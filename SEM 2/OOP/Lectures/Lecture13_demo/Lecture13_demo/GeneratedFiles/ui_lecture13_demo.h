/********************************************************************************
** Form generated from reading UI file 'lecture13_demo.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LECTURE13_DEMO_H
#define UI_LECTURE13_DEMO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <fibowidget.h>

QT_BEGIN_NAMESPACE

class Ui_Lecture13_demoClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *numberLineEdit1;
    QPushButton *computeButton1;
    QLabel *labelResult1;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *numberLineEdit2;
    QPushButton *computeButton2;
    QLabel *labelResult2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *numberLineEdit3;
    QPushButton *computeButton3;
    QLabel *labelResult3;
    FiboWidget *fiboWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Lecture13_demoClass)
    {
        if (Lecture13_demoClass->objectName().isEmpty())
            Lecture13_demoClass->setObjectName(QStringLiteral("Lecture13_demoClass"));
        Lecture13_demoClass->resize(1822, 608);
        centralWidget = new QWidget(Lecture13_demoClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_4 = new QHBoxLayout(centralWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        numberLineEdit1 = new QLineEdit(centralWidget);
        numberLineEdit1->setObjectName(QStringLiteral("numberLineEdit1"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(numberLineEdit1->sizePolicy().hasHeightForWidth());
        numberLineEdit1->setSizePolicy(sizePolicy);
        numberLineEdit1->setMinimumSize(QSize(280, 0));
        numberLineEdit1->setMaximumSize(QSize(100, 16777215));
        QFont font;
        font.setPointSize(18);
        numberLineEdit1->setFont(font);

        horizontalLayout->addWidget(numberLineEdit1);

        computeButton1 = new QPushButton(centralWidget);
        computeButton1->setObjectName(QStringLiteral("computeButton1"));
        computeButton1->setMinimumSize(QSize(0, 0));
        computeButton1->setMaximumSize(QSize(120, 16777215));
        computeButton1->setFont(font);

        horizontalLayout->addWidget(computeButton1);

        labelResult1 = new QLabel(centralWidget);
        labelResult1->setObjectName(QStringLiteral("labelResult1"));
        labelResult1->setMinimumSize(QSize(200, 0));
        labelResult1->setMaximumSize(QSize(200, 16777215));
        labelResult1->setFont(font);

        horizontalLayout->addWidget(labelResult1);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        numberLineEdit2 = new QLineEdit(centralWidget);
        numberLineEdit2->setObjectName(QStringLiteral("numberLineEdit2"));
        numberLineEdit2->setMinimumSize(QSize(280, 0));
        numberLineEdit2->setMaximumSize(QSize(100, 16777215));
        numberLineEdit2->setFont(font);

        horizontalLayout_2->addWidget(numberLineEdit2);

        computeButton2 = new QPushButton(centralWidget);
        computeButton2->setObjectName(QStringLiteral("computeButton2"));
        computeButton2->setMinimumSize(QSize(0, 0));
        computeButton2->setMaximumSize(QSize(120, 16777215));
        computeButton2->setFont(font);

        horizontalLayout_2->addWidget(computeButton2);

        labelResult2 = new QLabel(centralWidget);
        labelResult2->setObjectName(QStringLiteral("labelResult2"));
        labelResult2->setMinimumSize(QSize(200, 0));
        labelResult2->setMaximumSize(QSize(200, 16777215));
        labelResult2->setFont(font);

        horizontalLayout_2->addWidget(labelResult2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        numberLineEdit3 = new QLineEdit(centralWidget);
        numberLineEdit3->setObjectName(QStringLiteral("numberLineEdit3"));
        numberLineEdit3->setMinimumSize(QSize(280, 0));
        numberLineEdit3->setMaximumSize(QSize(100, 16777215));
        numberLineEdit3->setFont(font);

        horizontalLayout_3->addWidget(numberLineEdit3);

        computeButton3 = new QPushButton(centralWidget);
        computeButton3->setObjectName(QStringLiteral("computeButton3"));
        computeButton3->setMinimumSize(QSize(0, 0));
        computeButton3->setMaximumSize(QSize(120, 16777215));
        computeButton3->setFont(font);

        horizontalLayout_3->addWidget(computeButton3);

        labelResult3 = new QLabel(centralWidget);
        labelResult3->setObjectName(QStringLiteral("labelResult3"));
        labelResult3->setMinimumSize(QSize(200, 0));
        labelResult3->setMaximumSize(QSize(200, 16777215));
        labelResult3->setFont(font);

        horizontalLayout_3->addWidget(labelResult3);


        verticalLayout->addLayout(horizontalLayout_3);

        fiboWidget = new FiboWidget(centralWidget);
        fiboWidget->setObjectName(QStringLiteral("fiboWidget"));
        fiboWidget->setMinimumSize(QSize(1500, 400));

        verticalLayout->addWidget(fiboWidget);

        verticalLayout->setStretch(0, 1);

        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout_4->addLayout(verticalLayout_2);

        Lecture13_demoClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Lecture13_demoClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1822, 21));
        Lecture13_demoClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Lecture13_demoClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Lecture13_demoClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Lecture13_demoClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Lecture13_demoClass->setStatusBar(statusBar);

        retranslateUi(Lecture13_demoClass);

        QMetaObject::connectSlotsByName(Lecture13_demoClass);
    } // setupUi

    void retranslateUi(QMainWindow *Lecture13_demoClass)
    {
        Lecture13_demoClass->setWindowTitle(QApplication::translate("Lecture13_demoClass", "Lecture13_demo", 0));
        numberLineEdit1->setPlaceholderText(QApplication::translate("Lecture13_demoClass", "nth Fibonacci number...", 0));
        computeButton1->setText(QApplication::translate("Lecture13_demoClass", "Compute", 0));
        labelResult1->setText(QString());
        numberLineEdit2->setPlaceholderText(QApplication::translate("Lecture13_demoClass", "nth Fibonacci number...", 0));
        computeButton2->setText(QApplication::translate("Lecture13_demoClass", "Compute", 0));
        labelResult2->setText(QString());
        numberLineEdit3->setPlaceholderText(QApplication::translate("Lecture13_demoClass", "nth Fibonacci number...", 0));
        computeButton3->setText(QApplication::translate("Lecture13_demoClass", "Compute", 0));
        labelResult3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Lecture13_demoClass: public Ui_Lecture13_demoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LECTURE13_DEMO_H

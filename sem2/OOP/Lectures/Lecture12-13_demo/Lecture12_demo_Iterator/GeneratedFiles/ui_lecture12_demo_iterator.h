/********************************************************************************
** Form generated from reading UI file 'lecture12_demo_iterator.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LECTURE12_DEMO_ITERATOR_H
#define UI_LECTURE12_DEMO_ITERATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lecture12_demo_IteratorClass
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *castleLabel;
    QLabel *photoLabel;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *nextButton;
    QPushButton *slideShowButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Lecture12_demo_IteratorClass)
    {
        if (Lecture12_demo_IteratorClass->objectName().isEmpty())
            Lecture12_demo_IteratorClass->setObjectName(QStringLiteral("Lecture12_demo_IteratorClass"));
        Lecture12_demo_IteratorClass->resize(955, 632);
        centralWidget = new QWidget(Lecture12_demo_IteratorClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 9, 911, 521));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        castleLabel = new QLabel(layoutWidget);
        castleLabel->setObjectName(QStringLiteral("castleLabel"));
        QFont font;
        font.setPointSize(18);
        castleLabel->setFont(font);

        verticalLayout->addWidget(castleLabel);

        photoLabel = new QLabel(layoutWidget);
        photoLabel->setObjectName(QStringLiteral("photoLabel"));
        photoLabel->setFont(font);

        verticalLayout->addWidget(photoLabel);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(360, 540, 197, 39));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        nextButton = new QPushButton(widget);
        nextButton->setObjectName(QStringLiteral("nextButton"));
        nextButton->setFont(font);

        horizontalLayout->addWidget(nextButton);

        slideShowButton = new QPushButton(widget);
        slideShowButton->setObjectName(QStringLiteral("slideShowButton"));
        slideShowButton->setFont(font);

        horizontalLayout->addWidget(slideShowButton);

        Lecture12_demo_IteratorClass->setCentralWidget(centralWidget);
        layoutWidget->raise();
        nextButton->raise();
        slideShowButton->raise();
        slideShowButton->raise();
        menuBar = new QMenuBar(Lecture12_demo_IteratorClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 955, 21));
        Lecture12_demo_IteratorClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Lecture12_demo_IteratorClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Lecture12_demo_IteratorClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Lecture12_demo_IteratorClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Lecture12_demo_IteratorClass->setStatusBar(statusBar);

        retranslateUi(Lecture12_demo_IteratorClass);

        QMetaObject::connectSlotsByName(Lecture12_demo_IteratorClass);
    } // setupUi

    void retranslateUi(QMainWindow *Lecture12_demo_IteratorClass)
    {
        Lecture12_demo_IteratorClass->setWindowTitle(QApplication::translate("Lecture12_demo_IteratorClass", "Lecture12_demo_Iterator", 0));
        castleLabel->setText(QString());
        photoLabel->setText(QString());
        nextButton->setText(QApplication::translate("Lecture12_demo_IteratorClass", "Next", 0));
        slideShowButton->setText(QApplication::translate("Lecture12_demo_IteratorClass", "SlideShow", 0));
    } // retranslateUi

};

namespace Ui {
    class Lecture12_demo_IteratorClass: public Ui_Lecture12_demo_IteratorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LECTURE12_DEMO_ITERATOR_H

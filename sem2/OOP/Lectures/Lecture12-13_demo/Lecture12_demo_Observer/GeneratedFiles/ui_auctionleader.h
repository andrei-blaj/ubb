/********************************************************************************
** Form generated from reading UI file 'auctionleader.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUCTIONLEADER_H
#define UI_AUCTIONLEADER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuctionLeader
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QListWidget *housesListWidget;
    QPushButton *startButton;

    void setupUi(QWidget *AuctionLeader)
    {
        if (AuctionLeader->objectName().isEmpty())
            AuctionLeader->setObjectName(QStringLiteral("AuctionLeader"));
        AuctionLeader->resize(317, 379);
        layoutWidget = new QWidget(AuctionLeader);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 301, 361));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        housesListWidget = new QListWidget(layoutWidget);
        housesListWidget->setObjectName(QStringLiteral("housesListWidget"));

        verticalLayout->addWidget(housesListWidget);

        startButton = new QPushButton(layoutWidget);
        startButton->setObjectName(QStringLiteral("startButton"));
        QFont font;
        font.setPointSize(14);
        startButton->setFont(font);

        verticalLayout->addWidget(startButton);


        retranslateUi(AuctionLeader);

        QMetaObject::connectSlotsByName(AuctionLeader);
    } // setupUi

    void retranslateUi(QWidget *AuctionLeader)
    {
        AuctionLeader->setWindowTitle(QApplication::translate("AuctionLeader", "AuctionLeader", 0));
        startButton->setText(QApplication::translate("AuctionLeader", "Start ", 0));
    } // retranslateUi

};

namespace Ui {
    class AuctionLeader: public Ui_AuctionLeader {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUCTIONLEADER_H

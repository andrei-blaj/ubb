/********************************************************************************
** Form generated from reading UI file 'bidderwithdescription.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BIDDERWITHDESCRIPTION_H
#define UI_BIDDERWITHDESCRIPTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BidderWithDescription
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *labelDescription;
    QLabel *labelPrice;
    QHBoxLayout *horizontalLayout;
    QPushButton *add100Button;
    QPushButton *add1000Button;

    void setupUi(QWidget *BidderWithDescription)
    {
        if (BidderWithDescription->objectName().isEmpty())
            BidderWithDescription->setObjectName(QStringLiteral("BidderWithDescription"));
        BidderWithDescription->resize(470, 252);
        horizontalLayout_2 = new QHBoxLayout(BidderWithDescription);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        labelDescription = new QLabel(BidderWithDescription);
        labelDescription->setObjectName(QStringLiteral("labelDescription"));
        QFont font;
        font.setPointSize(20);
        labelDescription->setFont(font);

        verticalLayout->addWidget(labelDescription);

        labelPrice = new QLabel(BidderWithDescription);
        labelPrice->setObjectName(QStringLiteral("labelPrice"));
        labelPrice->setFont(font);

        verticalLayout->addWidget(labelPrice);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        add100Button = new QPushButton(BidderWithDescription);
        add100Button->setObjectName(QStringLiteral("add100Button"));
        QFont font1;
        font1.setPointSize(18);
        add100Button->setFont(font1);

        horizontalLayout->addWidget(add100Button);

        add1000Button = new QPushButton(BidderWithDescription);
        add1000Button->setObjectName(QStringLiteral("add1000Button"));
        add1000Button->setFont(font1);

        horizontalLayout->addWidget(add1000Button);


        verticalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout_2);


        retranslateUi(BidderWithDescription);

        QMetaObject::connectSlotsByName(BidderWithDescription);
    } // setupUi

    void retranslateUi(QWidget *BidderWithDescription)
    {
        BidderWithDescription->setWindowTitle(QApplication::translate("BidderWithDescription", "BidderWithDescription", 0));
        labelDescription->setText(QString());
        labelPrice->setText(QString());
        add100Button->setText(QApplication::translate("BidderWithDescription", "Add 100", 0));
        add1000Button->setText(QApplication::translate("BidderWithDescription", "Add 1000", 0));
    } // retranslateUi

};

namespace Ui {
    class BidderWithDescription: public Ui_BidderWithDescription {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BIDDERWITHDESCRIPTION_H

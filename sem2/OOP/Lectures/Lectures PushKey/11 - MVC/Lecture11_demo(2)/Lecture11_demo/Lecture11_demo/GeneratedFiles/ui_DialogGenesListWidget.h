/********************************************************************************
** Form generated from reading UI file 'DialogGenesListWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGGENESLISTWIDGET_H
#define UI_DIALOGGENESLISTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogGenesWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget;

    void setupUi(QDialog *DialogGenesWidget)
    {
        if (DialogGenesWidget->objectName().isEmpty())
            DialogGenesWidget->setObjectName(QStringLiteral("DialogGenesWidget"));
        DialogGenesWidget->resize(347, 405);
        horizontalLayout = new QHBoxLayout(DialogGenesWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        listWidget = new QListWidget(DialogGenesWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        horizontalLayout->addWidget(listWidget);


        retranslateUi(DialogGenesWidget);

        QMetaObject::connectSlotsByName(DialogGenesWidget);
    } // setupUi

    void retranslateUi(QDialog *DialogGenesWidget)
    {
        DialogGenesWidget->setWindowTitle(QApplication::translate("DialogGenesWidget", "Genes List Widget", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogGenesWidget: public Ui_DialogGenesWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGGENESLISTWIDGET_H

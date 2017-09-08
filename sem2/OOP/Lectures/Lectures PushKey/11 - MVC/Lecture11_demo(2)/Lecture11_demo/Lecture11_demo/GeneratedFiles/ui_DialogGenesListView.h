/********************************************************************************
** Form generated from reading UI file 'DialogGenesListView.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGGENESLISTVIEW_H
#define UI_DIALOGGENESLISTVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>

QT_BEGIN_NAMESPACE

class Ui_DialogGenesListView
{
public:
    QHBoxLayout *horizontalLayout;
    QListView *listView;

    void setupUi(QDialog *DialogGenesListView)
    {
        if (DialogGenesListView->objectName().isEmpty())
            DialogGenesListView->setObjectName(QStringLiteral("DialogGenesListView"));
        DialogGenesListView->resize(330, 406);
        horizontalLayout = new QHBoxLayout(DialogGenesListView);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        listView = new QListView(DialogGenesListView);
        listView->setObjectName(QStringLiteral("listView"));

        horizontalLayout->addWidget(listView);


        retranslateUi(DialogGenesListView);

        QMetaObject::connectSlotsByName(DialogGenesListView);
    } // setupUi

    void retranslateUi(QDialog *DialogGenesListView)
    {
        DialogGenesListView->setWindowTitle(QApplication::translate("DialogGenesListView", "DialogGenesListView", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogGenesListView: public Ui_DialogGenesListView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGGENESLISTVIEW_H

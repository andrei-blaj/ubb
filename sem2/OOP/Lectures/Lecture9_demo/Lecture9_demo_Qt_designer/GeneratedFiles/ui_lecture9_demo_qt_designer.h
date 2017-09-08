/********************************************************************************
** Form generated from reading UI file 'lecture9_demo_qt_designer.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LECTURE9_DEMO_QT_DESIGNER_H
#define UI_LECTURE9_DEMO_QT_DESIGNER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lecture9_demo_Qt_designerClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QFormLayout *formLayout;
    QLabel *nameLabel;
    QLineEdit *nameEdit;
    QLabel *emailLabel;
    QLineEdit *emailEdit;
    QLabel *genderLabel;
    QComboBox *genderComboBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *OKButton;
    QPushButton *CancelButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Lecture9_demo_Qt_designerClass)
    {
        if (Lecture9_demo_Qt_designerClass->objectName().isEmpty())
            Lecture9_demo_Qt_designerClass->setObjectName(QStringLiteral("Lecture9_demo_Qt_designerClass"));
        Lecture9_demo_Qt_designerClass->resize(444, 504);
        centralWidget = new QWidget(Lecture9_demo_Qt_designerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        nameLabel = new QLabel(centralWidget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, nameLabel);

        nameEdit = new QLineEdit(centralWidget);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nameEdit);

        emailLabel = new QLabel(centralWidget);
        emailLabel->setObjectName(QStringLiteral("emailLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, emailLabel);

        emailEdit = new QLineEdit(centralWidget);
        emailEdit->setObjectName(QStringLiteral("emailEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, emailEdit);

        genderLabel = new QLabel(centralWidget);
        genderLabel->setObjectName(QStringLiteral("genderLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, genderLabel);

        genderComboBox = new QComboBox(centralWidget);
        genderComboBox->setObjectName(QStringLiteral("genderComboBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, genderComboBox);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        OKButton = new QPushButton(centralWidget);
        OKButton->setObjectName(QStringLiteral("OKButton"));

        horizontalLayout->addWidget(OKButton);

        CancelButton = new QPushButton(centralWidget);
        CancelButton->setObjectName(QStringLiteral("CancelButton"));

        horizontalLayout->addWidget(CancelButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        Lecture9_demo_Qt_designerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Lecture9_demo_Qt_designerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 444, 21));
        Lecture9_demo_Qt_designerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Lecture9_demo_Qt_designerClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Lecture9_demo_Qt_designerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Lecture9_demo_Qt_designerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Lecture9_demo_Qt_designerClass->setStatusBar(statusBar);

        retranslateUi(Lecture9_demo_Qt_designerClass);

        QMetaObject::connectSlotsByName(Lecture9_demo_Qt_designerClass);
    } // setupUi

    void retranslateUi(QMainWindow *Lecture9_demo_Qt_designerClass)
    {
        Lecture9_demo_Qt_designerClass->setWindowTitle(QApplication::translate("Lecture9_demo_Qt_designerClass", "Lecture9_demo_Qt_designer", 0));
        nameLabel->setText(QApplication::translate("Lecture9_demo_Qt_designerClass", "Name", 0));
        emailLabel->setText(QApplication::translate("Lecture9_demo_Qt_designerClass", "Email", 0));
        genderLabel->setText(QApplication::translate("Lecture9_demo_Qt_designerClass", "Gender", 0));
        OKButton->setText(QApplication::translate("Lecture9_demo_Qt_designerClass", "OK", 0));
        CancelButton->setText(QApplication::translate("Lecture9_demo_Qt_designerClass", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class Lecture9_demo_Qt_designerClass: public Ui_Lecture9_demo_Qt_designerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LECTURE9_DEMO_QT_DESIGNER_H

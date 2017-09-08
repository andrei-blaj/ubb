/********************************************************************************
** Form generated from reading UI file 'admin.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_H
#define UI_ADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_admin
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QVBoxLayout *verticalLayout;
    QLineEdit *admin_name;
    QLineEdit *admin_breed;
    QLineEdit *admin_age;
    QLineEdit *admin_photo;
    QPushButton *admin_add;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *admin_delete_label;
    QLineEdit *admin_update_label;
    QVBoxLayout *verticalLayout_4;
    QPushButton *admin_delete;
    QPushButton *admin_update;
    QPushButton *admin_display;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_8;
    QTextEdit *textEdit;
    QLabel *admin_message_label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButton1;
    QRadioButton *radioButton;

    void setupUi(QWidget *admin)
    {
        if (admin->objectName().isEmpty())
            admin->setObjectName(QStringLiteral("admin"));
        admin->resize(641, 426);
        label = new QLabel(admin);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(300, 30, 41, 16));
        layoutWidget = new QWidget(admin);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 60, 242, 284));
        verticalLayout_7 = new QVBoxLayout(layoutWidget);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_2->addWidget(label_4);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_2->addWidget(label_5);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        admin_name = new QLineEdit(layoutWidget);
        admin_name->setObjectName(QStringLiteral("admin_name"));

        verticalLayout->addWidget(admin_name);

        admin_breed = new QLineEdit(layoutWidget);
        admin_breed->setObjectName(QStringLiteral("admin_breed"));

        verticalLayout->addWidget(admin_breed);

        admin_age = new QLineEdit(layoutWidget);
        admin_age->setObjectName(QStringLiteral("admin_age"));

        verticalLayout->addWidget(admin_age);

        admin_photo = new QLineEdit(layoutWidget);
        admin_photo->setObjectName(QStringLiteral("admin_photo"));

        verticalLayout->addWidget(admin_photo);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout);

        admin_add = new QPushButton(layoutWidget);
        admin_add->setObjectName(QStringLiteral("admin_add"));

        verticalLayout_3->addWidget(admin_add);


        verticalLayout_6->addLayout(verticalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        admin_delete_label = new QLineEdit(layoutWidget);
        admin_delete_label->setObjectName(QStringLiteral("admin_delete_label"));

        verticalLayout_5->addWidget(admin_delete_label);

        admin_update_label = new QLineEdit(layoutWidget);
        admin_update_label->setObjectName(QStringLiteral("admin_update_label"));

        verticalLayout_5->addWidget(admin_update_label);


        horizontalLayout_2->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        admin_delete = new QPushButton(layoutWidget);
        admin_delete->setObjectName(QStringLiteral("admin_delete"));

        verticalLayout_4->addWidget(admin_delete);

        admin_update = new QPushButton(layoutWidget);
        admin_update->setObjectName(QStringLiteral("admin_update"));

        verticalLayout_4->addWidget(admin_update);


        horizontalLayout_2->addLayout(verticalLayout_4);


        verticalLayout_6->addLayout(horizontalLayout_2);


        verticalLayout_7->addLayout(verticalLayout_6);

        admin_display = new QPushButton(layoutWidget);
        admin_display->setObjectName(QStringLiteral("admin_display"));

        verticalLayout_7->addWidget(admin_display);

        layoutWidget1 = new QWidget(admin);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(270, 60, 361, 281));
        verticalLayout_8 = new QVBoxLayout(layoutWidget1);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(layoutWidget1);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout_8->addWidget(textEdit);

        admin_message_label = new QLabel(layoutWidget1);
        admin_message_label->setObjectName(QStringLiteral("admin_message_label"));

        verticalLayout_8->addWidget(admin_message_label);

        widget = new QWidget(admin);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 380, 611, 20));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        radioButton1 = new QRadioButton(widget);
        radioButton1->setObjectName(QStringLiteral("radioButton1"));
        radioButton1->setChecked(true);

        horizontalLayout_3->addWidget(radioButton1);

        radioButton = new QRadioButton(widget);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        horizontalLayout_3->addWidget(radioButton);


        retranslateUi(admin);

        QMetaObject::connectSlotsByName(admin);
    } // setupUi

    void retranslateUi(QWidget *admin)
    {
        admin->setWindowTitle(QApplication::translate("admin", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("admin", "Admin", Q_NULLPTR));
        label_2->setText(QApplication::translate("admin", "Name:", Q_NULLPTR));
        label_3->setText(QApplication::translate("admin", "Breed:", Q_NULLPTR));
        label_4->setText(QApplication::translate("admin", "Age:", Q_NULLPTR));
        label_5->setText(QApplication::translate("admin", "Photograph:", Q_NULLPTR));
        admin_add->setText(QApplication::translate("admin", "Add", Q_NULLPTR));
        admin_delete->setText(QApplication::translate("admin", "Delete", Q_NULLPTR));
        admin_update->setText(QApplication::translate("admin", "Update", Q_NULLPTR));
        admin_display->setText(QApplication::translate("admin", "Display dogs", Q_NULLPTR));
        admin_message_label->setText(QApplication::translate("admin", "> Welcome!", Q_NULLPTR));
        radioButton1->setText(QApplication::translate("admin", "Sorted", Q_NULLPTR));
        radioButton->setText(QApplication::translate("admin", "Shuffled", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class admin: public Ui_admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H

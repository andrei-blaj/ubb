/********************************************************************************
** Form generated from reading UI file 'user.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_H
#define UI_USER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_User
{
public:
    QLabel *label;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *user_adopt;
    QPushButton *user_next;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *user_see_adoption_list;
    QPushButton *see_adoption_list_html;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *user_breed;
    QLineEdit *user_age;
    QPushButton *user_filter;

    void setupUi(QWidget *User)
    {
        if (User->objectName().isEmpty())
            User->setObjectName(QStringLiteral("User"));
        User->resize(574, 476);
        label = new QLabel(User);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(270, 20, 31, 16));
        widget = new QWidget(User);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(21, 52, 465, 413));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textEdit = new QTextEdit(widget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        user_adopt = new QPushButton(widget);
        user_adopt->setObjectName(QStringLiteral("user_adopt"));

        horizontalLayout->addWidget(user_adopt);

        user_next = new QPushButton(widget);
        user_next->setObjectName(QStringLiteral("user_next"));

        horizontalLayout->addWidget(user_next);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        user_see_adoption_list = new QPushButton(widget);
        user_see_adoption_list->setObjectName(QStringLiteral("user_see_adoption_list"));

        horizontalLayout_3->addWidget(user_see_adoption_list);

        see_adoption_list_html = new QPushButton(widget);
        see_adoption_list_html->setObjectName(QStringLiteral("see_adoption_list_html"));

        horizontalLayout_3->addWidget(see_adoption_list_html);


        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_5->addWidget(label_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_3->addWidget(label_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_3->addWidget(label_3);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        user_breed = new QLineEdit(widget);
        user_breed->setObjectName(QStringLiteral("user_breed"));

        verticalLayout_4->addWidget(user_breed);

        user_age = new QLineEdit(widget);
        user_age->setObjectName(QStringLiteral("user_age"));

        verticalLayout_4->addWidget(user_age);


        horizontalLayout_2->addLayout(verticalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout_2);

        user_filter = new QPushButton(widget);
        user_filter->setObjectName(QStringLiteral("user_filter"));

        verticalLayout_5->addWidget(user_filter);


        verticalLayout_2->addLayout(verticalLayout_5);


        retranslateUi(User);

        QMetaObject::connectSlotsByName(User);
    } // setupUi

    void retranslateUi(QWidget *User)
    {
        User->setWindowTitle(QApplication::translate("User", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("User", "User", Q_NULLPTR));
        user_adopt->setText(QApplication::translate("User", "Adopt", Q_NULLPTR));
        user_next->setText(QApplication::translate("User", "Next", Q_NULLPTR));
        user_see_adoption_list->setText(QApplication::translate("User", "See CSV", Q_NULLPTR));
        see_adoption_list_html->setText(QApplication::translate("User", "See HTML", Q_NULLPTR));
        label_4->setText(QApplication::translate("User", "See all the dogs of a given breed, having the age less than a given number", Q_NULLPTR));
        label_2->setText(QApplication::translate("User", "Breed", Q_NULLPTR));
        label_3->setText(QApplication::translate("User", "Age", Q_NULLPTR));
        user_filter->setText(QApplication::translate("User", "Filter dogs", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class User: public Ui_User {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_H

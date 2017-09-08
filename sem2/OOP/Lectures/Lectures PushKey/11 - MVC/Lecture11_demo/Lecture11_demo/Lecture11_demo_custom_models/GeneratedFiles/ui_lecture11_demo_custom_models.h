/********************************************************************************
** Form generated from reading UI file 'lecture11_demo_custom_models.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LECTURE11_DEMO_CUSTOM_MODELS_H
#define UI_LECTURE11_DEMO_CUSTOM_MODELS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lecture11_demo_custom_modelsClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tableView;
    QHBoxLayout *horizontalLayout_2;
    QTableView *genesTableView;
    QWidget *treeView;
    QHBoxLayout *horizontalLayout_3;
    QTreeView *genesTreeView;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_4;
    QListView *genesListView;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_5;
    QTableView *paginatedGenesTableView;
    QWidget *tab_3;
    QHBoxLayout *horizontalLayout_6;
    QTableView *picturesTableView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Lecture11_demo_custom_modelsClass)
    {
        if (Lecture11_demo_custom_modelsClass->objectName().isEmpty())
            Lecture11_demo_custom_modelsClass->setObjectName(QStringLiteral("Lecture11_demo_custom_modelsClass"));
        Lecture11_demo_custom_modelsClass->resize(1032, 363);
        centralWidget = new QWidget(Lecture11_demo_custom_modelsClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QFont font;
        font.setPointSize(14);
        tabWidget->setFont(font);
        tableView = new QWidget();
        tableView->setObjectName(QStringLiteral("tableView"));
        horizontalLayout_2 = new QHBoxLayout(tableView);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        genesTableView = new QTableView(tableView);
        genesTableView->setObjectName(QStringLiteral("genesTableView"));

        horizontalLayout_2->addWidget(genesTableView);

        tabWidget->addTab(tableView, QString());
        treeView = new QWidget();
        treeView->setObjectName(QStringLiteral("treeView"));
        horizontalLayout_3 = new QHBoxLayout(treeView);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        genesTreeView = new QTreeView(treeView);
        genesTreeView->setObjectName(QStringLiteral("genesTreeView"));

        horizontalLayout_3->addWidget(genesTreeView);

        tabWidget->addTab(treeView, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        horizontalLayout_4 = new QHBoxLayout(tab);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        genesListView = new QListView(tab);
        genesListView->setObjectName(QStringLiteral("genesListView"));

        horizontalLayout_4->addWidget(genesListView);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        horizontalLayout_5 = new QHBoxLayout(tab_2);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        paginatedGenesTableView = new QTableView(tab_2);
        paginatedGenesTableView->setObjectName(QStringLiteral("paginatedGenesTableView"));

        horizontalLayout_5->addWidget(paginatedGenesTableView);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        horizontalLayout_6 = new QHBoxLayout(tab_3);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        picturesTableView = new QTableView(tab_3);
        picturesTableView->setObjectName(QStringLiteral("picturesTableView"));

        horizontalLayout_6->addWidget(picturesTableView);

        tabWidget->addTab(tab_3, QString());

        horizontalLayout->addWidget(tabWidget);

        Lecture11_demo_custom_modelsClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Lecture11_demo_custom_modelsClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1032, 21));
        Lecture11_demo_custom_modelsClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Lecture11_demo_custom_modelsClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Lecture11_demo_custom_modelsClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Lecture11_demo_custom_modelsClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Lecture11_demo_custom_modelsClass->setStatusBar(statusBar);

        retranslateUi(Lecture11_demo_custom_modelsClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Lecture11_demo_custom_modelsClass);
    } // setupUi

    void retranslateUi(QMainWindow *Lecture11_demo_custom_modelsClass)
    {
        Lecture11_demo_custom_modelsClass->setWindowTitle(QApplication::translate("Lecture11_demo_custom_modelsClass", "Lecture11_demo_custom_models", 0));
        tabWidget->setTabText(tabWidget->indexOf(tableView), QApplication::translate("Lecture11_demo_custom_modelsClass", "TableView", 0));
        tabWidget->setTabText(tabWidget->indexOf(treeView), QApplication::translate("Lecture11_demo_custom_modelsClass", "TreeView", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Lecture11_demo_custom_modelsClass", "ListView", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Lecture11_demo_custom_modelsClass", "TableView - Paginated", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Lecture11_demo_custom_modelsClass", "TableWithPictures", 0));
    } // retranslateUi

};

namespace Ui {
    class Lecture11_demo_custom_modelsClass: public Ui_Lecture11_demo_custom_modelsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LECTURE11_DEMO_CUSTOM_MODELS_H

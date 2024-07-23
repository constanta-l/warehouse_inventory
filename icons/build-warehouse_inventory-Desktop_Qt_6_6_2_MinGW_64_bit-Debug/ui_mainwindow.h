/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *ProductsLabel;
    QTableView *tableView;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *prevBtn;
    QLabel *pageLabel;
    QPushButton *nextBtn;
    QLineEdit *searchLineEdit;
    QPushButton *searchBtn;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton;
    QPushButton *addBtn;
    QPushButton *deleteBtn;
    QPushButton *toPdfBtn;
    QWidget *tab_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(988, 619);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(20, 10, 961, 581));
        tab = new QWidget();
        tab->setObjectName("tab");
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(140, 60, 371, 431));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        ProductsLabel = new QLabel(layoutWidget);
        ProductsLabel->setObjectName("ProductsLabel");
        ProductsLabel->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"    color: #454544;\n"
"    font-weight: bold;\n"
"    font-size: 13px;"));

        verticalLayout_2->addWidget(ProductsLabel);

        tableView = new QTableView(layoutWidget);
        tableView->setObjectName("tableView");
        tableView->setStyleSheet(QString::fromUtf8("QTableView {\n"
"    background-color: #fff;\n"
"    border: 1px solid gray;\n"
"    color: #454544;\n"
"    gridline-color: gray;\n"
"    outline: 0;\n"
"    font-size: 16px; /* Increase font size */\n"
"}\n"
"\n"
"\n"
"\n"
"QTableView::item:selected {\n"
"    background-color: #5c55e9;\n"
"    color: #fff;\n"
"}\n"
"\n"
"QTableView::item:hover {\n"
"    background-color: #bcbdbb;\n"
"    color: #000;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    color: #2a547f;\n"
"    background-color: #ced5e3;\n"
"    padding: 8px; /* Adjust padding for headers */\n"
"    font-size: 16px;\n"
"    border-bottom: 1px solid gray;\n"
"}\n"
"\n"
"QHeaderView::section:disabled {\n"
"    background-color: #525251;\n"
"    color: #656565;\n"
"}\n"
"\n"
"\n"
"\n"
"QHeaderView::section:checked:disabled {\n"
"    color: #656565;\n"
"    background-color: #525251;\n"
"}\n"
"\n"
"/* Border styling */\n"
"QHeaderView::section::first {\n"
"    border-top: 1px solid #353635;\n"
"}\n"
"\n"
"QHeaderView::section::last {\n"
"    border-left:"
                        " 1px solid #353635;\n"
"}"));

        verticalLayout_2->addWidget(tableView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        prevBtn = new QPushButton(layoutWidget);
        prevBtn->setObjectName("prevBtn");
        prevBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #5c55e9;\n"
"    color: #fff;\n"
"    font-size: 13px;\n"
"    font-weight: bold;\n"
"    border-radius: 5px;\n"
"    padding: 10px;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #5c5c5c;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #5564f2;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #3d4ef2;\n"
"}\n"
""));

        horizontalLayout->addWidget(prevBtn);

        pageLabel = new QLabel(layoutWidget);
        pageLabel->setObjectName("pageLabel");
        pageLabel->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"    color: #454544;\n"
"    font-weight: bold;\n"
"    font-size: 13px;"));
        pageLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(pageLabel);

        nextBtn = new QPushButton(layoutWidget);
        nextBtn->setObjectName("nextBtn");
        nextBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #5c55e9;\n"
"    color: #fff;\n"
"    font-size: 13px;\n"
"    font-weight: bold;\n"
"    border-radius: 5px;\n"
"    padding: 10px;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #5c5c5c;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #5564f2;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #3d4ef2;\n"
"}\n"
""));

        horizontalLayout->addWidget(nextBtn);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        searchLineEdit = new QLineEdit(tab);
        searchLineEdit->setObjectName("searchLineEdit");
        searchLineEdit->setGeometry(QRect(410, 20, 261, 22));
        searchBtn = new QPushButton(tab);
        searchBtn->setObjectName("searchBtn");
        searchBtn->setGeometry(QRect(700, 20, 111, 24));
        searchBtn->setStyleSheet(QString::fromUtf8(""));
        layoutWidget1 = new QWidget(tab);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(600, 90, 221, 281));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName("pushButton");
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #5c55e9;\n"
"    color: #fff;\n"
"    font-size: 13px;\n"
"    font-weight: bold;\n"
"    border-radius: 5px;\n"
"    padding: 10px;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #5c5c5c;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #5564f2;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #3d4ef2;\n"
"}\n"
""));

        verticalLayout_3->addWidget(pushButton);

        addBtn = new QPushButton(layoutWidget1);
        addBtn->setObjectName("addBtn");
        addBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #5c55e9;\n"
"    color: #fff;\n"
"    font-size: 13px;\n"
"    font-weight: bold;\n"
"    border-radius: 5px;\n"
"    padding: 10px;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #5c5c5c;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #5564f2;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #3d4ef2;\n"
"}\n"
""));

        verticalLayout_3->addWidget(addBtn);

        deleteBtn = new QPushButton(layoutWidget1);
        deleteBtn->setObjectName("deleteBtn");
        deleteBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #5c55e9;\n"
"    color: #fff;\n"
"    font-size: 13px;\n"
"    font-weight: bold;\n"
"    border-radius: 5px;\n"
"    padding: 10px;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #5c5c5c;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #5564f2;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #3d4ef2;\n"
"}\n"
""));

        verticalLayout_3->addWidget(deleteBtn);

        toPdfBtn = new QPushButton(layoutWidget1);
        toPdfBtn->setObjectName("toPdfBtn");
        toPdfBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: red;\n"
"    color: #fff;\n"
"    font-size: 13px;\n"
"    font-weight: bold;\n"
"    border-radius: 5px;\n"
"    padding: 10px;\n"
"}"));

        verticalLayout_3->addWidget(toPdfBtn);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Stoc Depozit", nullptr));
        ProductsLabel->setText(QCoreApplication::translate("MainWindow", "Stoc curent", nullptr));
        prevBtn->setText(QCoreApplication::translate("MainWindow", "Precedent\304\203", nullptr));
        pageLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        nextBtn->setText(QCoreApplication::translate("MainWindow", "Urm\304\203toarea", nullptr));
        searchBtn->setText(QCoreApplication::translate("MainWindow", "Caut\304\203", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Toate Produsele", nullptr));
        addBtn->setText(QCoreApplication::translate("MainWindow", "Adaug\304\203 produs", nullptr));
        deleteBtn->setText(QCoreApplication::translate("MainWindow", "\310\230terge produs", nullptr));
        toPdfBtn->setText(QCoreApplication::translate("MainWindow", "Descarc\304\203 stoc curent (PDF)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

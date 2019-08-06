/********************************************************************************
** Form generated from reading UI file 'MainWindowView.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWVIEW_H
#define UI_MAINWINDOWVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowViewClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowViewClass)
    {
        if (MainWindowViewClass->objectName().isEmpty())
            MainWindowViewClass->setObjectName(QString::fromUtf8("MainWindowViewClass"));
        MainWindowViewClass->resize(600, 400);
        menuBar = new QMenuBar(MainWindowViewClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        MainWindowViewClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowViewClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindowViewClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(MainWindowViewClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainWindowViewClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindowViewClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindowViewClass->setStatusBar(statusBar);

        retranslateUi(MainWindowViewClass);

        QMetaObject::connectSlotsByName(MainWindowViewClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowViewClass)
    {
        MainWindowViewClass->setWindowTitle(QCoreApplication::translate("MainWindowViewClass", "MainWindowView", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowViewClass: public Ui_MainWindowViewClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWVIEW_H

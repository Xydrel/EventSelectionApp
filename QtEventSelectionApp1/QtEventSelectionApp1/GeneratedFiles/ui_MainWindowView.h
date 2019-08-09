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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowViewClass
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QHBoxLayout *eventBarHLayout;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowViewClass)
    {
        if (MainWindowViewClass->objectName().isEmpty())
            MainWindowViewClass->setObjectName(QString::fromUtf8("MainWindowViewClass"));
        MainWindowViewClass->resize(1920, 1080);
        centralWidget = new QWidget(MainWindowViewClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 70, 1901, 451));
        eventBarHLayout = new QHBoxLayout(layoutWidget);
        eventBarHLayout->setSpacing(4);
        eventBarHLayout->setContentsMargins(11, 11, 11, 11);
        eventBarHLayout->setObjectName(QString::fromUtf8("eventBarHLayout"));
        eventBarHLayout->setSizeConstraint(QLayout::SetNoConstraint);
        eventBarHLayout->setContentsMargins(0, 0, 0, 0);
        MainWindowViewClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowViewClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1920, 29));
        MainWindowViewClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowViewClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindowViewClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowViewClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindowViewClass->setStatusBar(statusBar);

        retranslateUi(MainWindowViewClass);

        QMetaObject::connectSlotsByName(MainWindowViewClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowViewClass)
    {
        MainWindowViewClass->setWindowTitle(QCoreApplication::translate("MainWindowViewClass", "EventSelectionApp", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowViewClass: public Ui_MainWindowViewClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWVIEW_H

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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowViewClass
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
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
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 80, 1921, 451));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        eventBarHLayout = new QHBoxLayout();
        eventBarHLayout->setSpacing(4);
        eventBarHLayout->setObjectName(QString::fromUtf8("eventBarHLayout"));

        verticalLayout->addLayout(eventBarHLayout);

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

/********************************************************************************
** Form generated from reading UI file 'EventButtonView.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENTBUTTONVIEW_H
#define UI_EVENTBUTTONVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EventButtonView
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *titleHeader;
    QFrame *frame;
    QPushButton *pushButton;
    QLabel *description;
    QLabel *lowerDescription;
    QLabel *thumbnailName;

    void setupUi(QWidget *EventButtonView)
    {
        if (EventButtonView->objectName().isEmpty())
            EventButtonView->setObjectName(QString::fromUtf8("EventButtonView"));
        EventButtonView->resize(318, 464);
        verticalLayoutWidget = new QWidget(EventButtonView);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(-1, -1, 241, 401));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleHeader = new QLabel(verticalLayoutWidget);
        titleHeader->setObjectName(QString::fromUtf8("titleHeader"));
        titleHeader->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(titleHeader->sizePolicy().hasHeightForWidth());
        titleHeader->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(8);
        font.setBold(false);
        font.setWeight(50);
        titleHeader->setFont(font);
        titleHeader->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(titleHeader);

        frame = new QFrame(verticalLayoutWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setSizeIncrement(QSize(0, 0));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 60, 161, 131));
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setBaseSize(QSize(0, 0));

        verticalLayout->addWidget(frame);

        description = new QLabel(verticalLayoutWidget);
        description->setObjectName(QString::fromUtf8("description"));
        sizePolicy.setHeightForWidth(description->sizePolicy().hasHeightForWidth());
        description->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(description);

        lowerDescription = new QLabel(verticalLayoutWidget);
        lowerDescription->setObjectName(QString::fromUtf8("lowerDescription"));
        sizePolicy.setHeightForWidth(lowerDescription->sizePolicy().hasHeightForWidth());
        lowerDescription->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(lowerDescription);

        thumbnailName = new QLabel(verticalLayoutWidget);
        thumbnailName->setObjectName(QString::fromUtf8("thumbnailName"));
        sizePolicy.setHeightForWidth(thumbnailName->sizePolicy().hasHeightForWidth());
        thumbnailName->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(thumbnailName);


        retranslateUi(EventButtonView);

        QMetaObject::connectSlotsByName(EventButtonView);
    } // setupUi

    void retranslateUi(QWidget *EventButtonView)
    {
        EventButtonView->setWindowTitle(QCoreApplication::translate("EventButtonView", "EventButton", nullptr));
        titleHeader->setText(QCoreApplication::translate("EventButtonView", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("EventButtonView", "PushButton", nullptr));
        description->setText(QCoreApplication::translate("EventButtonView", "TextLabel", nullptr));
        lowerDescription->setText(QCoreApplication::translate("EventButtonView", "TextLabel", nullptr));
        thumbnailName->setText(QCoreApplication::translate("EventButtonView", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EventButtonView: public Ui_EventButtonView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENTBUTTONVIEW_H

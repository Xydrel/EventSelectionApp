#include "EventButtonView.h"
#include "EventButtonModel.h"

#include <QPixmap>
#include <QPalette>
#include <QSize>
#include <QFont>

EventButtonView::EventButtonView(QWidget *parent)
	: QWidget(parent)
{
	_ui.setupUi(this);
	_ui.verticalLayoutWidget->installEventFilter(this);

	setButtonViewLayoutDimensions();
	setButtonFrameDimensions();
	setButtonDimensions();
	toggleTextVisibility(false);
}

void EventButtonView::SetModel(const std::shared_ptr<EventButtonModel> model)
{
	_model = model;
}

void EventButtonView::Populate()
{
	_ui.verticalLayout->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

	_ui.frame->setStyleSheet("QFrame {background-position: bottom center}");

	QFont buttonHeaderFont;
	buttonHeaderFont.setBold(true);
	buttonHeaderFont.setPointSize(9);
	_ui.eventHeader->setFont(buttonHeaderFont);
	_ui.eventHeader->setText(_model->GetHeader());
	_ui.eventHeader->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
	_ui.eventHeader->setStyleSheet("QLabel {color:rgb(211,211,211); font-weight:bold}");

	QFont descriptionFont;
	descriptionFont.setBold(true);
	descriptionFont.setPointSize(10);
	_ui.description->setFont(descriptionFont);
	_ui.description->setText(_model->GetDescription());
	_ui.description->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
	_ui.description->setStyleSheet("QLabel {color:rgb(169,169,169)}");

	QFont lowerDescriptionFont;
	lowerDescriptionFont.setBold(false);
	lowerDescriptionFont.setPointSize(6);
	_ui.lowerDescription->setFont(lowerDescriptionFont);
	_ui.lowerDescription->setText(_model->GetLowerDescription());
	_ui.lowerDescription->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
	_ui.lowerDescription->setStyleSheet("QLabel {color:rgb(128,128,128); font-weight:italic}");

	QFont thumbnailFont;
	thumbnailFont.setBold(false);
	thumbnailFont.setPointSize(6);
	_ui.bottomDescription->setFont(thumbnailFont);
	_ui.bottomDescription->setText(_model->GetBottomeDescription());
	_ui.bottomDescription->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
	_ui.bottomDescription->setStyleSheet("QLabel {color:rgb(128,128,128); font-weight:italic}");

	QFont buttonFont;
	buttonFont.setBold(true);
	buttonFont.setPointSize(8);
	_ui.pushButton->setFont(buttonFont);
	_ui.pushButton->setText(QString("08-08-2019"));
	_ui.pushButton->setStyleSheet("QPushButton {border-color:rgb(105,105,105)}");

	loadButtonImage(_model->GetImagePath());
}

QObject* EventButtonView::GetVerticalLayoutWidget() const
{
	return _ui.verticalLayoutWidget;
}

bool EventButtonView::eventFilter(QObject* watched, QEvent* event)
{
	if (watched == _ui.verticalLayoutWidget)
	{
		if (event->type() == QEvent::FocusIn)
		{
			onFocusResizeButton();
		}

		if (event->type() == QEvent::FocusOut)
		{
			onLostFocusResizeButton();
		}
	}

	return false;
}

void EventButtonView::setButtonViewLayoutDimensions()
{
	QSize layoutSz;
	layoutSz.setWidth(_baseLayoutWidth);
	layoutSz.setHeight(_baseLayoutHeight);
	_ui.verticalLayoutWidget->setFixedSize(layoutSz);
}

void EventButtonView::setButtonFrameDimensions()
{
	QSize frameSz;
	frameSz.setWidth(_buttonFrameWidth);
	frameSz.setHeight(_buttonFrameHeight);
	_ui.frame->setFixedSize(frameSz);
}

void EventButtonView::setButtonDimensions()
{
	QSize buttonSz;
	buttonSz.setWidth(_baseButtonWidth);
	buttonSz.setHeight(_baseButtonHeight);
	_ui.pushButton->setFixedSize(buttonSz);
}

void EventButtonView::loadButtonImage(const QString& imagePath)
{
	QPixmap pixmap(imagePath);
	pixmap = pixmap.scaled(_ui.pushButton->size(), Qt::IgnoreAspectRatio);
	_palette.setBrush(QPalette::Background, pixmap);
	_ui.pushButton->setPalette(_palette);
}

void EventButtonView::toggleTextVisibility(bool enable)
{
	if (true == enable)
	{
		_ui.eventHeader->show();
		_ui.description->show();
		_ui.lowerDescription->show();
		_ui.bottomDescription->show();
	}
	else
	{
		_ui.eventHeader->hide();
		_ui.description->hide();
		_ui.lowerDescription->hide();
		_ui.bottomDescription->hide();
	}
}

void EventButtonView::onFocusResizeButton()
{
	QSize scaledSz;
	scaledSz.setWidth(_baseButtonWidth * _hoveredScaler);
	scaledSz.setHeight(_baseButtonHeight * _hoveredScaler);
	_ui.pushButton->setFixedSize(scaledSz);
	toggleTextVisibility(true);
}

void EventButtonView::onLostFocusResizeButton()
{
	setButtonDimensions();
	toggleTextVisibility(false);
}


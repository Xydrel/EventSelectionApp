#include "EventButtonView.h"
#include "EventButtonModel.h"

#include <QPixmap>
#include <QPalette>
#include <QSize>

EventButtonView::EventButtonView(QWidget *parent)
	: QWidget(parent)
{
	_ui.setupUi(this);
	_ui.verticalLayoutWidget->installEventFilter(this);

	setButtonFrameDimensions();
	setButtonDimensions();
	bindButtonConnections();
	toggleTextVisibility(false);
}

void EventButtonView::OnButtonClicked()
{
	//TODO: Implement as extra credit if time permits
}

void EventButtonView::SetModel(const std::shared_ptr<EventButtonModel> model)
{
	_model = model;
}

void EventButtonView::Populate()
{
	_ui.verticalLayout->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

	_ui.frame->setStyleSheet("QFrame {background-position: bottom center}");

	_ui.titleHeader->setText(_model->GetHeader());
	_ui.titleHeader->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
	_ui.titleHeader->setStyleSheet("QLabel {color:rgb(211,211,211); font-weight:bold}");

	_ui.description->setText(_model->GetDescription());
	_ui.description->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
	_ui.description->setStyleSheet("QLabel {color:rgb(169,169,169)}");

	_ui.lowerDescription->setText(_model->GetLowerDescription());
	_ui.lowerDescription->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
	_ui.lowerDescription->setStyleSheet("QLabel {color:rgb(128,128,128); font-weight:italic}");

	_ui.thumbnailName->setText(_model->GetThumbnailName());
	_ui.thumbnailName->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
	_ui.thumbnailName->setStyleSheet("QLabel {color:rgb(128,128,128); font-weight:italic}");

	_ui.pushButton->setText(QString("Test text"));
	_ui.pushButton->setStyleSheet("QPushButton {border-color:rgb(105,105,105)}");

	loadButtonImage(_model->GetImagePath());
}

const QObject* EventButtonView::GetVerticalLayoutWidget() const
{
	return _ui.verticalLayoutWidget;
}

bool EventButtonView::eventFilter(const QObject* watched, const QEvent* event)
{
	if (watched == _ui.verticalLayoutWidget)
	{
		if (event->type() == QEvent::FocusIn || event->type() == QEvent::Enter)
		{
			onFocusResizeButton();
		}

		if (event->type() == QEvent::FocusOut || event->type() == QEvent::Leave)
		{
			onLostFocusResizeButton();
		}
	}

	return false;
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

void EventButtonView::bindButtonConnections()
{
	//todo: migrate to the keyboardinputcontroller so all input handling is there
	QObject::connect(_ui.pushButton, SIGNAL(clicked()), this, SLOT(OnButtonClicked()));
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
		_ui.titleHeader->show();
		_ui.description->show();
		_ui.lowerDescription->show();
		_ui.thumbnailName->show();
	}
	else
	{
		_ui.titleHeader->hide();
		_ui.description->hide();
		_ui.lowerDescription->hide();
		_ui.thumbnailName->hide();
	}
}


// Bound Slot callbacks
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


#include "MainWindowView.h"
#include "EventButtonModel.h"

#include <QSize.h>
#include <QPalette.h>
#include <QPixmap.h>
#include <QTime>
#include <QtMath>

MainWindowView::MainWindowView(QWidget *parent)
	: QMainWindow(parent)
{
	_ui.setupUi(this);
	_parent = parent;
	_bkgrndImage = std::make_unique<BackgroundImageModel>(this->size());
	
	//todo: remove if no longer needed
	/*_ui.verticalLayoutWidget->setGeometry(QRect(0, 80, 3840, 450));

	_ui.verticalLayout->setSpacing(6);
	_ui.verticalLayout->setContentsMargins(11, 11, 11, 11);
	_ui.verticalLayout->setContentsMargins(0, 0, 0, 0);
		
	_ui.scrollArea->setWidgetResizable(true);
	_ui.scrollAreaWidgetContents->setGeometry(QRect(0, 0, 3840, 450));*/

	PopulateWindowElements();
}

MainWindowView::~MainWindowView()
{
	this->releaseMouse();
	if (_parent != nullptr)
	{
		delete _parent;
		_parent = nullptr;
	}
}

void MainWindowView::PopulateWindowElements()
{
	loadBackgroundImage();
}

void MainWindowView::AddNewButtonToMenu(const std::shared_ptr<EventButtonModel> model)
{
	auto eventButton = std::make_shared<EventButtonView>(_parent);
	eventButton->SetModel(model);
	eventButton->Populate();
	eventButton->setObjectName(model->GetObjectName());
	QVBoxLayout* eventButtonVLayout = new QVBoxLayout(eventButton.get());
	eventButtonVLayout->setSpacing(6);
	eventButtonVLayout->setContentsMargins(11, 11, 11, 11);
	QString layoutObjectName = model->GetObjectName() + "VLayout";
	eventButtonVLayout->setObjectName(layoutObjectName);

	_ui.eventBarHLayout->addWidget(eventButton.get());
	_eventButtonsList.push_back(eventButton);
}

void MainWindowView::OnButtonGenerationCompleted()
{
	// to stylize the starting view the index is starting off center to the left
	qint32 buttonStartIndex = 1;
	if (_eventButtonsList.size() > 2)
	{
		buttonStartIndex = (_eventButtonsList.size() / 2 - 2);
	}

	_currentButtonIndex = buttonStartIndex;
	QEvent focusInEvent = QEvent(QEvent::Type::FocusIn);
	QApplication::sendEvent(_eventButtonsList[buttonStartIndex]->GetVerticalLayoutWidget(), &focusInEvent);
}

void MainWindowView::OnMoveSelectionLeft()
{
	if (_currentButtonIndex > 0)
	{
		QEvent focusOutEvent = QEvent(QEvent::Type::FocusOut);
		QApplication::sendEvent(_eventButtonsList[_currentButtonIndex]->GetVerticalLayoutWidget(), &focusOutEvent);
		_currentButtonIndex--;
		QEvent focusInEvent = QEvent(QEvent::Type::FocusIn);
		QApplication::sendEvent(_eventButtonsList[_currentButtonIndex]->GetVerticalLayoutWidget(), &focusInEvent);
	}
}

void MainWindowView::OnMoveSelectionRight()
{	
	if (_currentButtonIndex < _eventButtonsList.size() - 1)
	{
		QEvent focusOutEvent = QEvent(QEvent::Type::FocusOut);
		QApplication::sendEvent(_eventButtonsList[_currentButtonIndex]->GetVerticalLayoutWidget(), &focusOutEvent);
		_currentButtonIndex++;
		QEvent focusInEvent = QEvent(QEvent::Type::FocusIn);
		QApplication::sendEvent(_eventButtonsList[_currentButtonIndex]->GetVerticalLayoutWidget(), &focusInEvent);
	}
}

void MainWindowView::loadBackgroundImage()
{
	QPixmap pixmap(_bkgrndImage->GetPath());
	pixmap = pixmap.scaled(this->size(), Qt::IgnoreAspectRatio);
	_palette.setBrush(QPalette::Background, pixmap);
	this->setPalette(_palette);
}

#include "MainWindowView.h"
#include "EventButtonModel.h"

#include <QScrollArea>
#include <QScrollBar>
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

	setupButtonScrollArea();

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
	qint32 buttonStartIndex = 0;

	resizeHorizontalLayoutToFitButtons();

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

		_scrollArea->ensureWidgetVisible(_eventButtonsList[_currentButtonIndex].get());
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

		_scrollArea->ensureWidgetVisible(_eventButtonsList[_currentButtonIndex].get());
	}
}

void MainWindowView::setupButtonScrollArea()
{
	_scrollArea = std::make_shared<QScrollArea>();
	this->setCentralWidget(_scrollArea.get());
	_scrollArea->setWidget(_ui.layoutWidget);
	_scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	_scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void MainWindowView::loadBackgroundImage()
{
	QPixmap pixmap(_bkgrndImage->GetPath());
	pixmap = pixmap.scaled(this->size(), Qt::IgnoreAspectRatio);
	_palette.setBrush(QPalette::Background, pixmap);
	this->setPalette(_palette);
}

void MainWindowView::resizeHorizontalLayoutToFitButtons()
{
	qint32 eventBarButtonspacingSize = 220;
	_ui.layoutWidget->setFixedWidth(_eventButtonsList.size() * eventBarButtonspacingSize);
}

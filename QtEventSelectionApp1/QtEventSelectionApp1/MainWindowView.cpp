#include "MainWindowView.h"
#include "EventButtonModel.h"

#include <QSize.h>
#include <QPalette.h>
#include <QPixmap.h>


MainWindowView::MainWindowView(QWidget *parent)
	: QMainWindow(parent)
{
	_ui.setupUi(this);
	_parent = parent;
	_bkgrndImage = std::make_unique<BackgroundImageModel>(this->size());

	PopulateWindowElements();
}

void MainWindowView::PopulateWindowElements()
{
	loadBackgroundImage();
}

void MainWindowView::AddNewButtonToMenu(std::shared_ptr<EventButtonModel> model)
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
	_titleButtonList.push_back(eventButton);
}

void MainWindowView::OnMoveSelectionLeft()
{

}

void MainWindowView::OnMoveSelectionRight()
{

}

void MainWindowView::loadBackgroundImage()
{
	QPixmap pixmap(_bkgrndImage->GetPath());
	pixmap = pixmap.scaled(this->size(), Qt::IgnoreAspectRatio);
	_palette.setBrush(QPalette::Background, pixmap);
	this->setPalette(_palette);
}

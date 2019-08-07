#include "MainWindowController.h"
#include "MainWindowView.h"
#include "EventButtonModel.h"

#include <QDateTime>

MainWindowController::MainWindowController(MainWindowView& view)
{
	_mainWinView = std::make_unique<MainWindowView>(&view);
	_netAccessMngr = std::make_shared<QNetworkAccessManager>();

	auto datesList = GetButtonDatesList();
	GenerateButtonModelsFromDates(datesList);
}

void MainWindowController::Show()
{
	_mainWinView->show();
}

std::shared_ptr<QList<QString>> MainWindowController::GetButtonDatesList()
{
	// Getting the date and subtracting 4 from it so the menu buttons start 4 days before today
	auto dateList = std::make_shared<QList<QString>>();
	QDate todaysDate = QDate::currentDate();
	todaysDate = todaysDate.addDays(-3);

	for (int i = 0; i < 10; ++i)
	{
		QString dateToAdd = "";
		std::string year = std::to_string(todaysDate.year());
		std::string month = (todaysDate.month() > 9) ? std::to_string(todaysDate.month()) : "0" + std::to_string(todaysDate.month());
		std::string day = (todaysDate.day() > 9) ? std::to_string(todaysDate.day()) : "0" + std::to_string(todaysDate.day());

		dateToAdd = QString::fromStdString(year + "-" + month + "-" + day);

		dateList->push_back(dateToAdd);
		todaysDate = todaysDate.addDays(1);
	}

	return dateList;
}

void MainWindowController::GenerateButtonModelsFromDates(const std::shared_ptr<QList<QString>> datesList)
{
	if (_mainWinView != nullptr)
	{
		_requestsObjMap = std::make_unique<QMap<const QString, std::shared_ptr<JsonRequestModel>>>();
		for (auto i = 0; i < datesList->size(); i++)
		{
			//todo: complete functionality for json request
			auto jsonRequest = std::make_shared<JsonRequestModel>();
			jsonRequest->MakeUrlJsonRequest(_netAccessMngr, datesList->at(i));
			//todo: add request object to map ? is this needed?

			auto btnDataModel = std::make_shared<EventButtonModel>();
			btnDataModel->SetObjectName(datesList->at(i));
			btnDataModel->SetImagePath(datesList->at(i) + "/test/image/path");
			btnDataModel->SetHeaderText(datesList->at(i) + " Header");
			btnDataModel->SetDescriptionText(datesList->at(i) + " Description Text");
			btnDataModel->SetLowerDescriptionText(datesList->at(i) + " Lower Description Text");
			btnDataModel->SetThumbnailNameText(datesList->at(i) + " The Thumbnail");

			AddButtonToMenu(btnDataModel);
		}
	}
}

void MainWindowController::AddButtonToMenu(const std::shared_ptr<EventButtonModel> model)
{
	_mainWinView->AddNewButtonToMenu(model);
}



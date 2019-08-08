#include "MainWindowController.h"
#include "MainWindowView.h"
#include "EventButtonModel.h"

#include <QDateTime>

MainWindowController::MainWindowController(std::shared_ptr<MainWindowView> mainWin, QObject* parent)
	: QObject(parent)
{
	_mainWinView = mainWin;
	_keyboardInputCntrlr = std::make_unique<KeyboardInputController>(_mainWinView);

	_mainWinView->installEventFilter(_keyboardInputCntrlr.get());

	bindCallbackEvents();

	auto datesList = getButtonDatesList();
	generateButtonModelsFromDates(datesList);
}

void MainWindowController::Show()
{
	_mainWinView->show();
}

//todo: refactor as the requirement is to generate based on games recieved from the json not dates
//this method may still be usfull for generating adjacent days and then storing the json info to disk for recall
std::shared_ptr<QList<QString>> MainWindowController::getButtonDatesList()
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

void MainWindowController::generateButtonModelsFromDates(const std::shared_ptr<QList<QString>> datesList)
{
	if (_mainWinView != nullptr)
	{
		_requestsObjList = std::make_unique<QList<std::shared_ptr<JsonRequestModel>>>();

		//todo: instead of generating buttons by a list of dates they need to be generated by the returned json data
		for (auto i = 0; i < datesList->size(); i++)
		{
			//todo: complete functionality for json request
			// this also needs to be made into just one call to get the games out
			auto jsonRequest = std::make_shared<JsonRequestModel>();
			jsonRequest->MakeUrlJsonRequest(datesList->at(i));
			_requestsObjList->push_back(jsonRequest);
			//todo: add request object to map ? is this needed?

			auto btnDataModel = std::make_shared<EventButtonModel>();
			btnDataModel->SetObjectName(datesList->at(i));
			btnDataModel->SetImagePath("/test/image/path");
			btnDataModel->SetHeaderText(datesList->at(i) + " Header");
			btnDataModel->SetDescriptionText("Description Text");
			btnDataModel->SetLowerDescriptionText("Lower Description Text");
			btnDataModel->SetThumbnailNameText("The Thumbnail");

			addButtonToMenu(btnDataModel);
		}

		sendButtonGenerationCompleteSignal();

	}
}

void MainWindowController::addButtonToMenu(const std::shared_ptr<EventButtonModel> model)
{
	_mainWinView->AddNewButtonToMenu(model);
}

void MainWindowController::bindCallbackEvents()
{
	QObject::connect(this, SIGNAL(sendButtonGenerationCompleteSignal()), _mainWinView.get(), SLOT(OnButtonGenerationCompleted()));
}



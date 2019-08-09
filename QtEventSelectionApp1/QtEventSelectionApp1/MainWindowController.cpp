#include "MainWindowController.h"
#include "MainWindowView.h"
#include "EventButtonModel.h"

#include <QDateTime>
#include <QJsonObject>

MainWindowController::MainWindowController(std::shared_ptr<MainWindowView> mainWin, QObject* parent)
	: QObject(parent)
{
	_mainWinView = mainWin;
	_keyboardInputComp = std::make_unique<KeyboardInputComponent>(_mainWinView);
	_httpRequestComponent = std::make_shared<HTTPRequestComponent>(this);

	_mainWinView->installEventFilter(_keyboardInputComp.get());

	bindMainWindowControllerCallbackEvents();

	QString formattedDate = getTodaysFormattedDate();
	invokeJsonRequest(formattedDate);
}

void MainWindowController::Show()
{
	_mainWinView->show();
}

void MainWindowController::OnJsonParseComplete()
{
	const QJsonArray& gamesArray = _httpRequestComponent->GetJsonGamesArray();
	generateButtonModelsFromGamesData(gamesArray);
}

void MainWindowController::bindMainWindowControllerCallbackEvents()
{
	QObject::connect(this, SIGNAL(notifyButtonGenerationCompleteSignal()), _mainWinView.get(), SLOT(OnButtonGenerationCompleted()));
	QObject::connect(_httpRequestComponent.get(), SIGNAL(notifyJsonParseComplete()), this, SLOT(OnJsonParseComplete()));
}

//todo: Extra credit code for loading the adjacent dates json
const std::shared_ptr<QList<QString>> MainWindowController::getTodayAndAdjacentDatesList() const
{
	auto dateList = std::make_shared<QList<QString>>();
	QDate todaysDate = QDate::currentDate();
	todaysDate = todaysDate.addDays(-1);

	for (int i = 0; i < 3; ++i)
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

const QString MainWindowController::getTodaysFormattedDate() const
{
	QDate todaysDate = QDate::currentDate();
	std::string year = std::to_string(todaysDate.year());
	std::string month = (todaysDate.month() > 9) ? std::to_string(todaysDate.month()) : "0" + std::to_string(todaysDate.month());
	std::string day = (todaysDate.day() > 9) ? std::to_string(todaysDate.day()) : "0" + std::to_string(todaysDate.day());

	return QString::fromStdString(year + "-" + month + "-" + day);
}

void MainWindowController::invokeJsonRequest(const QString& formattedDate)
{
	_httpRequestComponent->MakeUrlJsonRequest(formattedDate);
}

void MainWindowController::generateButtonModelsFromGamesData(const QJsonArray& gamesArr)
{
	if (!gamesArr.isEmpty())
	{
		// Generate the buttons from the data collected from the json request
		for (auto i = 0; i < gamesArr.size(); i++)
		{
			QJsonObject json = gamesArr.at(i).toObject();
			QVariantMap varMapFromJson = json.toVariantMap();

			auto btnDataModel = std::make_shared<EventButtonModel>();
			btnDataModel->SetObjectName(varMapFromJson["gamePk"].toString());
			btnDataModel->SetImagePath("/test/image/path");
			QVariantMap teamsVarMapFromJson = varMapFromJson["teams"].toJsonObject().toVariantMap();
			QVariantMap homeTeamVarMap = teamsVarMapFromJson["home"].toJsonObject().toVariantMap()["team"].toJsonObject().toVariantMap();
			QVariantMap awayTeamVarMap = teamsVarMapFromJson["away"].toJsonObject().toVariantMap()["team"].toJsonObject().toVariantMap();
			btnDataModel->SetHeaderText(homeTeamVarMap["name"].toString() + " vs. \n" + awayTeamVarMap["name"].toString());
			btnDataModel->SetDescriptionText("Season " + varMapFromJson["season"].toString());
			btnDataModel->SetLowerDescriptionText("At: " + varMapFromJson["venue"].toJsonObject().toVariantMap()["name"].toString());
			btnDataModel->SetBottomDescriptionText("Game Time: " + varMapFromJson["dayNight"].toString());

			addButtonToMenu(btnDataModel);
		}

		notifyButtonGenerationCompleteSignal();
	}
}

void MainWindowController::addButtonToMenu(const std::shared_ptr<EventButtonModel> model)
{
	_mainWinView->AddNewButtonToMenu(model);
}




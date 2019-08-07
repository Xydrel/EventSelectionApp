#pragma once
#include <memory>

#include "JsonRequestModel.h"
#include "KeyboardInputController.h"

#include <QNetworkAccessManager>
#include <QList>
#include <QString>

class MainWindowView;
class EventButtonModel;

class MainWindowController
{
public:
	MainWindowController(MainWindowView& view);
	MainWindowController() = delete;
	~MainWindowController() = default;

	MainWindowController(const MainWindowController&) = delete;
	MainWindowController& operator=(const MainWindowController&) = delete;

	void Show();

private:
	std::shared_ptr<QList<QString>> GetButtonDatesList();
	void GenerateButtonModelsFromDates(const std::shared_ptr<QList<QString>> datesList);
	void AddButtonToMenu(const std::shared_ptr<EventButtonModel> model);

private:
	std::shared_ptr<MainWindowView> _mainWinView;
	//todo: ? is this needed?
	std::unique_ptr<QMap<const QString, std::shared_ptr<JsonRequestModel>>> _requestsObjMap;
	std::shared_ptr<QNetworkAccessManager> _netAccessMngr;
	std::unique_ptr<KeyboardInputController> _keyboardInputCntrlr;
};


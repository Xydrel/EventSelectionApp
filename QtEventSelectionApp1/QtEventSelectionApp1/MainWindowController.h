#pragma once
#include <memory>

#include "JsonRequestModel.h"
#include "KeyboardInputController.h"

#include <QNetworkAccessManager>
#include <QList>
#include <QString>

class MainWindowView;
class EventButtonModel;

class MainWindowController : public QObject
{
	Q_OBJECT

public:
	MainWindowController(std::shared_ptr<MainWindowView> mainWin, QObject* parent = Q_NULLPTR);
	MainWindowController() = delete;
	~MainWindowController() = default;

	MainWindowController(const MainWindowController&) = delete;
	MainWindowController& operator=(const MainWindowController&) = delete;

	void Show();

private:
	void bindCallbackEvents();
	std::shared_ptr<QList<QString>> GetButtonDatesList();
	void GenerateButtonModelsFromDates(const std::shared_ptr<QList<QString>> datesList);
	void AddButtonToMenu(const std::shared_ptr<EventButtonModel> model);

signals:
	void sendButtonGenerationCompleteSignal();

private:
	std::shared_ptr<MainWindowView> _mainWinView;
	//todo: ? is this needed?
	std::unique_ptr<QList<std::shared_ptr<JsonRequestModel>>> _requestsObjList;
	std::unique_ptr<KeyboardInputController> _keyboardInputCntrlr;
};


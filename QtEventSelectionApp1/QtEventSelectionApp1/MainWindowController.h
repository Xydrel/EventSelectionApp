#pragma once
#include <memory>

#include "HTTPRequestComponent.h"
#include "KeyboardInputComponent.h"

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

public slots:
	void OnJsonParseComplete();

private:
	void bindMainWindowControllerCallbackEvents();
	const std::shared_ptr<QList<QString>> getTodayAndAdjacentDatesList() const;
	const QString getTodaysFormattedDate() const;
	void invokeJsonRequest(const QString& formattedDate);
	void generateButtonModelsFromGamesData(const QJsonArray& gamesArr);
	void addButtonToMenu(const std::shared_ptr<EventButtonModel> model);

signals:
	void notifyButtonGenerationCompleteSignal();

private:
	std::shared_ptr<MainWindowView> _mainWinView;
	std::unique_ptr<KeyboardInputComponent> _keyboardInputComp;
	std::shared_ptr<HTTPRequestComponent> _httpRequestComponent;
};


#pragma once

#include <QObject>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QJsonArray>

class MainWindowController;
class QNetworkReply;
class QJsonArray;

class HTTPRequestComponent : public QObject
{
	Q_OBJECT

public:
	HTTPRequestComponent(MainWindowController* mainWinCntrl, QObject* parent = Q_NULLPTR);
	~HTTPRequestComponent();

	HTTPRequestComponent(const HTTPRequestComponent&) = delete;
	HTTPRequestComponent& operator=(const HTTPRequestComponent&) = delete;

	// expected date format: yyyy-mm-dd
	void MakeUrlJsonRequest(const QString& date);
	const QJsonArray& GetJsonGamesArray();

private:
	void bindJsonRequestModelCallbackEvents();

private slots:
	void onJsonRequestFinnished(QNetworkReply* reply);

signals:
	void notifyJsonParseComplete();

private:
	MainWindowController* _mainWindController;
	std::unique_ptr<QNetworkAccessManager> _netAccessMngr;
	QJsonArray _gamesArray;
};

#pragma once

#include <QObject>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QJsonArray>

class MainWindowController;
class QNetworkReply;
class QJsonArray;

class JsonRequestModel : public QObject
{
	Q_OBJECT

public:
	JsonRequestModel(MainWindowController* mainWinCntrl, QObject* parent = Q_NULLPTR);
	~JsonRequestModel();

	JsonRequestModel(const JsonRequestModel&) = delete;
	JsonRequestModel& operator=(const JsonRequestModel&) = delete;

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

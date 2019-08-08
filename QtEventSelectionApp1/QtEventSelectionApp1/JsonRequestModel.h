#pragma once

#include <QObject>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QJsonArray>

class QNetworkReply;
class QJsonArray;

class JsonRequestModel : public QObject
{
	Q_OBJECT

public:
	JsonRequestModel(QObject* parent = Q_NULLPTR);
	~JsonRequestModel() = default;

	JsonRequestModel(const JsonRequestModel&) = delete;
	JsonRequestModel& operator=(const JsonRequestModel&) = delete;

	// expected date format: yyyy-mm-dd
	void MakeUrlJsonRequest(const QString& date);
	QJsonArray& GetJsonGamesArray();

private:
	

private slots:
	void onJsonRequestFinnished(QNetworkReply* reply);

signals:
	void notifyJsonParseComplete();

private:
	std::unique_ptr<QNetworkAccessManager> _netAccessMngr;
	QJsonArray _gamesArray;
};

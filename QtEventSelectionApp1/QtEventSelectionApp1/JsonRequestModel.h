#pragma once

#include <QWidget>
#include <QNetworkAccessManager>
#include <QUrl>

class QNetworkReply;

class JsonRequestModel : public QWidget
{
	Q_OBJECT

public:
	JsonRequestModel(QWidget* parent = Q_NULLPTR);
	~JsonRequestModel() = default;

	JsonRequestModel(const JsonRequestModel&) = delete;
	JsonRequestModel& operator=(const JsonRequestModel&) = delete;

	// expected date format: yyyy-mm-dd
	void MakeUrlJsonRequest(std::shared_ptr<QNetworkAccessManager> netAccessMngr, const QString& date);

private slots:
	void parseNetworkRequestReply(QNetworkReply* reply);

private:
	std::unique_ptr<QNetworkAccessManager> _netAccessMngr;
};

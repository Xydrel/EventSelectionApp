#include "JsonRequestModel.h"

#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>

//TODO: validate all these are needed and remove the ones that are not
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

JsonRequestModel::JsonRequestModel(QWidget* parent)
	: QWidget(parent)
{
	_netAccessMngr = std::make_unique<QNetworkAccessManager>();
}

void JsonRequestModel::MakeUrlJsonRequest(const QString& date)
{
	QUrl requestUrl = QUrl("http://statsapi.mlb.com/api/v1/schedule", QUrl::StrictMode);
	QUrlQuery query;
	query.addQueryItem("hydrate", "game(content(editorial(recap))),decisions");
	query.addQueryItem("date", date);
	query.addQueryItem("sportId", "1");

	requestUrl.setQuery(query.query());
	qDebug() << "query url = " + requestUrl.toString();

	_netAccessMngr->clearConnectionCache();
	if (_netAccessMngr->networkAccessible())
	{
		QObject::connect(_netAccessMngr.get(), SIGNAL(finished(QNetworkReply*)), this, SLOT(onJsonRequestFinnished(QNetworkReply*)));

		QNetworkRequest request;
		request.setUrl(requestUrl);
		request.setRawHeader("host", "statsapi.mlb.com");
		request.setRawHeader("Content-Type", "application/json");
		
		QNetworkReply* reply = _netAccessMngr->get(request);
	}

	_netAccessMngr->clearAccessCache();
}

void JsonRequestModel::onJsonRequestFinnished(QNetworkReply* reply)
{
	qDebug() << "Entered into parseNetworkRequestReply callback";

	switch (reply->error())
	{
		case QNetworkReply::AuthenticationRequiredError:
		{
			qDebug() << "AuthenticationRequiredError";
			break;
		}
		case QNetworkReply::ConnectionRefusedError:
		{
			qDebug() << "ConnectionRefusedError";
			break;
		}
		case QNetworkReply::HostNotFoundError:
		{
			qDebug() << "HostNotFoundError";
			break;
		}
		case QNetworkReply::TimeoutError:
		{
			qDebug() << "TimeoutError";
			break;
		}
		case QNetworkReply::OperationCanceledError:
		{
			qDebug() << "OperationCanceledError";
			break;
		}
		case QNetworkReply::NoError:
		{
			qDebug() << "QNetworkReply::NoError";

			QString strReply = QString(reply->readAll());
			qDebug() << strReply;
			
			QJsonObject jsonObj = QJsonDocument::fromJson(reply->readAll()).object();

			/* some code demonstrating  how to parse json for later once a response is received
			//parse the reply JSON and display result in the UI

			QString fullName= jsonObj["name"].toString();
			fullName.append(" ");
			fullName.append(jsonObj["surname"].toString());
			lineEditName.setText(fullName);
			lineEditGender.setText(jsonObj["gender"].toString());
			lineEditRegion.setText(jsonObj["region"].toString());
			*/

			break;
		}
		default:
		{
			qDebug() << "There was an unknown reply error type";
			break;
		}
	}

	reply->deleteLater();
}




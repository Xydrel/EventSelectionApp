#include "JsonRequestModel.h"

#include <QNetworkRequest>
#include <QNetworkReply>
#include <QThread>

//TODO: validate all these are needed and remove the ones that are not
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

JsonRequestModel::JsonRequestModel(QWidget* parent)
	: QWidget(parent)
{
}

void JsonRequestModel::MakeUrlJsonRequest(const QString& date)
{
	QString urlString = QString("http://statsapi.mlb.com/api/v1/schedule?hydrate=game(content(editorial(recap))),decisions&date=" + date + "&sportId=1");
	qDebug() << "urlString = " + urlString;	

	QNetworkAccessManager networkManager;
	networkManager.moveToThread(QThread::currentThread());

	QObject::connect(&networkManager, SIGNAL(finished(QNetworkReply*)),
		this, SLOT(parseNetworkRequestReply(QNetworkReply*)));

	if (networkManager.networkAccessible())
	{
		QNetworkRequest request(QUrl(urlString, QUrl::TolerantMode));
		qDebug() << "request stored URL = " + request.url().toDisplayString();
		request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
		request.setRawHeader("Host", "statsapi.mlb.com");
				
		QNetworkReply* reply = networkManager.get(request);
		reply->waitForReadyRead(20 * 100);

		//todo: resolve currently infinite loop caused by the reply always being in a running state
		//while (reply->isRunning())
		//{
		//	if (reply->isFinished())
		//	{
		//		parseNetworkRequestReply(reply);
		//	}
		//}

		reply->deleteLater();
	}
}

void JsonRequestModel::parseNetworkRequestReply(QNetworkReply* reply)
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
			qDebug() << "Printing string from read all";
			qDebug() << strReply;

			QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
			QJsonObject jsonObj = jsonResponse.object();
			break;
		}
		default:
		{
			qDebug() << "There was an unknown reply error type";
			break;
		}
	}

	//todo: debug code remove 
	qint64 availBytes = reply->bytesAvailable();
	if (availBytes > 0)
	{
		qDebug() << "There are some bytes avail";
	}

	if (QString(reply->readAll()) == "")
	{
		qDebug() << "ERROR: The QNetworkReply was empty!";
	}
	//todo: end remove debug code

}




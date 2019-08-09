#include "JsonRequestModel.h"
#include "MainWindowController.h"

#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>

JsonRequestModel::JsonRequestModel(MainWindowController* mainWinCntrl, QObject* parent)
	: QObject(parent)
{
	_mainWindController = mainWinCntrl;
	_netAccessMngr = std::make_unique<QNetworkAccessManager>();
	
	bindJsonRequestModelCallbackEvents();
}

JsonRequestModel::~JsonRequestModel()
{
	if (_mainWindController != nullptr)
	{
		_mainWindController = nullptr;
	}
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

		QNetworkRequest request;
		request.setUrl(requestUrl);
		request.setRawHeader("host", "statsapi.mlb.com");
		request.setRawHeader("Content-Type", "application/json");
		
		_netAccessMngr->get(request);
	}

	_netAccessMngr->clearAccessCache();
}

const QJsonArray& JsonRequestModel::GetJsonGamesArray()
{
	return _gamesArray;
}

void JsonRequestModel::bindJsonRequestModelCallbackEvents()
{
		QObject::connect(_netAccessMngr.get(), SIGNAL(finished(QNetworkReply*)), this, SLOT(onJsonRequestFinnished(QNetworkReply*)));
		QObject::connect(this, SIGNAL(notifyJsonParseComplete()), _mainWindController, SLOT(onJsonRequestFinnished()));
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
			
			QJsonParseError jsonError;
			QJsonDocument jsonDoc = QJsonDocument::fromJson(strReply.toUtf8(), &jsonError);
			if (jsonError.error != QJsonParseError::NoError)
			{
				qDebug() << "ERROR reading string to json: " + jsonError.errorString();
				break;
			}

			QJsonObject jsonObj = jsonDoc.object();
			QJsonObject::Iterator itr = jsonObj.begin();
			for (; itr != jsonObj.end(); itr++)
			{
				if (itr.key() == "dates")
				{
					QJsonArray datesArr = itr.value().toArray();
					for (const auto item : datesArr)
					{
						QJsonObject datesObject = item.toObject();
						QJsonObject::Iterator datesIter = datesObject.begin();
						for (; datesIter != item.toObject().end(); datesIter++)
						{
							if (datesIter.key() == "games")
							{
								_gamesArray = datesIter.value().toArray();
							}
						}
					}
				}
			}
			break;
		}
		default:
		{
			qDebug() << "There was an unknown reply error type";
			break;
		}
	}

	reply->deleteLater();

	// must remain last call after all processing
	notifyJsonParseComplete();
}




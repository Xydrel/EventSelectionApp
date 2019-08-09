#pragma once
#include <QString>

class EventButtonModel
{
public:
	EventButtonModel(QString objName, QString imagePath, QString header,
					 QString description, QString lowerDesc, QString thumbnailName);
	EventButtonModel() = default;
	~EventButtonModel() = default;

	EventButtonModel(const EventButtonModel&) = delete;
	EventButtonModel& operator=(const EventButtonModel&) = delete;

	const QString& GetObjectName() const;
	void SetObjectName(QString name);

	const QString& GetImagePath() const;
	void SetImagePath(QString pathStr);

	const QString& GetHeader() const;
	void SetHeaderText(QString text);

	const QString& GetDescription() const;
	void SetDescriptionText(QString text);

	const QString& GetLowerDescription() const;
	void SetLowerDescriptionText(QString text);

	const QString& GetBottomeDescription() const;
	void SetBottomDescriptionText(QString text);

private:
	QString _objectName;
	QString _imagePath;
	QString _header;
	QString _description;
	QString _lowerDesc;
	QString _bottomDescription;
};


#include "EventButtonModel.h"



EventButtonModel::EventButtonModel(QString objName, QString imagePath, QString header, 
								   QString description, QString lowerDesc, QString thumbnailName) 
	:
	_objectName(objName),
	_imagePath(imagePath),
	_header(header),
	_description(description),
	_lowerDesc(lowerDesc),
	_bottomDescription(thumbnailName)
{

}

const QString & EventButtonModel::GetObjectName() const
{
	return _objectName;
}

void EventButtonModel::SetObjectName(QString name)
{
	_objectName = name;
}

const QString & EventButtonModel::GetImagePath() const
{
	return _imagePath;
}

void EventButtonModel::SetImagePath(QString pathStr)
{
	_imagePath = pathStr;
}

const QString & EventButtonModel::GetHeader() const
{
	return _header;
}

void EventButtonModel::SetHeaderText(QString text)
{
	_header = text;
}

const QString & EventButtonModel::GetDescription() const
{
	return _description;
}

void EventButtonModel::SetDescriptionText(QString text)
{
	_description = text;
}

const QString & EventButtonModel::GetLowerDescription() const
{
	return _lowerDesc;
}

void EventButtonModel::SetLowerDescriptionText(QString text)
{
	_lowerDesc = text;
}

const QString & EventButtonModel::GetBottomeDescription() const
{
	return _bottomDescription;
}

void EventButtonModel::SetBottomDescriptionText(QString text)
{
	_bottomDescription = text;
}

#include "BackgroundImageModel.h"

BackgroundImageModel::BackgroundImageModel()
{
}

BackgroundImageModel::BackgroundImageModel(QSize winSize)
{
	_path = "Assets/Images/AppBackground.jpg";
	_size = winSize;
}

QString & BackgroundImageModel::GetPath()
{
	return _path;
}

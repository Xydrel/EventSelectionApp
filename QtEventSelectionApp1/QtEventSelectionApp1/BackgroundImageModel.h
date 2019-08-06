#pragma once

#include <QString>
#include <QSize>

class BackgroundImageModel
{
public:
	BackgroundImageModel();
	BackgroundImageModel(QSize winSize);
	~BackgroundImageModel() = default;

	BackgroundImageModel(const BackgroundImageModel&) = delete;
	BackgroundImageModel& operator=(const BackgroundImageModel&) = delete;

	QString& GetPath();

private:
	QString _path;
	QSize _size;
};

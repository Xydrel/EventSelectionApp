#pragma once

#include <QWidget>
#include "ui_EventButtonView.h"

class EventButtonView : public QWidget
{
	Q_OBJECT

public:
	EventButtonView(QWidget *parent = Q_NULLPTR);
	~EventButtonView();

private:
	Ui::EventButtonView ui;
};

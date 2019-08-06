#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindowView.h"

class MainWindowView : public QMainWindow
{
	Q_OBJECT

public:
	MainWindowView(QWidget *parent = Q_NULLPTR);

private:
	Ui::MainWindowViewClass ui;
};

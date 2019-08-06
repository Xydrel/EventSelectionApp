#include "MainWindowController.h"
#include "MainWindowView.h"

#include <QDateTime>

MainWindowController::MainWindowController(MainWindowView& view)
{
	_mainWindow = std::make_unique<MainWindowView>(&view);

	auto datesList = GetButtonDates();
	GenerateButtonsForMenuBar(datesList);
}

void MainWindowController::Show()
{
	_mainWindow->show();
}

std::shared_ptr<QList<QString>> MainWindowController::GetButtonDates()
{
	// Getting the date and subtracting 4 from it so the menu buttons start 4 days before today
	auto dateList = std::make_shared<QList<QString>>();
	QDate todaysDate = QDate::currentDate();
	todaysDate = todaysDate.addDays(-3);

	for (int i = 0; i < 10; ++i)
	{
		QString dateToAdd = "";
		auto year = std::to_string(todaysDate.year());
		auto month = (todaysDate.month() > 9) ? std::to_string(todaysDate.month()) : "0" + std::to_string(todaysDate.month());
		auto day = (todaysDate.day() > 9) ? std::to_string(todaysDate.day()) : "0" + std::to_string(todaysDate.day());

		dateToAdd = QString::fromStdString(year + "-" + month + "-" + day);

		dateList->push_back(dateToAdd);
		todaysDate = todaysDate.addDays(1);
	}

	return dateList;
}

void MainWindowController::GenerateButtonsForMenuBar(std::shared_ptr<QList<QString>> datesList)
{
	//TODO: Implement me!
}

void MainWindowController::AddButtonToMenu(std::shared_ptr<EventButtonModel> data)
{
	//TODO: Implement me!
}



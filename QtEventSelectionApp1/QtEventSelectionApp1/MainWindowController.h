#pragma once
#include <memory>

#include <QList>
#include <QString>

class MainWindowView;
class EventButtonModel;

class MainWindowController
{
public:
	MainWindowController(MainWindowView& view);
	MainWindowController() = delete;
	~MainWindowController() = default;

	MainWindowController(const MainWindowController&) = delete;
	MainWindowController& operator=(const MainWindowController&) = delete;

	void Show();

private:
	std::shared_ptr<QList<QString>> GetButtonDates();
	void GenerateButtonsForMenuBar(std::shared_ptr<QList<QString>> datesList);
	void AddButtonToMenu(std::shared_ptr<EventButtonModel> model);

private:
	std::unique_ptr<MainWindowView> _mainWinView;

};


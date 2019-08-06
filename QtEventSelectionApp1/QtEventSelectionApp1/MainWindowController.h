#pragma once
#include <memory>

class MainWindowView;

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

private:
	std::unique_ptr<MainWindowView> _mainWindow;

};


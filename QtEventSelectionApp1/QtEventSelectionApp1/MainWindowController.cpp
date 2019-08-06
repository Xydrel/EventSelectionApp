#include "MainWindowController.h"
#include "MainWindowView.h"


MainWindowController::MainWindowController(MainWindowView& view)
{
	_mainWindow = std::make_unique<MainWindowView>(&view);
}

void MainWindowController::Show()
{
	_mainWindow->show();
}



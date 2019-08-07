#include "MainWindowView.h"
#include "MainWindowController.h"

#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	auto w = std::make_shared<MainWindowView>();
	auto mainWindowContoler = std::make_unique<MainWindowController>(w);
	mainWindowContoler->Show();

	return a.exec();
}

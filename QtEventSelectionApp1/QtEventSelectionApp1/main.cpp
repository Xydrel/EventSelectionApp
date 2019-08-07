#include "MainWindowView.h"
#include "MainWindowController.h"

#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	a.setOverrideCursor(Qt::BlankCursor);

	auto w = std::make_shared<MainWindowView>();
	w->grabMouse();

	auto mainWindowContoler = std::make_unique<MainWindowController>(w);
	mainWindowContoler->Show();

	return a.exec();
}

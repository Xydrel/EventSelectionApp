#include "MainWindowView.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindowView w;
	w.show();
	return a.exec();
}

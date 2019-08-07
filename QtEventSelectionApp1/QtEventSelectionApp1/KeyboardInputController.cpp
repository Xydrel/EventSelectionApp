#include "KeyboardInputController.h"

#include <QApplication>

KeyboardInputController::KeyboardInputController(QObject* parent)
	: QObject(parent)
{
}

bool KeyboardInputController::eventFilter(QObject* watched, QEvent* event)
{
	//if (event->type() == QEvent::KeyPress)
	//{
		QKeyEvent* keyEvent = dynamic_cast<QKeyEvent*>(event);
		if (keyEvent != nullptr)
		{
			switch (keyEvent->key())
			{
				case Qt::Key_Escape:
				{
					QApplication::quit();
					return true;
				}
				case Qt::Key_Left:
				{
					//todo: call chain to move the selection left
					return true;
				}			
				case Qt::Key_Right:
				{
					//todo: call chain to move the selection right
					return true;
				}
				default:
					return false;
			}
		}
	//}
	return false;
}

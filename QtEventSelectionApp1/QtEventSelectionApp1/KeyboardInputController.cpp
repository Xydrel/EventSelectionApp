#include "KeyboardInputController.h"
#include "MainWindowView.h"

#include <QApplication>

KeyboardInputController::KeyboardInputController(QObject* parent, std::shared_ptr<MainWindowView> mainWin)
	: QObject(parent)
{
	_mainWinView = mainWin;

	bindKeyboardInputSignalCallbacks();
}

bool KeyboardInputController::eventFilter(QObject* watched, QEvent* event)
{
	QKeyEvent* keyEvent = dynamic_cast<QKeyEvent*>(event);
	if (keyEvent != nullptr)
	{
		switch (keyEvent->key())
		{
			case Qt::Key_Escape:
			{
				onEscapeKeyPressed();
				return true;
			}
			case Qt::Key_Left:
			{
				onLeftKeyPressed();
				return true;
			}			
			case Qt::Key_Right:
			{
				onRightKeyPressed();
				return true;
			}
			default:
				return false;
		}
	}
	return false;
}

void KeyboardInputController::bindKeyboardInputSignalCallbacks()
{
	QObject::connect(this, SIGNAL(onLeftKeyPressed()), _mainWinView.get(), SLOT(OnMoveSelectionLeft()));
	QObject::connect(this, SIGNAL(onRightKeyPressed()), _mainWinView.get(), SLOT(OnMoveSelectionRight()));
}

void KeyboardInputController::onEscapeKeyPressed()
{
		QApplication::quit();
}


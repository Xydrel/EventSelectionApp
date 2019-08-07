#include "KeyboardInputController.h"
#include "MainWindowView.h"

#include <QApplication>

KeyboardInputController::KeyboardInputController(std::shared_ptr<MainWindowView> mainWin, QObject* parent)
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
				sendLeftKeyPressedSignal();
				return true;
			}			
			case Qt::Key_Right:
			{
				sendRightKeyPressedSignal();
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
	QObject::connect(this, SIGNAL(sendLeftKeyPressedSignal()), _mainWinView.get(), SLOT(OnMoveSelectionLeft()));
	QObject::connect(this, SIGNAL(sendRightKeyPressedSignal()), _mainWinView.get(), SLOT(OnMoveSelectionRight()));
}

void KeyboardInputController::onEscapeKeyPressed()
{
		QApplication::quit();
}


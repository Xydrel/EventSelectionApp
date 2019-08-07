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
	/* note: for some reason which needs further investigation 
	 * KeyPress events do not apply to arrow keys. If events are 
	 * not being filtered by KeyPress events double movement 
	 * navigation across event menu buttons. */
	if (keyEvent != nullptr && keyEvent->type() == QEvent::Type::KeyPress)
	{
		switch (keyEvent->key())
		{
			case Qt::Key_Escape:
			{
				onEscapeKeyPressed();
				return false;
			}
			//todo: investigate further
			case Qt::Key_Left:
			{
				sendLeftKeyPressedSignal();
				return false;
			}			
			case Qt::Key_Right:
			{
				sendRightKeyPressedSignal();
				return false;
			}
			//todo: end investigate further
			case Qt::Key_S:
			{
				sendLeftKeyPressedSignal();
				return false;
			}
			case Qt::Key_F:
			{
				sendRightKeyPressedSignal();
				return false;
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


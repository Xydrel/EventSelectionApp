#include "KeyboardInputComponent.h"
#include "MainWindowView.h"

#include <QApplication>

KeyboardInputComponent::KeyboardInputComponent(std::shared_ptr<MainWindowView> mainWin, QObject* parent)
	: QObject(parent)
{
	_mainWinView = mainWin;

	bindKeyboardInputSignalCallbacks();
}

bool KeyboardInputComponent::eventFilter(QObject* watched, QEvent* event)
{
	QKeyEvent* keyEvent = dynamic_cast<QKeyEvent*>(event);
	/* note: Not using Arrow keys as they are events related to scrollbar behavior */
	if (keyEvent != nullptr && keyEvent->type() == QEvent::Type::KeyPress)
	{
		switch (keyEvent->key())
		{
			case Qt::Key_Escape:
			{
				onEscapeKeyPressed();
				return false;
			}
			case Qt::Key_S:
			{
				notifyLeftKeyPressedSignal();
				return false;
			}
			case Qt::Key_F:
			{
				notifyRightKeyPressedSignal();
				return false;
			}
			default:
				return false;
		}
	}
	return false;
}

void KeyboardInputComponent::bindKeyboardInputSignalCallbacks()
{
	QObject::connect(this, SIGNAL(notifyLeftKeyPressedSignal()), _mainWinView.get(), SLOT(OnMoveSelectionLeft()));
	QObject::connect(this, SIGNAL(notifyRightKeyPressedSignal()), _mainWinView.get(), SLOT(OnMoveSelectionRight()));
}

void KeyboardInputComponent::onEscapeKeyPressed()
{
		QApplication::quit();
}


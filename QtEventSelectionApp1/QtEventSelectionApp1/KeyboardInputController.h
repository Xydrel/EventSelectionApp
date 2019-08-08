#pragma once

#include <QObject>
#include <QKeyEvent>

class QKeyEvent;
class MainWindowView;

class KeyboardInputController : public QObject
{
	Q_OBJECT

public:
	KeyboardInputController(std::shared_ptr<MainWindowView> mainWin, QObject* parent = Q_NULLPTR);
	~KeyboardInputController() = default;

	KeyboardInputController(const KeyboardInputController&) = delete;
	KeyboardInputController& operator=(const KeyboardInputController&) = delete;

private:
	// QObject overrides
	bool eventFilter(QObject* watched, QEvent* event) override;
	// End QObject overrides	

	void bindKeyboardInputSignalCallbacks();
	void onEscapeKeyPressed();

signals:
	void notifyLeftKeyPressedSignal();
	void notifyRightKeyPressedSignal();

private:
	std::shared_ptr<MainWindowView> _mainWinView;
};

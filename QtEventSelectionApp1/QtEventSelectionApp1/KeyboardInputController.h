#pragma once

#include <QObject>
#include <QKeyEvent>

class QKeyEvent;
class MainWindowView;

class KeyboardInputController : public QObject
{
	Q_OBJECT

public:
	KeyboardInputController(QObject *parent, std::shared_ptr<MainWindowView> mainWin);
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
	void onLeftKeyPressed();
	void onRightKeyPressed();

private:
	std::shared_ptr<MainWindowView> _mainWinView;
};

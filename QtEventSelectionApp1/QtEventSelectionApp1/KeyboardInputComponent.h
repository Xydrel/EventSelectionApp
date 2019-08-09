#pragma once

#include <QObject>
#include <QKeyEvent>

class QKeyEvent;
class MainWindowView;

class KeyboardInputComponent : public QObject
{
	Q_OBJECT

public:
	KeyboardInputComponent(std::shared_ptr<MainWindowView> mainWin, QObject* parent = Q_NULLPTR);
	~KeyboardInputComponent() = default;

	KeyboardInputComponent(const KeyboardInputComponent&) = delete;
	KeyboardInputComponent& operator=(const KeyboardInputComponent&) = delete;

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

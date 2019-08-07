#pragma once

#include <QObject>
#include <QKeyEvent>

class QKeyEvent;

class KeyboardInputController : public QObject
{
	Q_OBJECT

public:
	KeyboardInputController(QObject *parent);
	~KeyboardInputController() = default;

	KeyboardInputController(const KeyboardInputController&) = delete;
	KeyboardInputController& operator=(const KeyboardInputController&) = delete;


private:
	// QObject overrides
	bool eventFilter(QObject* watched, QEvent* event) override;
	// End QObject overrides
};

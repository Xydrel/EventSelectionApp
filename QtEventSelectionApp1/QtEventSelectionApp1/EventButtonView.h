#pragma once

#include <QWidget>

#include "ui_EventButtonView.h"

class EventButtonModel;

class EventButtonView : public QWidget
{
	Q_OBJECT

public:
	EventButtonView(QWidget *parent = Q_NULLPTR);
	~EventButtonView() = default;

	EventButtonView(const EventButtonView&) = delete;
	EventButtonView& operator=(const EventButtonView&) = delete;

	void SetData(const std::shared_ptr<EventButtonModel> data);
	void Populate();

public slots:
	void OnButtonClicked();

private:
	// QObject overrides
	bool eventFilter(QObject* watched, QEvent* event) override;
	// End QObject overrides

	void setButtonFrameDimensions();
	void setButtonDimensions();
	void bindButtonConnections();

	void loadButtonImage(const QString& imagePath);
	void toggleTextVisibility(bool enable);

	void onFocusResizeButton();
	void onLostFocusResizeButton();

private:
	Ui::EventButtonView _ui;
	QPalette _palette;
	std::shared_ptr<EventButtonModel> _data;

	const int _baseButtonWidth = 120;
	const int _baseButtonHeight = 100;
	const int _buttonFrameWidth = 255;
	const int _buttonFrameHeight = 255;
	const float _hoveredScaler = 1.5;
};

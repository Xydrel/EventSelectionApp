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

	void SetModel(const std::shared_ptr<EventButtonModel> model);
	void Populate();
	QObject* GetVerticalLayoutWidget() const;

private:
	// QObject overrides
	bool eventFilter(QObject* watched, QEvent* event) override;
	// End QObject overrides

	void setButtonViewLayoutDimensions();
	void setButtonFrameDimensions();
	void setButtonDimensions();
	void loadButtonImage(const QString& imagePath);
	void toggleTextVisibility(bool enable);
	void onFocusResizeButton();
	void onLostFocusResizeButton();

private:
	Ui::EventButtonView _ui;
	QPalette _palette;
	std::shared_ptr<EventButtonModel> _model;

	const qint32 _baseLayoutWidth = 255;
	const qint32 _baseLayoutHeight = 450;
	const qint32 _baseButtonWidth = 120;
	const qint32 _baseButtonHeight = 100;
	const qint32 _buttonFrameWidth = 255;
	const qint32 _buttonFrameHeight = 200;
	const float_t _hoveredScaler = 1.5;
};

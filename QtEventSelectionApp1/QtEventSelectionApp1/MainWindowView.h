#pragma once
#include "BackgroundImageModel.h"
#include "EventButtonView.h"

#include <QtWidgets/QMainWindow>
#include <QList>

#include "ui_MainWindowView.h"

class QSize;
class QPalette;
class EventButtonView;
class QScrollArea;

class MainWindowView : public QMainWindow
{
	Q_OBJECT

public:
	MainWindowView(QWidget* parent = Q_NULLPTR);
	~MainWindowView();

	MainWindowView(const MainWindowView&) = delete;
	MainWindowView& operator=(const MainWindowView&) = delete;

	void PopulateWindowElements();
	void AddNewButtonToMenu(const std::shared_ptr<EventButtonModel> model);

public slots:
	// Handlers for calls coming from the KeyboardInputController
	void OnButtonGenerationCompleted();
	void OnMoveSelectionLeft();
	void OnMoveSelectionRight();

private:
	void setupButtonScrollArea();
	void loadBackgroundImage();
	void resizeHorizontalLayoutToFitButtons();


private:
	Ui::MainWindowViewClass _ui;
	QWidget* _parent;
	std::unique_ptr<BackgroundImageModel> _bkgrndImage;
	std::shared_ptr<QScrollArea> _scrollArea;
	QPalette _palette;
	QList<std::shared_ptr<EventButtonView>> _eventButtonsList;
	qint32 _currentButtonIndex;
};

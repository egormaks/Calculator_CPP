#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QProcess>

class QPushButton;
class QTextBrowser;

// Declaration of the MainWidget class. Implemented in mainwidget.cpp
class MainWidget : public QWidget
{
	// Pre-processor macro used by QT build tools to determine that this class is a QT Object
	Q_OBJECT

	public:
		// Constructor
		explicit MainWidget(QWidget * parent = 0);

		// Destructor
		~MainWidget();
	
	private slots:
		// Handler for button presses
		void onButtonRelease();

	private:
		// All the elements the MainWidget will contain.
		// TODO: add the components of the calculator here.
		QPushButton * button_;
		QTextBrowser * textBrowser_;
		QProcess * process_;
};

#endif


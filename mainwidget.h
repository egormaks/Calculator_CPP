#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QProcess>
#include <list>
#include <string>
#include <iostream>
#include "exprtk.hpp"
using namespace std;

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
		void onEnterButtonRelease();
		void onClearButtonRelease();
		void onDeleteButtonRelease();

	private:
		// All the elements the MainWidget will contain.
		QPushButton * button_;
		QPushButton * enter_button_;
		QPushButton * del_button_;
		QPushButton * clear_button_;
		list<QPushButton *> calc_buttons_;
		QTextBrowser * text_browser_;
		string curr_expression_;
		double stored_ans_;
		bool prev_computed_;
		void generateCalcButtons(list<QPushButton *> * buttons);
};

#endif


#include <QtWidgets>
#include "mainwidget.h"

MainWidget::MainWidget(QWidget * parent) : QWidget(parent)
{
	calc_buttons_ = {};
	button_ = new QPushButton(tr("Push me!"));
	generateCalcButtons(&calc_buttons_);
	enter_button_ = new QPushButton(tr("Enter"));
	textBrowser_ = new QTextBrowser();

	QGridLayout * main_layout = new QGridLayout;
	// (N, 0) dicates vertical structure, (0, N) horizontal
	
	int pos = 0;
	for (auto button = calc_buttons_.begin(); button != calc_buttons_.end(); button++) {
		connect(*button, SIGNAL(released()), this, SLOT(onButtonRelease()));
	}
	for (auto button = calc_buttons_.begin(); button != calc_buttons_.end(); button++) {
		main_layout->addWidget(*button, 0, pos);
		pos++;
	}

	main_layout->addWidget(textBrowser_, 1, 0);
	setLayout(main_layout);
	setWindowTitle(tr("Calcuator"));

	// connect button_'s released SIGNAL to the MainWidget's (this) slot method (onButtonReleased())
	// basically, when button_ is released after a click, MainWidget's onButtonReleased() method will run
	// connect(button_, SIGNAL(released()), this, SLOT(onButtonRelease()));
}

MainWidget::~MainWidget() 
{
	delete button_;
	delete textBrowser_;
}

void MainWidget::onButtonRelease()
{
	QPushButton * signaler = qobject_cast<QPushButton *>(sender());
	textBrowser_->clear();
	textBrowser_->append(signaler->text());
}

void MainWidget::generateCalcButtons(list<QPushButton *> * buttons) {
	for (int i = 1; i <= 9; i++) {
		buttons->push_back(new QPushButton(tr(to_string(i).c_str())));
	}
	buttons->push_back(new QPushButton(tr("+")));
	buttons->push_back(new QPushButton(tr("-")));
	buttons->push_back(new QPushButton(tr("*")));
	buttons->push_back(new QPushButton(tr("/")));
	buttons->push_back(new QPushButton(tr("^")));
}	

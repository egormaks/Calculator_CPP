#include <QtWidgets>
#include "mainwidget.h"

MainWidget::MainWidget(QWidget * parent) : QWidget(parent)
{
	button_ = new QPushButton(tr("Push me!"));
	textBrowser_ = new QTextBrowser();

	QGridLayout * main_layout = new QGridLayout;
	// (N, 0) dicates vertical structure, (0, N) horizontal
	main_layout->addWidget(button_, 0, 0);
	main_layout->addWidget(textBrowser_, 1, 0);
	setLayout(main_layout);
	setWindowTitle(tr("Connecting buttons to process..."));

	// connect button_'s released SIGNAL to the MainWidget's (this) slot method (onButtonReleased())
	// basically, when button_ is released after a click, MainWidget's onButtonReleased() method will run
	connect(button_, SIGNAL(released()), this, SLOT(onButtonRelease()));
}

MainWidget::~MainWidget() 
{
	delete button_;
	delete textBrowser_;
}

void MainWidget::onButtonRelease()
{
	textBrowser_->clear();
	textBrowser_->append(tr("Hello World!"));
}

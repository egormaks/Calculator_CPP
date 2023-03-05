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
}

MainWidget::~MainWidget() 
{
	delete button_;
	delete textBrowser_;
}

#include <QtWidgets>
#include "mainwidget.h"

MainWidget::MainWidget(QWidget * parent) : QWidget(parent)
{
	calc_buttons_ = {};
	generateCalcButtons(&calc_buttons_);
	enter_button_ = new QPushButton(tr("Enter"));
	del_button_ = new QPushButton(tr("Delete"));
	clear_button_ = new QPushButton(tr("Clear"));
	textBrowser_ = new QTextBrowser();

	QGridLayout * main_layout = new QGridLayout;
	int pos = 0;
	auto curr_button = calc_buttons_.begin();
	for (curr_button = calc_buttons_.begin(); curr_button != calc_buttons_.end() && pos < 10; curr_button++) {
		main_layout->addWidget(*curr_button, 3 + pos / 3, pos % 3);
		pos++;
	}
	int height = 3 + pos / 3;
	for (int i = 1; i < 3 && curr_button != calc_buttons_.end(); i++, curr_button++) { 
		main_layout->addWidget(*curr_button, height, i);
	}
	height = height - 1;
	while (curr_button != calc_buttons_.end()) { 
		main_layout->addWidget(*curr_button, height, 4);
		height--;
		curr_button++;
	}
	
	for (curr_button = calc_buttons_.begin(); curr_button != calc_buttons_.end(); curr_button++) {
        	connect(*curr_button, SIGNAL(released()), this, SLOT(onButtonRelease()));
        }

	
	textBrowser_->setFixedHeight(3 * 20);
	main_layout->addWidget(textBrowser_, 0, 0, 2, 3);
	main_layout->addWidget(enter_button_, 0, 4);
	main_layout->addWidget(clear_button_, 1, 4);
	main_layout->addWidget(del_button_, 2, 4);
	setLayout(main_layout);
	setWindowTitle(tr("Calcuator"));
}

MainWidget::~MainWidget() 
{
	delete textBrowser_;
	delete enter_button_;
	delete clear_button_;
	delete del_button_;
	for (auto curr_button = calc_buttons_.begin(); curr_button != calc_buttons_.end(); curr_button++) { 
		delete *curr_button;
	}
}

void MainWidget::onButtonRelease()
{
	QPushButton * signaler = qobject_cast<QPushButton *>(sender());
	textBrowser_->clear();
	textBrowser_->append(signaler->text());
}

void MainWidget::generateCalcButtons(list<QPushButton *> * buttons) {
	for (int i = 0; i <= 9; i++) {
		buttons->push_back(new QPushButton(tr(to_string(i).c_str())));
	}
	buttons->push_back(new QPushButton(tr("+")));
	buttons->push_back(new QPushButton(tr("-")));
	buttons->push_back(new QPushButton(tr("*")));
	buttons->push_back(new QPushButton(tr("/")));
	buttons->push_back(new QPushButton(tr("^")));
}	

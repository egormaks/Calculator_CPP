#include <QtWidgets>
#include "mainwidget.h"

MainWidget::MainWidget(QWidget * parent) : QWidget(parent)
{
	calc_buttons_ = {};
	curr_expression_ = {};
	stored_ans_ = {};
	prev_computed_ = false;
	generateCalcButtons(&calc_buttons_);

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

	while (curr_button != calc_buttons_.end()) { 
		main_layout->addWidget(*curr_button, height, 4);
		height--;
		curr_button++;
	}

	text_browser_->setFixedHeight(3 * 20);
	main_layout->addWidget(text_browser_, 0, 0, 2, 3);
	main_layout->addWidget(enter_button_, 0, 4);
	main_layout->addWidget(clear_button_, 1, 4);
	main_layout->addWidget(del_button_, 2, 4);
	setLayout(main_layout);
	setWindowTitle(tr("Calcuator"));
}

MainWidget::~MainWidget() 
{
	delete text_browser_;
	delete enter_button_;
	delete clear_button_;
	delete del_button_;
	for (auto curr_button = calc_buttons_.begin(); curr_button != calc_buttons_.end(); curr_button++) { 
		delete *curr_button;
	}
}

void MainWidget::onEnterButtonRelease() 
{
	text_browser_->clear();
	exprtk::expression<double> expression;
	exprtk::parser<double> parser;
	parser.compile(curr_expression_, expression);
        double res = expression.value();
        if (isnan(res)) {
		text_browser_->append(tr("Invalid input. Clear and try again."));
	} else { 
		text_browser_->append(tr(to_string(res).c_str()));
        	stored_ans_ = res;
        	prev_computed_ = true;
	}
}

void MainWidget::onClearButtonRelease() 
{ 
	text_browser_->clear();
	curr_expression_ = {};
}

void MainWidget::onDeleteButtonRelease() 
{
	if (curr_expression_.length() > 0) { 
		curr_expression_ = curr_expression_.substr(0, curr_expression_.length() - 2);
		text_browser_->clear();
		text_browser_->append(tr(curr_expression_.c_str()));
	}
}

void MainWidget::onButtonRelease()
{
	if (prev_computed_) {
		text_browser_->clear();
		curr_expression_ = {};
	}
	QPushButton * signaler = qobject_cast<QPushButton *>(sender());
	string label = signaler->text().toStdString();
	if (!isdigit(label[0]) && prev_computed_ && label[0] != '(' && label[0] != ')') {
		label = to_string(stored_ans_) + " " + label;
	}
	prev_computed_ = false;
	curr_expression_.append(label + " ");
	text_browser_->clear();
	text_browser_->append(tr(curr_expression_.c_str()));
}

void MainWidget::generateCalcButtons(list<QPushButton *> * buttons) {
	for (int i = 0; i <= 9; i++) {
		buttons->push_back(new QPushButton(tr(to_string(i).c_str())));
	}
	buttons->push_back(new QPushButton(tr("+")));
	buttons->push_back(new QPushButton(tr("-")));
	buttons->push_back(new QPushButton(tr("*")));
	buttons->push_back(new QPushButton(tr("/")));
	buttons->push_back(new QPushButton(tr("(")));
	buttons->push_back(new QPushButton(tr(")")));

        enter_button_ = new QPushButton(tr("Enter"));
        del_button_ = new QPushButton(tr("Delete"));
        clear_button_ = new QPushButton(tr("Clear"));
        text_browser_ = new QTextBrowser();

	for (auto curr_button = calc_buttons_.begin(); curr_button != calc_buttons_.end(); curr_button++) {
                connect(*curr_button, SIGNAL(released()), this, SLOT(onButtonRelease()));
        }
        connect(enter_button_, SIGNAL(released()), this, SLOT(onEnterButtonRelease()));
        connect(clear_button_, SIGNAL(released()), this, SLOT(onClearButtonRelease()));
        connect(del_button_, SIGNAL(released()), this, SLOT(onDeleteButtonRelease()));
}	

#include <QtWidgets>
#include "mainwidget.h"

int main(int argc, char ** argv) 
{
	QApplication app(argc, argv);
	MainWidget mw;
	mw.show();

	return app.exec();
}

#include "MainWidget.h"
#include <QApplication>
#include "MatrixTestWidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	CMatrixTestWidget w;
	w.makeCurrent();
	w.setFixedSize(600, 600);
    w.show();

    return a.exec();
}

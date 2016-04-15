#ifndef MATRIXTESTWIDGET_H
#define MATRIXTESTWIDGET_H

#include <QtOpenGL/QGLWidget>

class CMatrixTestWidget : public QGLWidget
{
	Q_OBJECT

public:
	CMatrixTestWidget(QWidget *parent = 0);
	~CMatrixTestWidget();

protected:
	void initializeGL();
	void resizeGL(int w, int h);
	void paintGL();
	void keyPressEvent(QKeyEvent *e);

private:
	bool fullscreen;
};

#endif // MATRIXTESTWIDGET_H

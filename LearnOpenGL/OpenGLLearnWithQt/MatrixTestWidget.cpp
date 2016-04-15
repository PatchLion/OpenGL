#include "MatrixTestWidget.h"
#include <QtOpenGL>
#include <GL/GLU.h>
#include <QDebug>

#ifndef GL_MULTISAMPLE
#define GL_MULTISAMPLE  0x809D
#endif

#define GL_PI 3.1415926
#define GL_RADIUX  0.2f

#define drawOneLine(x1, y1, x2, y2) 		glBegin(GL_LINES);\
glVertex2f(x1, y1);\
glVertex2f(x2, y2);\
glEnd();

#define drawOneLineWithColor(x1, y1, x2, y2, r, g, b) 		glBegin(GL_LINES);\
glColor3f(r, g, b);\
glVertex2f(x1, y1);\
glVertex2f(x2, y2);\
glEnd();

CMatrixTestWidget::CMatrixTestWidget(QWidget *parent)
	: QGLWidget(parent)
{
	if (!QGLFormat::hasOpenGL())
	{
		QMessageBox::information(0, "OpenGL", "This system does not support OpenGL.");
	}


}

CMatrixTestWidget::~CMatrixTestWidget()
{

}

void CMatrixTestWidget::initializeGL()
{
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClearDepth(1.0);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);


}

void CMatrixTestWidget::resizeGL(int w, int h)
{
	if (0 == h)
		h = 1;//防止一条边为0
	glViewport(0, 0, (GLint)w, (GLint)h);//重置当前视口，本身不是重置窗口的，只不过是这里被Qt给封装好了
	glMatrixMode(GL_PROJECTION);//选择投影矩阵
	glLoadIdentity();//重置选择好的投影矩阵
	// gluPerspective(45.0, (GLfloat)width/(GLfloat)height, 0.1, 100.0);//建立透视投影矩阵
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void CMatrixTestWidget::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(-1.5, 0.0, -6.0);

	glBegin(GL_TRIANGLES);
	glVertex3f(0.0, 1.0, 0.0);
	glVertex3f(-1.0, -1.0, 0.0);
	glVertex3f(1.0, -1.0, 0.0);
	glEnd();

	glTranslatef(3.0, 0.0, 0.0);

	glBegin(GL_QUADS);
	glVertex3f(-1.0, 1.0, 0.0);
	glVertex3f(1.0, 1.0, 0.0);
	glVertex3f(1.0, -1.0, 0.0);
	glVertex3f(-1.0, -1.0, 0.0);
	glEnd();

}

void CMatrixTestWidget::keyPressEvent(QKeyEvent *e)
{
	switch (e->key())
	{
		//F1键为全屏和普通屏显示切换键
	case Qt::Key_F1:
		fullscreen = !fullscreen;
		if (fullscreen)
			showFullScreen();
		else
		{
			//setGeometry(300, 150, 640, 480);
			showNormal();
		}
		updateGL();
		break;
		//Ese为退出程序键
	case Qt::Key_Escape:
		close();
	}

}
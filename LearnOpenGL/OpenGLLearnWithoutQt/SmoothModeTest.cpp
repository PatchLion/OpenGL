#include "stdafx.h"
#include "SmoothModeTest.h"

CSmoothModeTest::CSmoothModeTest()
{
	
}

CSmoothModeTest::~CSmoothModeTest()
{
}

void CSmoothModeTest::displayEvent()
{
	CLearnOpenGLBase::displayEvent();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1, 0, 0);
	glVertex3f(0, 0, 0);
	glColor3f(0, 1, 0);
	glVertex3f(1, 1, -1);
	glColor3f(0, 0, 1);
	glVertex3f(2, 0.5, -0.5);
	glEnd();

	glutSwapBuffers();
}

void CSmoothModeTest::init()
{
	CLearnOpenGLBase::init();

	glShadeModel(GL_SMOOTH);
}

#include "stdafx.h"
#include "Aaindex6_5.h"

#define PAMPSIZE 16
#define PAMP1START 32
#define PAMP2START 48

CAaindex6_5::CAaindex6_5()
{

}

CAaindex6_5::~CAaindex6_5()
{
}

void CAaindex6_5::displayEvent()
{
	CLearnOpenGLBase::displayEvent();

	glIndexi(PAMP1START);
	glBegin(GL_LINES);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(-0.5, -0.5);
	glEnd();

	
	glutSwapBuffers();
}

void CAaindex6_5::init()
{
	CLearnOpenGLBase::init();

	for (int i = 0; i < PAMPSIZE; i++)
	{
		GLfloat shade = (GLfloat)i / (GLfloat)PAMPSIZE;
		glutSetColor(PAMP1START + (GLint)i, 0, shade, 0);
		glutSetColor(PAMP2START + (GLint)i, 0, 0, shade);
	}

	glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);
	glLineWidth(1.5);

	glClearIndex((GLfloat)PAMP1START);
}

void CAaindex6_5::keyPressedEvent(unsigned char key, int x, int y)
{
	LearnOpenGL::CLearnOpenGLBase::keyPressedEvent(key, x, y);
}
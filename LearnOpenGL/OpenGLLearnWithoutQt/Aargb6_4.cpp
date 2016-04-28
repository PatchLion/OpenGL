#include "stdafx.h"
#include "Aargb6_4.h"

#define MAXZ 2.0
#define MINZ -2.0
#define ZINC 0.01
static float solidz = MAXZ;
static float transparentZ = MINZ;

CAargb6_4::CAargb6_4()
{

}

CAargb6_4::~CAargb6_4()
{
}

void CAargb6_4::displayEvent()
{
	CLearnOpenGLBase::displayEvent();

	glBegin(GL_LINES);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(-0.5, -0.5);
	glEnd();

	
	glutSwapBuffers();
}

void CAargb6_4::init()
{
	CLearnOpenGLBase::init();

	GLfloat values[2];
	glGetFloatv(GL_LINE_WIDTH_GRANULARITY, values);

	printf("GL_LINE_WIDTH_GRANULARITY value is %3.1f\n", values[0]);

	glGetFloatv(GL_LINE_WIDTH_RANGE, values);
	printf("GL_LINE_WIDTH_RANGE value are %3.1f %3.1f\n", values[0]);

	glEnable(GL_LINE_SMOOTH);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);
	glLineWidth(1.5);
}

void CAargb6_4::keyPressedEvent(unsigned char key, int x, int y)
{
	LearnOpenGL::CLearnOpenGLBase::keyPressedEvent(key, x, y);
}
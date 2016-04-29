#include "stdafx.h"
#include "PointP6_10.h"

CPointP6_10::CPointP6_10()
{
}

CPointP6_10::~CPointP6_10()
{
}


void CPointP6_10::displayEvent()
{
	CLearnOpenGLBase::displayEvent();

	glPointSize(10);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POINTS);
	glVertex3f(1, 1,0);
	glEnd();
	
	glutSwapBuffers();
}

void CPointP6_10::init()
{
	CLearnOpenGLBase::init();

	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
}

void CPointP6_10::keyPressedEvent(unsigned char key, int x, int y)
{
	static GLfloat constant[3] = { 1.0, 0.0, 0.0 };
	static GLfloat linear[3] = {0.0, 0.12, 0.0 };
	static GLfloat quadratic[3] = { 0.0, 0.0, 0.01 };
	if ('f' == key)
	{
		glPointParameterfv(GL_POINT_DISTANCE_ATTENUATION, constant);
	}
	else if ('x' == key)
	{
		glPointParameterfv(GL_POINT_DISTANCE_ATTENUATION, linear);
	}
	else if ('c' == key)
	{
		glPointParameterfv(GL_POINT_DISTANCE_ATTENUATION, quadratic);
	}

	LearnOpenGL::CLearnOpenGLBase::keyPressedEvent(key, x, y);
}

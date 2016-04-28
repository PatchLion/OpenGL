#include "stdafx.h"
#include "Blendeqn6_1.h"

CBlendeqn6_1::CBlendeqn6_1()
{
	m_bIsLeftFirst = true;
}

CBlendeqn6_1::~CBlendeqn6_1()
{
}

void CBlendeqn6_1::displayEvent()
{
	CLearnOpenGLBase::displayEvent();
	/*
	//6-1
	glColor4f(0.0, 0.0, 1.0, 1.0);
	glRectf(-0.5, -0.5, 0.5, 0.5);*/

	if (m_bIsLeftFirst)
	{
		drawLeftTriangle();
		drawRightTriangle();
	}
	else
	{
		drawRightTriangle();
		drawLeftTriangle();
	}
	glutSwapBuffers();
}

void CBlendeqn6_1::init()
{
	CLearnOpenGLBase::init();

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);

}
void CBlendeqn6_1::drawLeftTriangle(void)
{
	glBegin(GL_TRIANGLES);
	glColor4f(1.0, 1.0, 0.0, 0.75);
	glVertex3f(0.1, 0.9, 0.0);
	glVertex3f(0.1, 0.1, 0.0);
	glVertex3f(0.7, 0.5, 0.0);
	glEnd();
}
void CBlendeqn6_1::drawRightTriangle(void)
{
	glBegin(GL_TRIANGLES);
	glColor4f(0.0, 0.1, 1.0, 0.75);
	glVertex3f(0.9, 0.9, 0.0);
	glVertex3f(0.3, 0.5, 0.0);
	glVertex3f(0.9, 0.1, 0.0);
	glEnd();
}

void CBlendeqn6_1::keyPressedEvent(unsigned char key, int x, int y)
{
	if ('z' == key)
	{
		glBlendEquation(GL_FUNC_ADD);
	}
	else if ('x' == key)
	{
		glBlendEquation(GL_FUNC_SUBTRACT);
	}
	else if ('c' == key)
	{
		glBlendEquation(GL_FUNC_REVERSE_SUBTRACT);
	}
	else if ('v' == key)
	{
		glBlendEquation(GL_MIN);
	}
	else if ('b' == key)
	{
		glBlendEquation(GL_MAX);
	}
	else if ('n' == key)
	{
		m_bIsLeftFirst = !m_bIsLeftFirst;
	}
	LearnOpenGL::CLearnOpenGLBase::keyPressedEvent(key, x, y);
}

void CBlendeqn6_1::idleEvent()
{

}

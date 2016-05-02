#include "stdafx.h"
#include "DisplayList7_9.h"

CDisplayList7_9::CDisplayList7_9()
{
}

CDisplayList7_9::~CDisplayList7_9()
{
	//glDeleteLists(m_unListIndex, 4);
}

#define drawOneLine(x1, y1, x2, y2) glBegin(GL_LINES);\
	glVertex2f((x1), (y1)); glVertex2f((x2), (y2)); glEnd();

void CDisplayList7_9::displayEvent()
{
	glDisable(GL_LINE_STIPPLE);
	CLearnOpenGLBase::displayEvent();

	glCallList(m_offset);
	drawOneLine(0, 1, 1, 1);

	glCallList(m_offset+1);
	drawOneLine(0,1.2, 1, 1.2);

	glCallList(m_offset + 2);
	drawOneLine(0, 1.4, 1, 1.4);

	glutSwapBuffers();
}

void CDisplayList7_9::init()
{
	CLearnOpenGLBase::init();

	m_offset = glGenLists(3);

	glNewList(m_offset, GL_COMPILE);
	glDisable(GL_LINE_STIPPLE);
	glEndList();

	glNewList(m_offset + 1, GL_COMPILE);
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0x0F0F);
	glEndList();

	glNewList(m_offset + 2, GL_COMPILE);
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0x1111);
	glEndList();


}

void CDisplayList7_9::keyPressedEvent(unsigned char key, int x, int y)
{
	LearnOpenGL::CLearnOpenGLBase::keyPressedEvent(key, x, y);
}

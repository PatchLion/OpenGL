#include "stdafx.h"
#include "DrawSunAndPlanet.h"

CDrawSunAndPlanet::CDrawSunAndPlanet()
{
	m_nYear = 0;
	m_nDay = 0;
}

CDrawSunAndPlanet::~CDrawSunAndPlanet()
{
}

void CDrawSunAndPlanet::displayEvent()
{
	CLearnOpenGLBase::displayEvent();


	glPushMatrix();
	glPushMatrix();
	glPushMatrix();


	glPushMatrix();
	glRotatef((GLfloat)m_nDay, 0.0, 1.0, 0);

	glutWireSphere(1.0, 20, 16);
	glPopMatrix();

	glRotatef((GLfloat)m_nDay, 0.2, 1.0, 1.0);
	glTranslatef(2.0, 0.0, 0.0);
	glutWireSphere(0.2, 10, 8);
	glPopMatrix();
	glRotatef((GLfloat)m_nYear, 0.2, 1.0, 1.0);
	glTranslatef(1.6, 0.0, 0.0);
	glutWireSphere(0.15, 9, 4);
	glPopMatrix();
	glRotatef((GLfloat)m_nYear, -0.2, -0.3, -1.0);
	glTranslatef(2.4, 0.0, 0.0);
	glutWireSphere(0.15, 8, 4);
	glPopMatrix();

	glutSwapBuffers();
}

void CDrawSunAndPlanet::init()
{
	CLearnOpenGLBase::init();

	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
}

void CDrawSunAndPlanet::idleEvent()
{
	m_nDay = (m_nDay + 10) % 360;
	m_nYear = (m_nYear + 5) % 360;
	Sleep(30);

	glutPostRedisplay();
}

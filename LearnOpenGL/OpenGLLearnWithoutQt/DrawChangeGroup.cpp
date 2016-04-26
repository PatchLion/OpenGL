#include "stdafx.h"
#include "DrawChangeGroup.h"
bool g_drawEarth = false;
CDrawChangeGroup::CDrawChangeGroup()
{
	m_nHour = 0;
	m_nDay = 0;
	m_nMonth = 0;
	m_nYear = 0;
}

CDrawChangeGroup::~CDrawChangeGroup()
{
}

void CDrawChangeGroup::displayEvent()
{
	CLearnOpenGLBase::displayEvent();

	if (g_drawEarth)
	{
		drawEarth();
	}
	else
	{
		drawRobotArm();
	}

	glutSwapBuffers();
}

void CDrawChangeGroup::init()
{
	CLearnOpenGLBase::init();

	//glShadeModel(GL_FLAT);

/*
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);*/
}

void CDrawChangeGroup::idleEvent()
{
	CLearnOpenGLBase::idleEvent();

	if (g_drawEarth)
	{
		const int ANGLE_PER_HOUR = 360 / 24;
		const int ANGLE_PER_DAY = 360 / 30;

		m_nHour = (m_nHour + 2) % 360;
		m_nDay = (m_nDay + 4) % 360;
		m_nMonth = (m_nMonth + 6) % 360;
		m_nYear = (m_nYear + 10) % 360;
	}


	Sleep(30);

	glutPostRedisplay();
}


void CDrawChangeGroup::drawEarth()
{
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();
	//自转
	//glRotatef(45, 1, 0, 0);
	glRotatef(m_nHour, 0, 1, 0);
	glutWireSphere(0.5, 20, 16);
	glPopMatrix();

	//第一颗卫星
	glRotatef(m_nDay, 0, 1, 0);
	glTranslatef(2, 0, 0);
	glRotatef(10, 0, 1, 0);
	glutWireSphere(0.1, 10, 8);
	glPopMatrix();

	//第二颗卫星
	glRotatef(m_nMonth, 0, 0, 1);
	glTranslatef(1.5, 0, 0);
	glRotatef(10, 0, 1, 0);
	glutWireSphere(0.2, 10, 8);
	glPopMatrix();

	//第三颗卫星
	glRotatef(-m_nYear, 1, 0, 0);
	glTranslatef(0, 0, 1.3);
	glRotatef(10, 0, 1, 0);
	glutWireSphere(0.2, 10, 8);
	glPopMatrix();
}

void CDrawChangeGroup::keyPressedEvent(unsigned char key, int x, int y)
{
	if (113 == key)//q
	{
		//重置
		g_drawEarth = !g_drawEarth;
	}

	LearnOpenGL::CLearnOpenGLBase::keyPressedEvent(key, x, y);


}
static int shoulder = 30, elbow = 45;
void CDrawChangeGroup::drawRobotArm()
{

	glPushMatrix();
	glTranslatef(-1, 0, 0);
	glRotatef(shoulder, 0, 0, 1);
	glTranslatef(1, 0, 0);


	glPushMatrix();
	glScaled(2, 0.4, 0.4);
	glutWireCube(1.0);
	glPopMatrix();

	glTranslatef(1, 0, 0);
	glRotatef(elbow, 0, 0, 1);
	glTranslatef(1, 0, 0);

	glPushMatrix();
	glScalef(2, 0.4, 0.4);
	glutWireCube(1.0);
	glPopMatrix();
	
	glPopMatrix();


}


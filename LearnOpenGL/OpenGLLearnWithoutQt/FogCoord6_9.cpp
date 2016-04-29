#include "stdafx.h"
#include "FogCoord6_9.h"

CFogCoord6_9::CFogCoord6_9()
{
	m_efogMode = GL_EXP;
	setDefaultValue(1, 1);
	setDefaultValue(2, 5);
	setDefaultValue(3, 10);
	setValueStep(1, 0.25);
	setValueStep(2, 0.25);
	setValueStep(3, 0.25);
}

CFogCoord6_9::~CFogCoord6_9()
{
}


void CFogCoord6_9::displayEvent()
{

	glDisable(GL_LIGHTING);
	glDisable(GL_FOG);
	CLearnOpenGLBase::displayEvent();
	glEnable(GL_LIGHTING);
	glEnable(GL_FOG);

	glBegin(GL_TRIANGLES);
	glFogCoordf(value(1));
	glVertex3f(2.0, -2.0, 0.0);
	glFogCoordf(value(2));
	glVertex3f(-2.0, 0.0, -5.0);
	glFogCoordf(value(3));
	glVertex3f(0.0, 2.0, -10.0);
	glEnd();

	glutSwapBuffers();
}

void CFogCoord6_9::init()
{
	CLearnOpenGLBase::init();

	GLfloat fogColor[] = { 0.0, 0.25, 0.25, 1.0 };

	glEnable(GL_FOG);

	glFogi(GL_FOG_MODE, m_efogMode);
	glFogfv(GL_FOG_COLOR, fogColor);
	glFogf(GL_FOG_DENSITY, 0.25);
	glHint(GL_FOG_HINT, GL_DONT_CARE);
	glFogf(GL_FOG_COORD_SRC, GL_FOG_COORD);
	glFogf(GL_FOG_END, 5.0);

	glClearColor(0.0, 0.25, 0.25, 1.0);
}

void CFogCoord6_9::keyPressedEvent(unsigned char key, int x, int y)
{
	if ('f' == key)
	{
		if (m_efogMode == GL_EXP)
		{
			m_efogMode = GL_EXP2;
		}
		else if (m_efogMode == GL_EXP2)
		{
			m_efogMode = GL_LINEAR;
		}
		else
		{
			m_efogMode = GL_EXP;
		}

		glFogi(GL_FOG_MODE, m_efogMode);
	}
	else if ('x' == key)
	{
		
		glFogi(GL_FOG_COORD_SRC, GL_FRAGMENT_DEPTH);
	}
	else if ('c' == key)
	{
		glFogi(GL_FOG_COORD_SRC, GL_FOG_COORD);
	}
	LearnOpenGL::CLearnOpenGLBase::keyPressedEvent(key, x, y);
}

void CFogCoord6_9::renderSphere(GLfloat x, GLfloat y, GLfloat z)
{
	glPushMatrix();
	glTranslatef(x, y, z);
	glutSolidSphere(0.2, 16, 16);
	glPopMatrix();
}

#include "stdafx.h"
#include "Fog6_7.h"

CFog6_7::CFog6_7()
{
	m_efogMode = GL_EXP;
}

CFog6_7::~CFog6_7()
{
}


void CFog6_7::displayEvent()
{

	glDisable(GL_LIGHTING);
	glDisable(GL_FOG);
	CLearnOpenGLBase::displayEvent();
	glEnable(GL_LIGHTING);
	glEnable(GL_FOG);

	renderSphere(0, 0.5, -0.3);
	renderSphere(0, 0.5, -0.7);
	renderSphere(0, 0.5, -1.1);
	renderSphere(0, 0.5, -1.5);
	renderSphere(0, 0.5, -1.9);

	glutSwapBuffers();
}

void CFog6_7::init()
{
	CLearnOpenGLBase::init();

	GLfloat position[] = { 0.5, 0.5, 3.0, 0.0 };
	
	glLightfv(GL_LIGHT0, GL_POSITION, position);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	{
		GLfloat mat[3] = { 0.1745, 0.01175, 0.01175 };
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
		mat[0] = 0.61424;
		mat[1] = 0.04136;
		mat[2] = 0.04136;
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
		mat[0] = 0.727811;
		mat[1] = 0.626959;
		mat[2] = 0.626959;
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat);
		glMaterialf(GL_FRONT, GL_SHININESS, 0.6 * 128.0);
	}

	glEnable(GL_FOG);
	{
		GLfloat fogColor[4] = { 0.5, 0.5, 0.5, 1.0 };

		glFogi(GL_FOG_MODE, m_efogMode);
		glFogfv(GL_FOG_COLOR, fogColor);
		glFogf(GL_FOG_DENSITY, 0.35);
		glHint(GL_FOG_HINT, GL_DONT_CARE);
		glFogf(GL_FOG_START, 1.0);
		glFogf(GL_FOG_END, 5.0);
	}
	glClearColor(0.5, 0.5, 0.5, 1.0);
}

void CFog6_7::keyPressedEvent(unsigned char key, int x, int y)
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
	LearnOpenGL::CLearnOpenGLBase::keyPressedEvent(key, x, y);
}

void CFog6_7::renderSphere(GLfloat x, GLfloat y, GLfloat z)
{
	glPushMatrix();
	glTranslatef(x, y, z);
	glutSolidSphere(0.2, 16, 16);
	glPopMatrix();
}

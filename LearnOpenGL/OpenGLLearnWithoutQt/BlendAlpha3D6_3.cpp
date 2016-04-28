#include "stdafx.h"
#include "BlendAlpha3D6_3.h"

#define MAXZ 2.0
#define MINZ -2.0
#define ZINC 0.01
static float solidz = MAXZ;
static float transparentZ = MINZ;

CBlendAlpha3D6_3::CBlendAlpha3D6_3()
{

}

CBlendAlpha3D6_3::~CBlendAlpha3D6_3()
{
}

void CBlendAlpha3D6_3::displayEvent()
{
	CLearnOpenGLBase::displayEvent();

	glPushAttrib(GL_LIGHTING | GL_LIGHT0);
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 0.15 };
	GLfloat mat_shininess[] = { 100.0 };
	GLfloat position[] = { 0.5, 0.5, 1.0, 0.0 };

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, position);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	GLfloat mat_solid[] = { 0.75, 0.75, 0.0, 1.0 };
	GLfloat mat_zero[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat mat_transparent[] = { 0.0, 0.8, 0.8, 0.6 };
	GLfloat mat_emission[] = {0.0, 0.3, 0.3, 0.6};

	glPushMatrix();
	glTranslatef(-0.15, -0.15, -solidz);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_zero);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_solid);
	glutSolidSphere(0.4, 16, 16);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.15, 0.15, solidz);
	glRotatef(15.0, 1.0, 1.0, 0.0);
	glRotatef(30.0, 0.0, 1.0, 0.0);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_transparent);
	glEnable(GL_BLEND);
	glDepthMask(GL_FALSE);		//让深度缓冲区处于只读状态 解释P160
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	glutSolidCube(0.6);
	glDepthMask(GL_TRUE);
	glDisable(GL_BLEND);
	glPopMatrix();

	glPopAttrib();
	glutSwapBuffers();
}

void CBlendAlpha3D6_3::init()
{
	CLearnOpenGLBase::init();



/*
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
*/

}

void animate(void)
{
	if (solidz <= MINZ || transparentZ >= MAXZ)
	{
		glutIdleFunc(NULL);
	}
	else
	{
		Sleep(50);
		solidz -= ZINC;
		transparentZ += ZINC;
		glutPostRedisplay();
	}
}
void CBlendAlpha3D6_3::keyPressedEvent(unsigned char key, int x, int y)
{

	if ('z' == key)
	{
		solidz = MAXZ;
		transparentZ = MINZ;
		glutIdleFunc(animate);
	}
	else if ('x' == key)
	{
		solidz = MAXZ;
		transparentZ = MINZ;
		glutPostRedisplay();
	}
/*	else if ('c' == key)
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
	}*/
	LearnOpenGL::CLearnOpenGLBase::keyPressedEvent(key, x, y);
}
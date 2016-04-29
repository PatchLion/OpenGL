#include "stdafx.h"
#include "PolyOff6_11.h"

CPolyOff6_11::CPolyOff6_11()
{
	setDefaultValue(1, 1);
	setDefaultValue(2, 1);
	setValueStep(1, 0.1);
	setValueStep(2, 0.1);
}

CPolyOff6_11::~CPolyOff6_11()
{
}

const double radius = 0.5;
void CPolyOff6_11::displayEvent()
{
	GLfloat gray[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat black[] = { 0.0, 0.0, 0.0, 1.0 };

	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	CLearnOpenGLBase::displayEvent();

	drawSphere(radius * 2 + 0.1, radius * 2 + 0.1, 0, true);
	drawSphere(-radius * 2 + 0.1, radius * 2 + 0.1, 0, false);


	glutSwapBuffers();
}

void CPolyOff6_11::drawSphere(double tx, double ty, double tz, bool isPolyGonOffset)
{
	GLfloat matSpecular[] = { 1, 0, 0, 1.0 };
	GLfloat matShininess[] = { 20.0 };
	GLfloat matEmission[] = { 0, 0, 1, 1.0 };
	GLfloat polyfactor = value(1);
	GLfloat polyunits = value(1);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glPushMatrix();
	glTranslatef(tx, ty, tz);

	glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, matShininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, matEmission);
	

	if (isPolyGonOffset)
	{
		glEnable(GL_POLYGON_OFFSET_FILL);
	}
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glPolygonOffset(polyfactor, polyunits);
	glutSolidSphere(radius, 20, 12);
	if (isPolyGonOffset)
	{
		glDisable(GL_POLYGON_OFFSET_FILL);
	}
	

	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glutSolidSphere(radius, 20, 12);

	glPopMatrix();
}

void CPolyOff6_11::init()
{
	CLearnOpenGLBase::init();	


	const GLfloat lightPosition[] = { 2, 2, 2, 0.0 };
	const GLfloat whiteLight[] = { 0, 1, 0, 1.0 };
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, whiteLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, whiteLight);
}

void CPolyOff6_11::keyPressedEvent(unsigned char key, int x, int y)
{
	LearnOpenGL::CLearnOpenGLBase::keyPressedEvent(key, x, y);
}

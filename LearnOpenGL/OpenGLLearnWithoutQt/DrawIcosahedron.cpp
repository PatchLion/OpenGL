#include "stdafx.h"
#include "DrawIcosahedron.h"

CDrawIcosahedron::CDrawIcosahedron()
{
	
}

CDrawIcosahedron::~CDrawIcosahedron()
{
}

void CDrawIcosahedron::displayEvent()
{
	CLearnOpenGLBase::displayEvent();

	glPolygonMode(GL_FRONT, GL_FILL);
	glPolygonMode(GL_BACK, GL_LINE);

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	GLfloat points[4][2] = { { -0.8, -0.8 }, { 0.8, -0.8 }, { -0.6, 0.6 }, { -0.9, 0.5 } };
	glVertex2fv(points[0]);
	glVertex2fv(points[1]);
	glVertex2fv(points[2]);
	glVertex2fv(points[3]);
	glEnd();

	glutSwapBuffers();
}

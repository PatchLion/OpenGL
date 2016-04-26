#include "stdafx.h"
#include "DrawCilp3_5.h"

CDrawCilp3_5::CDrawCilp3_5()
{
	
}

CDrawCilp3_5::~CDrawCilp3_5()
{
}

GLdouble eqn[4] = { 0.0, 1.0, 0.0, 0.0 };
GLdouble eqn2[4] = { 1.0, 1.0, 0.0, 0.0 };

void CDrawCilp3_5::displayEvent()
{
	CLearnOpenGLBase::displayEvent();

	glPushMatrix();
	glTranslated(0, 0, -1);

	/*clip lower half --y<0*/
	glClipPlane(GL_CLIP_PLANE0, eqn);
	glEnable(GL_CLIP_PLANE0);
	/*clip left half --x<0*/
	glClipPlane(GL_CLIP_PLANE1, eqn2);
	glEnable(GL_CLIP_PLANE1);
	glRotatef(90, 1.0, 0, 0);

	glutWireSphere(0.5, 20, 16);
	glPopMatrix();

	glutSwapBuffers();
}

void CDrawCilp3_5::init()
{
	CLearnOpenGLBase::init();

	glShadeModel(GL_FLAT);

/*
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);*/
}


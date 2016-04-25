#include "stdafx.h"
#include "DrawCircle.h"


CDrawCircle::CDrawCircle()
{
	
}

CDrawCircle::~CDrawCircle()
{
}

void CDrawCircle::displayEvent()
{
	CLearnOpenGLBase::displayEvent();

	const int EDGES = 60;

	/*
	//don't use this code
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i <= EDGES; i++)
	{
	glColor3f(1, 0.64, 0);
	//(2 * M_PI*i) / EDGES == 0的时候，不同的电脑cos((2 * M_PI*i) / EDGES)不一定等于cos(0)
	const GLfloat fx = cos((2 * M_PI*i) / EDGES);  
	const GLfloat fy = sin((2 * M_PI*i) / EDGES);
	printf("Position: %f, %f\n", fx, fy);
	glVertex2f(fx, fy);
	}
	glEnd();
	*/

	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < EDGES; i++)
	{
		glColor3f(1, 0.64, 0);
		const GLfloat fx = cos((2 * M_PI*i) / EDGES);
		const GLfloat fy = sin((2 * M_PI*i) / EDGES);
		printf("Position: %f, %f\n", fx, fy);
		glVertex2f(fx, fy);
	}
	glEnd();
	glutSwapBuffers();
}

void CDrawCircle::init()
{
	CLearnOpenGLBase::init();

/*
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);*/
}

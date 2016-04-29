#include "stdafx.h"
#include "DisplayList7_1.h"

CDisplayList7_1::CDisplayList7_1()
{
}

CDisplayList7_1::~CDisplayList7_1()
{
}


void CDisplayList7_1::displayEvent()
{
	CLearnOpenGLBase::displayEvent();

	//torus(8, 25);
	glCallList(theTorus);
	
	glutSwapBuffers();
}

void CDisplayList7_1::init()
{
	CLearnOpenGLBase::init();

	theTorus = glGenLists(1);
	glNewList(theTorus, GL_COMPILE);
	torus(8, 25);
	glEndList();
}

void CDisplayList7_1::keyPressedEvent(unsigned char key, int x, int y)
{
	LearnOpenGL::CLearnOpenGLBase::keyPressedEvent(key, x, y);
}

void CDisplayList7_1::torus(int numc, int numt)
{
	int i, j, k;
	double s, t, x, y, z, twopi;

	twopi = 2 * M_PI;
	for (i = 0; i < numc; i++)
	{
		glBegin(GL_QUAD_STRIP);
		for (j = 0; j <= numt; j++)
		{
			for (k = 1; k >= 0; k--)
			{
				s = (i + k) % numc + 0.5;
				t = j % numt;

				x = (1 + 0.1*cos(s*twopi / numc)) * cos(t*twopi / numt);
				y = (1 + 0.1*cos(s*twopi / numc)) * sin(t*twopi / numt);
				z = 0.1 * sin(s * twopi / numc);
				glVertex3f(x, y, z);
			}
		}
		glEnd();
	}
}

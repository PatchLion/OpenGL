#include "stdafx.h"
#include "UnprojectTest.h"

CUnprojectTest::CUnprojectTest()
{
	
}

CUnprojectTest::~CUnprojectTest()
{
}

void CUnprojectTest::displayEvent()
{
	CLearnOpenGLBase::displayEvent();

	glPointSize(3);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1, 1, 1);
	for (int i = 0; i < m_vecVeritex.size(); i++)
	{
		double c = i * (1.0 / (double)i);
		glColor3f(c, 0, 0);
		glVertex3f(m_vecVeritex[i].x, m_vecVeritex[i].y, m_vecVeritex[i].z);
	}
	glEnd();

	glutSwapBuffers();
}

void CUnprojectTest::init()
{
	CLearnOpenGLBase::init();

	GLint redbit, greenbit, bluebit, alphabit, indexbit;
	glGetIntegerv(GL_RED_BITS, &redbit);
	glGetIntegerv(GL_GREEN_BITS, &greenbit);
	glGetIntegerv(GL_BLUE_BITS, &bluebit);
	glGetIntegerv(GL_ALPHA_BITS, &alphabit);
	glGetIntegerv(GL_INDEX_BITS, &indexbit);
	printf("RED_BITS: %d\n", redbit);
	printf("GREEN_BITS: %d\n", greenbit);
	printf("BLUE_BITS: %d\n", bluebit);
	printf("ALPHA_BITS: %d\n", alphabit);
	printf("INDEX_BITS: %d\n", indexbit);
}

void CUnprojectTest::mouseEvent(int button, int state, int x, int y)
{
	GLint viewport[4];
	GLdouble mvmatrix[16], projmatrix[16];
	GLint realy;
	GLdouble wx, wy, wz;

	switch (button)
	{
	case GLUT_LEFT_BUTTON:
	{
		if (GLUT_DOWN == state)
		{
			glGetIntegerv(GL_VIEWPORT, viewport);
			glGetDoublev(GL_MODELVIEW_MATRIX, mvmatrix);
			glGetDoublev(GL_PROJECTION_MATRIX, projmatrix);

			/*note viewport[3] is height of window in pixels*/
			realy = viewport[3] - (GLint)y - 1;
			printf("Coordinates at cursor are (%4d, %4d)\n", x, realy);

			gluUnProject((GLdouble)x, (GLdouble)realy, 0.0, mvmatrix, projmatrix, viewport, &wx, &wy, &wz);

			m_vecVeritex.push_back(stVeritex3f(wx, wy, wz));

			printf("World coords at z = 1.0 are (%f, %f, %f)\n", wx, wy, wz);

			glutPostRedisplay();
		}
	}
	case GLUT_RIGHT_BUTTON:
	{

	}
	}
}

void CUnprojectTest::keyPressedEvent(unsigned char key, int x, int y)
{
	if (26 == key) //ctrl + z
	{
		if (!m_vecVeritex.empty())
		{
			m_vecVeritex.pop_back();
		}
		
	}

	LearnOpenGL::CLearnOpenGLBase::keyPressedEvent(key, x, y);
}

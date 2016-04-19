#include "stdafx.h"
#include "LearnOpenGLBase.h"

LearnOpenGL::CLearnOpenGLBase* LearnOpenGL::CLearnOpenGLBase::current = 0;

void LearnOpenGL::CLearnOpenGLBase::s_display()
{
	if (CLearnOpenGLBase::current)
	{
		CLearnOpenGLBase::current->displayEvent();
	}
}

void LearnOpenGL::CLearnOpenGLBase::s_idle()
{
	if (CLearnOpenGLBase::current)
	{
		CLearnOpenGLBase::current->idleEvent();
	}
}

void LearnOpenGL::CLearnOpenGLBase::s_resize(int w, int h)
{
	if (CLearnOpenGLBase::current)
	{
		CLearnOpenGLBase::current->resizeEvent(w, h);
	}
}

void LearnOpenGL::CLearnOpenGLBase::s_mouse(int button, int state, int x, int y)
{
	if (CLearnOpenGLBase::current)
	{
		CLearnOpenGLBase::current->mouseEvent(button, state, x, y);
	}
}

void LearnOpenGL::CLearnOpenGLBase::s_mousePressedMove(int x, int y)
{
	if (CLearnOpenGLBase::current)
	{
		CLearnOpenGLBase::current->mousePressedMoveEvent(x,y);
	}
}

void LearnOpenGL::CLearnOpenGLBase::s_mouseMove(int x, int y)
{
	if (CLearnOpenGLBase::current)
	{
		CLearnOpenGLBase::current->mouseMoveEvent(x, y);
	}
}

void LearnOpenGL::CLearnOpenGLBase::s_keyPressed(unsigned char key, int x, int y)
{
	if (CLearnOpenGLBase::current)
	{
		CLearnOpenGLBase::current->keyPressedEvent(key, x, y);
	}
}

LearnOpenGL::CLearnOpenGLBase::CLearnOpenGLBase()
	: m_projectionType(Ortho2D)
	, m_currentWidth(0)
	, m_currentHeight(0)
{

}

LearnOpenGL::CLearnOpenGLBase::~CLearnOpenGLBase()
{

}

void LearnOpenGL::CLearnOpenGLBase::init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
}

void LearnOpenGL::CLearnOpenGLBase::resizeEvent(int w, int h)
{
	m_currentWidth = w;
	m_currentHeight = h;
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	changeProjectionType(projectionType());
}

void LearnOpenGL::CLearnOpenGLBase::displayEvent()
{
	drawLine3fWithColor(-2, 0, 0, 2, 0, 0, 1, 0, 0);
	drawLine3fWithColor(0, -2, 0, 0, 2, 0, 0, 1, 0);
	drawLine3fWithColor(0, 0, -2, 0, 0, 2, 0, 0, 1);

	glutSwapBuffers();
}

void LearnOpenGL::CLearnOpenGLBase::changeProjectionType(ProjectionType val)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	switch (val)
	{
	case LearnOpenGL::CLearnOpenGLBase::Perspective:
	{
		gluPerspective(120, (double)width() / (double)height(), 1, 5);

	}
	break;
	case LearnOpenGL::CLearnOpenGLBase::Ortho:
	{
		glOrtho(-1, 1, -1, 1, 1, 5);
	}
		break;
	case LearnOpenGL::CLearnOpenGLBase::Ortho2D:
	{
		gluOrtho2D(-1, 1, -1, 1);
	}
		break;
	}

	switch (val)
	{
	case LearnOpenGL::CLearnOpenGLBase::Perspective:
	case LearnOpenGL::CLearnOpenGLBase::Ortho:
	{
		glMatrixMode(GL_MODELVIEW);
		gluLookAt(2, 2, 2, 0, 0, 0, 0, 1, 0);
	}
		break;
	}
}

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
	: m_projectionType(Ortho)
	, m_currentWidth(0)
	, m_currentHeight(0)
	, m_yAngle(0)
	, m_bShowCoor(true)
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
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	switch (projectionType())
	{
	case LearnOpenGL::CLearnOpenGLBase::Perspective:
	case LearnOpenGL::CLearnOpenGLBase::Ortho:
	{

		gluLookAt(2, 2, 2, 0, 0, 0, 0, 1, 0);
		glRotatef(m_yAngle, 0, 1, 0);

		if (isShowCoordinates())
		{
			drawLine3fWithColor(-2, 0, 0, 2, 0, 0, 1, 0, 0);
			drawLine3fWithColor(0, -2, 0, 0, 2, 0, 0, 1, 0);
			drawLine3fWithColor(0, 0, -2, 0, 0, 2, 0, 0, 1);
		}


	}
		break;

	case LearnOpenGL::CLearnOpenGLBase::Ortho2D:
	{
		if (isShowCoordinates())
		{
			drawOneLine2fWithColor(-2, 0, 2, 0, 1.0, 0.0, 0.0);
			drawOneLine2fWithColor(0, 2, 0, -2, 0.0, 1.0, 0.0);
		}
	}
		break;
	}

}

void LearnOpenGL::CLearnOpenGLBase::changeProjectionType(ProjectionType val)
{
	m_projectionType = val;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	switch (val)
	{
	case LearnOpenGL::CLearnOpenGLBase::Perspective:
	{
		gluPerspective(120, (double)width() / (double)height(), 1, 10);

	}
	break;
	case LearnOpenGL::CLearnOpenGLBase::Ortho:
	{
		glOrtho(-2, 2, -2, 2, 1, 5);
	}
		break;
	case LearnOpenGL::CLearnOpenGLBase::Ortho2D:
	{
		gluOrtho2D(-2, 2, -2, 2);
	}
		break;
	}


}

void LearnOpenGL::CLearnOpenGLBase::keyPressedEvent(unsigned char key, int x, int y)
{
	printf("Key pressed: %d(%d, %d)\n", key, x, y);

	if (91 == key)//[
	{
		m_yAngle += 5;
	}
	else if (93 == key)//]
	{
		m_yAngle -= 5;
	}
	else if (49 == key)//1
	{
		changeProjectionType(Perspective);
	}
	else if (50 == key)//2
	{
		changeProjectionType(Ortho);
	}
	else if (51 == key)//3
	{
		changeProjectionType(Ortho2D);
	}
	else if (99 == key)//c
	{
		//隐藏显示坐标系
		setShowCoordinates(!isShowCoordinates());
	}
	else if (114 == key)//r
	{
		//重置
		m_yAngle = 0;
	}
	glutPostRedisplay();
}

void LearnOpenGL::CLearnOpenGLBase::setShowCoordinates(bool show)
{
	m_bShowCoor = show;
	glutPostRedisplay();
}

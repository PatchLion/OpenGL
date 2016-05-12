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

void LearnOpenGL::CLearnOpenGLBase::s_mouseWheel(int button, int dir, int x, int y)
{
	if (CLearnOpenGLBase::current)
	{
		CLearnOpenGLBase::current->mouseWheelEvent(button, dir, x, y);
	}
}

LearnOpenGL::CLearnOpenGLBase::CLearnOpenGLBase(bool doubleBuffer)
	: m_projectionType(Ortho)
	, m_currentWidth(0)
	, m_currentHeight(0)
	, m_yAngle(0)
	, m_bShowCoor(true)
	, m_bIsDoubleBuffer(doubleBuffer)
{
	resetAllValue();
	resetValueAndStepToDefault();
}

LearnOpenGL::CLearnOpenGLBase::~CLearnOpenGLBase()
{

}

void LearnOpenGL::CLearnOpenGLBase::init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (isDoubleBuffer())
	{
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	}
	else
	{
		glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
	}
	

	glEnable(GL_DEPTH_TEST);
	
	//glShadeModel(GL_SMOOTH);
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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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

	//glColor3f(1.0, 1.0, 1.0);

	flush();
}

void LearnOpenGL::CLearnOpenGLBase::changeProjectionType(ProjectionType val)
{
	m_projectionType = val;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	const double ratio = (double)width() / (double)height();
	switch (val)
	{
	case LearnOpenGL::CLearnOpenGLBase::Perspective:
	{
		gluPerspective(90, ratio, 1, 1000);

	}
	break;
	case LearnOpenGL::CLearnOpenGLBase::Ortho:
	{
		//glOrtho(-2, 2, -2, 2, 1, 10);
		if (width() <= height())
		{
			glOrtho(-2, 2, -2, 2 * (GLfloat)height() / (GLfloat)width(), 1, 10);
		}
		else
		{
			glOrtho(-2, 2 * (GLfloat)width() / (GLfloat)height(), -2, 2, 1, 10);
		}
	}
		break;
	case LearnOpenGL::CLearnOpenGLBase::Ortho2D:
	{
		if (width()<= height())
		{
			gluOrtho2D(-2, 2, -2, 2 * (GLfloat)height() / (GLfloat)width());
		}
		else
		{
			gluOrtho2D(-2, 2 * (GLfloat)width() / (GLfloat)height(), -2, 2);
		}
	}
		break;
	}

}

void LearnOpenGL::CLearnOpenGLBase::keyPressedEvent(unsigned char key, int x, int y)
{
	//printf("Key pressed: %d(%d, %d)\n", key, x, y);

	if ('[' == key)//[
	{
		printf("Current y angle = %d\n", m_yAngle);
		m_yAngle -= 5;
	}
	else if (']' == key)//]
	{
		m_yAngle += 5;
		printf("Current y angle = %d\n", m_yAngle);
	}
	else if ('q' == key)//q
	{
		changeProjectionType(Perspective);
		printf("->Perspective\n");
	}
	else if ('w' == key)//w
	{
		changeProjectionType(Ortho);
		printf("->Ortho\n");
	}
	else if ('e' == key)//e
	{
		changeProjectionType(Ortho2D);
		printf("->Ortho2D\n");
	}
	else if ('s' == key)//s
	{
		//隐藏显示坐标系
		setShowCoordinates(!isShowCoordinates());

		printf("Show coordinates: %s\n", (isShowCoordinates() ? "true" : "false"));
	}
	else if ('r' == key)//r
	{
		resetValueAndStepToDefault();

		//重置
		m_yAngle = 0;
		printf("Current y angle = %d\n", m_yAngle);
	}
	else if ('0' <= key && key <= '9')
	{
		//增加值
		int index = key - '0';
		m_indexToValue[index] += m_indexToStep[index];
		printf("Value[%d] = %f\n", index, m_indexToValue[index]);
	}
	char reduceKeys[10] = { ')', '!', '@', '#', '$', '%', '^', '&', '*', '(' };

	for (int i = 0; i < 10; i++)
	{
		//减少值
		if (reduceKeys[i] == key) //shift + 0
		{
			m_indexToValue[i] -= m_indexToStep[i];
			printf("Value[%d] = %f\n", i, m_indexToValue[i]);
			break;
		}
	}

	glutPostRedisplay();
}

void LearnOpenGL::CLearnOpenGLBase::setShowCoordinates(bool show)
{
	m_bShowCoor = show;

	glutPostRedisplay();
	
}

double LearnOpenGL::CLearnOpenGLBase::calculateAngle(double size, double distance)
{
	double radtheta, degtheta;
	radtheta = 2.0 * atan2(size / 2.0, distance);
	degtheta = (180 * radtheta) / M_PI;
	return degtheta;
}

double LearnOpenGL::CLearnOpenGLBase::value(int index) const
{
	if (index < 0 || index > 9)
	{
		return 0.0;
	}
	return m_indexToValue[index];
}

double LearnOpenGL::CLearnOpenGLBase::valueStep(int index) const
{
	if (index < 0 || index > 9)
	{
		return 0.0;
	}
	return m_indexToStep[index];
}

void LearnOpenGL::CLearnOpenGLBase::setValueStep(int index, double step)
{
	if (index < 0 || index > 9)
	{
		return;
	}
	m_indexToStep[index] = step;
}

void LearnOpenGL::CLearnOpenGLBase::setDefaultValue(int index, double value)
{
	if (index < 0 || index > 9)
	{
		return;
	}
	m_indexToValue[index] = m_indexToDefaultValue[index] = value;
	
}

void LearnOpenGL::CLearnOpenGLBase::resetValueAndStepToDefault()
{
	for (int i = 0; i < 10; i++)
	{
		m_indexToValue[i] = m_indexToDefaultValue[i];
	}
}

void LearnOpenGL::CLearnOpenGLBase::resetAllValue()
{
	for (int i = 0; i < 10; i++)
	{
		m_indexToDefaultValue[i] = m_indexToValue[i] = 0;
		m_indexToStep[i] = 1.0;
	}
}

void LearnOpenGL::CLearnOpenGLBase::mouseWheelEvent(int button, int dir, int x, int y)
{
	//printf("mouseWheelEvent: %d, %d, %d, %d\n", button, dir, x, y);
}

void LearnOpenGL::CLearnOpenGLBase::flush()
{
	if (isDoubleBuffer())
	{
		glutSwapBuffers();
	}
	else
	{
		glFlush();
	}
}

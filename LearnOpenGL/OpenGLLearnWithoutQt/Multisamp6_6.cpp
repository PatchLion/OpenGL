#include "stdafx.h"
#include "Multisamp6_6.h"

CMultisamp6_6::CMultisamp6_6()
{
	m_bgToggle = true;
}

CMultisamp6_6::~CMultisamp6_6()
{
}

void CMultisamp6_6::displayEvent()
{
	CLearnOpenGLBase::displayEvent();

	glPushAttrib(GL_LINE_WIDTH);
	glLineWidth(value(1));
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(0.25, 0.05);
	glVertex2f(0.9, 0.2);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 1.0, 1.0);
	glVertex2f(0.25, 0);
	glVertex2f(0.9, 0.0);
	glVertex2f(0.875, 0.10);
	glEnd();

	if (m_bgToggle)
	{
		glBegin(GL_QUADS);
		for (int i = 0; i < 16; i++)
		{
			for (int j = 0; j < 16; j++)
			{
				if ((i + j) % 2 == 0)
				{
					glVertex2f(-2.0 + (i*0.25), -2.0 + (j*0.25));
					glVertex2f(-2.0 + (i*0.25), -1.75 + (j*0.25));
					glVertex2f(-1.75 + (i*0.25), -1.75 + (j*0.25));
					glVertex2f(-1.75 + (i*0.25), -2.0 + (j*0.25));
				}
			}
		}
		glEnd();
	}
	
	glPopAttrib();
	glutSwapBuffers();
	
}

void CMultisamp6_6::init()
{
	CLearnOpenGLBase::init();

	//
	//glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_MULTISAMPLE);
	glEnable(GL_MULTISAMPLE);
	GLint buf, sbuf;
	
	glGetIntegerv(GL_SAMPLE_BUFFERS, &buf);
	printf("number of sample buffers is %d\n", buf);

	glGetIntegerv(GL_SAMPLES, &sbuf);
	printf("number of samples is %d\n", sbuf);

	GLfloat width[2];  //存储直线的宽度范围
	GLfloat step;  //存储受支持的直线宽度增量

	//获取受支持的直线宽度范围和增量  
	glGetFloatv(GL_LINE_WIDTH_RANGE, width);
	glGetFloatv(GL_LINE_WIDTH_GRANULARITY, &step);

	printf("GL_LINE_WIDTH_RANGE is %f %f\n", width[0], width[1]);
	printf("GL_LINE_WIDTH_GRANULARITY is %f\n", step);
}

void CMultisamp6_6::keyPressedEvent(unsigned char key, int x, int y)
{
	if ('z' == key)
	{
		m_bgToggle = !m_bgToggle;
	}
	LearnOpenGL::CLearnOpenGLBase::keyPressedEvent(key, x, y);
}
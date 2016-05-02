#include "stdafx.h"
#include "HierarchicalDisplayList7_3.h"

CP Adata[] = { { 0, 0, PT }, { 0, 9, PT }, { 1, 10, PT },{ 4, 10, PT },
	{ 5, 9, PT }, { 5, 0, STROKE }, { 0, 5, PT }, { 5, 5, END } };

CP Edata[] = { { 5, 0, PT }, { 0, 0, PT }, { 0, 10, PT }, { 5, 10, STROKE },
{ 0, 5, PT }, { 4, 5, END } };

CP Pdata[] = { { 0, 0, PT }, { 0, 10, PT }, { 4, 10, PT }, { 5, 9, PT }, { 5, 6, PT },
{ 4, 5, PT }, { 0, 5, END } };

CP Rdata[] = { { 0, 0, PT }, { 0, 10, PT }, { 4, 10, PT }, { 5, 9, PT }, { 5, 6, PT },
{ 4, 5, PT }, { 0, 5, STROKE }, { 3, 5, PT }, { 5, 0, END } };

CP Sdata[] = { { 0, 1, PT }, { 1, 0, PT }, { 4, 0, PT }, { 5, 1, PT }, { 5, 4, PT },
{ 4, 5, PT }, { 1, 5, PT }, { 0, 6, PT }, { 0, 9, PT }, { 1, 10, PT },
{ 4, 10, PT }, { 5, 9, END } };

char *test1 = "A SPARE SERAPE APPEARS AS ";
char *test2 = "APES PREPARE RARE PEPPERS ";

CHierarchicalDisplayList7_3::CHierarchicalDisplayList7_3()
{
}

CHierarchicalDisplayList7_3::~CHierarchicalDisplayList7_3()
{
	//glDeleteLists(m_unListIndex, 4);
}


void CHierarchicalDisplayList7_3::displayEvent()
{
	CLearnOpenGLBase::displayEvent();

	glPushMatrix();
	glTranslatef(0.1, 1.0, 0.0);
	printStrokedString(test1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.1, 0.1, 0.0);
	printStrokedString(test2);
	glPopMatrix();

	glutSwapBuffers();
}

void CHierarchicalDisplayList7_3::init()
{
	CLearnOpenGLBase::init();


	initStrokedFont();

/*
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_BLEND);*/

}

void CHierarchicalDisplayList7_3::keyPressedEvent(unsigned char key, int x, int y)
{
	LearnOpenGL::CLearnOpenGLBase::keyPressedEvent(key, x, y);
}

void CHierarchicalDisplayList7_3::initStrokedFont()
{
	GLuint base;
	base = glGenLists(128);

	glNewList(base + 'A' -1, GL_COMPILE);
	drawLetter(Adata);
	glEndList();

	glNewList(base + 'E' - 1, GL_COMPILE);
	drawLetter(Edata);
	glEndList();

	glNewList(base + 'P' - 1, GL_COMPILE);
	drawLetter(Pdata);
	glEndList();

	glNewList(base + 'R' - 1, GL_COMPILE);
	drawLetter(Rdata);
	glEndList();

	glNewList(base + 'S' - 1, GL_COMPILE);
	drawLetter(Sdata);
	glEndList();

	glNewList(base + ' ' - 1, GL_COMPILE);
	glTranslatef(0.1, 0.0, 0.0);
	glEndList();
}

void CHierarchicalDisplayList7_3::drawLetter(CP *l)
{
	glBegin(GL_LINE_STRIP);

	const double SCALE = 25.0;
	while (1)
	{
		switch (l->type)
		{
		case PT:
			glVertex2f(l->x / SCALE + 0.1, l->y / SCALE);
			break;

		case STROKE:
			glVertex2f(l->x / SCALE + 0.1, l->y / SCALE);
			glEnd();
			glBegin(GL_LINE_STRIP);
			//glTranslatef(0.01, 0.0, 0.0);
			break;

		case END:
			glVertex2f(l->x / SCALE + 0.1, l->y / SCALE);
			glEnd();
			glTranslatef(0.2, 0.0, 0.0);
			return;

		default:
			break;
		}

		l++;
	}
}

void CHierarchicalDisplayList7_3::printStrokedString(char *s)
{
	GLint len = strlen(s);
	glCallLists(len, GL_BYTE, s);
}

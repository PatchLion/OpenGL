#include "stdafx.h"
#include "AargbPolygon.h"

#define MAXZ 2.0
#define MINZ -2.0
#define ZINC 0.01
static float solidz = MAXZ;
static float transparentZ = MINZ;

CAargbPolygon::CAargbPolygon()
{

}

CAargbPolygon::~CAargbPolygon()
{
}

void CAargbPolygon::displayEvent()
{
	CLearnOpenGLBase::displayEvent();



	// 设置逆时针绘制一个正方形
	glBegin(GL_POLYGON);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.0f, -0.5f);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(-0.5f, 0.0f);
	glEnd();
	// 设置顺时针绘制一个正方形
	glBegin(GL_POLYGON);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.0f, 0.5f);
	glVertex2f(0.5f, 0.5f);
	glVertex2f(0.5f, 0.0f);
	glEnd();

	
	glutSwapBuffers();
}

void CAargbPolygon::init()
{
	CLearnOpenGLBase::init();

	glEnable(GL_POLYGON_SMOOTH);
	glEnable(GL_LINE_SMOOTH);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);//设置混合函数
	glEnable(GL_BLEND);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);

	// 设置正面为填充模式
	glPolygonMode(GL_FRONT, GL_FILL);
	// 设置反面为线形模式
	glPolygonMode(GL_BACK, GL_LINE);

}

void CAargbPolygon::keyPressedEvent(unsigned char key, int x, int y)
{
	LearnOpenGL::CLearnOpenGLBase::keyPressedEvent(key, x, y);
}
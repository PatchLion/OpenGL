#include "stdafx.h"
#include "DrawIcosahedronEx.h"

#define X .525731112119133606
#define Z .850650808352039932 
namespace Icosahedron
{
	static GLfloat vdata[12][3] = { { -X, 0.0, Z }, { X, 0.0, Z }, { -X, 0.0, -Z }, { X, 0.0, -Z }, { 0.0, Z, X }, { 0.0, Z, -X }, { 0.0, -Z, X }, { 0.0, -Z, -X }, { Z, X, 0.0 }, { -Z, X, 0.0 }, { Z, -X, 0.0 }, { -Z, -X, 0.0 } };
	static GLuint tindices[20][3] = { { 1, 4, 0 }, { 4, 9, 0 }, { 4, 5, 9 }, { 8, 5, 4 }, { 1, 8, 4 }, { 1, 10, 8 }, { 10, 3, 8 }, { 8, 3, 5 }, { 3, 2, 5 }, { 3, 7, 2 }, { 3, 10, 7 }, { 10, 6, 7 }, { 6, 11, 7 }, { 6, 0, 11 }, { 6, 1, 0 }, { 10, 1, 6 }, { 11, 0, 9 }, { 2, 11, 9 }, { 5, 2, 9 }, { 11, 2, 7 } };
}

CDrawIcosahedronEx::CDrawIcosahedronEx()
{
	
}

CDrawIcosahedronEx::~CDrawIcosahedronEx()
{
}

//计算两个向量的规范化向量积
void normalize(GLfloat v[3])
{
	printf("Before normalize: %f, %f, %f\n", v[0], v[1], v[2]);
	GLfloat d = sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
	if (d == 0.0)
	{
		printf("zero length vector!");
		return;
	}
	v[0] /= d;
	v[1] /= d;
	v[2] /= d;
	printf("After normalize: %f, %f, %f\n", v[0], v[1], v[2]);
}
void normCrossProd(GLfloat v1[3], GLfloat v2[3], GLfloat out[3])
{
	out[0] = v1[1] * v2[2] - v1[2] * v2[1];
	out[1] = v1[2] * v2[0] - v1[0] * v2[2];
	out[2] = v1[0] * v2[1] - v1[1] * v2[0];
	normalize(out);
}
void drawTriangle(GLfloat *v1, GLfloat *v2, GLfloat *v3)
{
	glBegin(GL_TRIANGLES);
	glNormal3fv(v1);
	glVertex3fv(v1);
	glNormal3fv(v2);
	glVertex3fv(v2);
	glNormal3fv(v3);
	glVertex3fv(v3);
	glEnd();
}

void subDivide(GLfloat *v1, GLfloat *v2, GLfloat *v3, long depth)
{
	GLfloat v12[3], v23[3], v31[3];


	GLuint i;

	if (0 == depth)
	{
		drawTriangle(v1, v2, v3);
		return;
	}

	for (i = 0; i < 3; i++)
	{
		v12[i] = (v1[i] + v2[i]) / 2.0;
		v23[i] = (v2[i] + v3[i]) / 2.0;
		v31[i] = (v3[i] + v1[i]) / 2.0;
	}

	normalize(v12);
	normalize(v23);
	normalize(v31);

	glColor3f(1.0, 0.0, 0.0);
	subDivide(v1, v12, v31, depth-1);
	glColor3f(0.0, 1.0, 0.0);
	subDivide(v2, v23, v12, depth - 1);
	glColor3f(0.0, 0.0, 1.0);
	subDivide(v3, v31, v23, depth - 1);
	glColor3f(1.0, 0.0, 1.0);
	subDivide(v12, v23, v31, depth - 1);
}


void CDrawIcosahedronEx::displayEvent()
{
	CLearnOpenGLBase::displayEvent();

/*

	GLuint i;
	for (i = 0; i < 20; i++)
	{
		glColor3f(i * 1.0 / 20.0, 1 - i * 1.0 / 20.0, 1 - i * 1.0 / 20.0);
		subDivide(Icosahedron::vdata[Icosahedron::tindices[i][0]],
			Icosahedron::vdata[Icosahedron::tindices[i][1]],
			Icosahedron::vdata[Icosahedron::tindices[i][2]], 1);
	}*/

	//glBegin(GL_TRIANGLES);
	GLfloat v1[3] = { 2, 0, 0 };
	GLfloat v2[3] = { 0, 2, 0 };
	GLfloat v3[3] = { 0, 0, 2 };
	subDivide(v1, v2, v3, 3);
	//glEnd();

	glutSwapBuffers();
}

void CDrawIcosahedronEx::init()
{
	CLearnOpenGLBase::init();

/*
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);*/
}

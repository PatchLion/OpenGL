#include "stdafx.h"
#include "DrawIcosahedronEx.h"

#define X .525731112119133606
#define Z .850650808352039932 
namespace Icosahedron
{
	const static GLfloat vdata[12][3] = { { -X, 0.0, Z }, { X, 0.0, Z }, { -X, 0.0, -Z }, { X, 0.0, -Z }, { 0.0, Z, X }, { 0.0, Z, -X }, { 0.0, -Z, X }, { 0.0, -Z, -X }, { Z, X, 0.0 }, { -Z, X, 0.0 }, { Z, -X, 0.0 }, { -Z, -X, 0.0 } };
	const static GLuint tindices[20][3] = { { 1, 4, 0 }, { 4, 9, 0 }, { 4, 5, 9 }, { 8, 5, 4 }, { 1, 8, 4 }, { 1, 10, 8 }, { 10, 3, 8 }, { 8, 3, 5 }, { 3, 2, 5 }, { 3, 7, 2 }, { 3, 10, 7 }, { 10, 6, 7 }, { 6, 11, 7 }, { 6, 0, 11 }, { 6, 1, 0 }, { 10, 1, 6 }, { 11, 0, 9 }, { 2, 11, 9 }, { 5, 2, 9 }, { 11, 2, 7 } };
}

CDrawIcosahedronEx::CDrawIcosahedronEx()
{
	
}

CDrawIcosahedronEx::~CDrawIcosahedronEx()
{
}

//计算两个向量的规范化向量积
void normalize(float v[3])
{
	GLfloat d = sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
	if (d == 0.0)
	{
		printf("zero length vector!");
		return;
	}
	v[0] /= d;
	v[1] /= d;
	v[2] /= d;
}
void CDrawIcosahedronEx::displayEvent()
{
	CLearnOpenGLBase::displayEvent();

	glBegin(GL_TRIANGLES); 
	for (int i = 0; i < 20; i++) 
	{
		GLfloat cf = (float)i / 20.0;
		glColor3f(cf + 0.1, cf + 0.1, cf + 0.1);
		glVertex3fv(&Icosahedron::vdata[Icosahedron::tindices[i][0]][0]);
		glVertex3fv(&Icosahedron::vdata[Icosahedron::tindices[i][1]][0]);
		glVertex3fv(&Icosahedron::vdata[Icosahedron::tindices[i][2]][0]);
	} 
	glEnd();

	glutSwapBuffers();
}

void CDrawIcosahedronEx::init()
{
	CLearnOpenGLBase::init();

	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
}

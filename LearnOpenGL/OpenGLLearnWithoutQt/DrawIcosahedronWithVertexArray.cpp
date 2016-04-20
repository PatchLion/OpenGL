#include "stdafx.h"
#include "DrawIcosahedronWithVertexArray.h"


#define X 0.52573
#define Z 0.85065
namespace IcosahedronWithVertexArray
{

	static GLfloat vertexs[] = { -X, 0.0, Z,
		X, 0.0, Z,
		-X, 0.0, -Z,
		X, 0.0, -Z,
		0.0, Z, X,
		0.0, Z, -X,
		0.0, -Z, X,
		0.0, -Z, -X,
		Z, X, 0.0,
		-Z, X, 0.0,
		Z, -X, 0.0,
		-Z, -X, 0.0
	};
	static GLfloat colors[] = { 0.0, 0.0, 0.0,
		1.0, 0.0, 0.0,
		1.0, 1.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 0.0, 1.0,
		1.0, 0.0, 1.0,
		1.0, 1.0, 1.0,
		0.0, 1.0, 1.0,
		1.0, 0.0, 0.0,
		1.0, 1.0, 0.0,
	};
	static GLint  index[] = {
		1, 4, 0,
		4, 9, 0,
		4, 5, 9,
		8, 5, 4,
		1, 8, 4,
		1, 10, 8,
		10, 3, 8,
		8, 3, 5,
		3, 2, 5,
		3, 7, 2,
		3, 10, 7,
		10, 6, 7,
		6, 11, 7,
		6, 0, 11,
		6, 1, 0,
		10, 1, 6,
		11, 0, 9,
		2, 11, 9,
		5, 2, 9,
		11, 2, 7 };
}

CDrawIcosahedronWithVertexArray::CDrawIcosahedronWithVertexArray()
{
	
}

CDrawIcosahedronWithVertexArray::~CDrawIcosahedronWithVertexArray()
{
}

void CDrawIcosahedronWithVertexArray::displayEvent()
{
	CLearnOpenGLBase::displayEvent();

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, IcosahedronWithVertexArray::vertexs);
	glColorPointer(3, GL_FLOAT, 0, IcosahedronWithVertexArray::colors);
	glDrawElements(GL_TRIANGLE_FAN, 100, GL_UNSIGNED_SHORT, IcosahedronWithVertexArray::index);

	glutSwapBuffers();
}

void CDrawIcosahedronWithVertexArray::init()
{
	CLearnOpenGLBase::init();
/*

	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);*/
}

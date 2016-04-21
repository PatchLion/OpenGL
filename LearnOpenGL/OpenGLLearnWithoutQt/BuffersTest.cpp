#include "stdafx.h"
#include "BuffersTest.h"

CBuffersTest::CBuffersTest()
{
	
}

CBuffersTest::~CBuffersTest()
{
}

void CBuffersTest::displayEvent()
{
	CLearnOpenGLBase::displayEvent();

	glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, BUFFER_OFFSET(0));

	glutSwapBuffers();
}

#define VERTICES 0
#define INDICES 1
#define COLORS 2
#define NUM_BUFFERS 2
GLuint buffers[NUM_BUFFERS];

GLfloat vertices[][3] = {
	{-0.5, -0.5, -0.5},
	{ 0.5, -0.5, -0.5 },
	{ 0.5, 0.5, -0.5 },
	{ -0.5, 0.5, -0.5 },
	{ -0.5, -0.5, 0.5 },
	{ 0.5, -0.5, 0.5 },
	{ 0.5, 0.5, 0.5 },
	{ -0.5, 0.5, 0.5 }
};


GLubyte indices[][4] = {
	{ 0, 1, 2, 3 },
	{ 4, 7, 6, 5 },
	{ 0, 4, 5, 1 },
	{ 3, 2, 6, 7 },
	{ 0, 3, 7, 4 },
	{ 1, 5, 6, 2 }
};

void CBuffersTest::init()
{
	CLearnOpenGLBase::init();

	glGenBuffers(NUM_BUFFERS, buffers);
	glBindBuffer(GL_ARRAY_BUFFER, buffers[VERTICES]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexPointer(3, GL_FLOAT, 0, BUFFER_OFFSET(0));
	glEnableClientState(GL_VERTEX_ARRAY);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[INDICES]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

}

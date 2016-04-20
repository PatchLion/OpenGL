#include "stdafx.h"
#include "PrimrestartTest.h"


#define XStart -0.8
#define XEnd 0.8
#define YStart -0.8
#define YEnd 0.8

#define NumXPoints 3
#define NumYPoints 3
#define NumPoints  (NumXPoints * NumYPoints)
#define NumStrips  (NumYPoints-1)
#define NumPointsPerStrip (2*NumXPoints)
#define RestartIndex 0xffff

CPrimrestartTest::CPrimrestartTest()
{
	
}

CPrimrestartTest::~CPrimrestartTest()
{
}

void CPrimrestartTest::displayEvent()
{
	CLearnOpenGLBase::displayEvent();

	int i, start;

	glDrawElements(GL_TRIANGLES, NumStrips*(NumPointsPerStrip + 1), GL_UNSIGNED_SHORT, BUFFER_OFFSET(0));

	glutSwapBuffers();
}

void CPrimrestartTest::init()
{
	CLearnOpenGLBase::init();

	GLuint vbo, ebo;
	GLfloat *vertices;
	GLushort *indices;

	/*Set up vertex data*/
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glBufferData(GL_ARRAY_BUFFER, 2 * NumPoints*sizeof(GLfloat), NULL, GL_STATIC_DRAW);

	vertices = (GLfloat*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);

	if (vertices == NULL)
	{
		fprintf(stderr, "Unable to map vertex buffer!\n");
	}
	else
	{
		int i, j;
		GLfloat dx = (XEnd - XStart) / (NumXPoints - 1);
		GLfloat dy = (YEnd - YStart) / (NumYPoints - 1);

		GLfloat* temp = vertices;

		int n = 0;

		for (j = 0; j < NumYPoints; ++j)
		{
			GLfloat y = YStart + j * dy;
			for (i = 0; i < NumXPoints; ++i)
			{
				GLfloat x = XStart + i*dx;
				*temp++ = x;
				*temp++ = y;
			}
		}

		glUnmapBuffer(GL_ARRAY_BUFFER);
		glVertexPointer(2, GL_FLOAT, 0, BUFFER_OFFSET(0));
		glEnableClientState(GL_VERTEX_ARRAY);
	}

	/*Set up index data*/
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

	/*We allocate an extra restart index because it simplifies
	the element-array loop logic*/
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, NumStrips*(NumPointsPerStrip + 1) * sizeof(GLushort), NULL, GL_STATIC_DRAW);
	indices = (GLushort *)glMapBuffer(GL_ELEMENT_ARRAY_BUFFER, GL_WRITE_ONLY);

	if (indices == NULL)
	{
		fprintf(stderr, "Unable to map index buffer!\n");
	}
	else
	{
		int i, j;
		GLushort *index = indices;

		for (j = 0; j < NumStrips; ++j)
		{
			GLushort bottomRow = j*NumYPoints;

			GLushort topRow = bottomRow + NumYPoints;

			for (i = 0; i < NumXPoints; ++i)
			{
				*index++ = topRow + i;
				*index++ = bottomRow + i;
			}
			*index++ = RestartIndex;
		}
		glUnmapBuffer(GL_ELEMENT_ARRAY_BUFFER);
	}

	glPrimitiveRestartIndex(RestartIndex);
	glEnable(GL_PRIMITIVE_RESTART);
}

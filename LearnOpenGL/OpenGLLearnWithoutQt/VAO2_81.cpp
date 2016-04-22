#include "stdafx.h"
#include "VAO2_81.h"
#include <math.h>

struct vec3
{
	GLfloat x, y, z;
};

struct XForm
{
	vec3 xlate; /*Translation*/
	GLfloat angle;
	vec3 axis;
};

#define NumConePoints 36

enum {Cube, Cone, NumVAOs};

GLuint VAO[NumVAOs];
GLenum PrimType[NumVAOs];
GLsizei NumElements[NumVAOs];

XForm xform[NumVAOs] = {
	{ { -1.0, 0.0, 0.0 }, 0.0, {0.0, 1.0, 0.0} },
	{ { 0.0, 0.0, 1.0 }, 0.0, { 1.0, 0.0, 0.0 } }
};

//GLfloat Angle = 0;

CVAO2_81::CVAO2_81()
{

}

CVAO2_81::~CVAO2_81()
{
}

void CVAO2_81::displayEvent()
{	
	glPushMatrix();
	CLearnOpenGLBase::displayEvent();

	int i;


	//glRotatef(Angle, 0.0, 1.0, 0.0);

	for (i = 0; i < NumVAOs; ++i)
	{
		glPushMatrix();
		glTranslatef(xform[i].xlate.x, xform[i].xlate.y, xform[i].xlate.z);
		glRotatef(xform[i].angle, xform[i].axis.x, xform[i].axis.y, xform[i].axis.z);
		glBindVertexArray(VAO[i]);
		glDrawElements(PrimType[i], NumElements[i], GL_UNSIGNED_BYTE, BUFFER_OFFSET(0));
		glPopMatrix();
	}
	glPopMatrix();
	glutSwapBuffers();
}

void CVAO2_81::init()
{
	CLearnOpenGLBase::init();

	enum {Vertices, Colors, Elements, NumVBOs};
	GLuint buffers[NumVBOs];

	glGenVertexArrays(NumVAOs, VAO);

	{
		GLfloat cubVerts[][3] = {
			{-1.0, -1.0, -1.0},
			{ -1.0, -1.0, 1.0 },
			{ -1.0, 1.0, -1.0 },
			{ -1.0, 1.0, 1.0 },
			{ 1.0, -1.0, -1.0 },
			{ 1.0, -1.0, 1.0 },
			{ 1.0, 1.0, -1.0 },
			{ 1.0, 1.0, 1.0 }
		};

		GLfloat cubeColors[][3] = {
			{0.0, 0.0, 0.0},
			{ 0.0, 0.0, 1.0 },
			{ 0.0, 1.0, 0.0 },
			{ 0.0, 1.0, 1.0 },
			{ 1.0, 0.0, 0.0 },
			{ 1.0, 0.0, 1.0 },
			{ 1.0, 1.0, 0.0 },
			{ 1.0, 1.0, 1.0 }
		};

		GLubyte cubeIndices[] = {
			0, 1, 3, 2,
			4, 6, 7, 5, 
			2, 3, 7, 6, 
			0, 4, 5, 1,
			0, 2, 6, 4, 
			1, 5, 7, 3
		};

		glBindVertexArray(VAO[Cube]);
		glGenBuffers(NumVBOs, buffers);
		glBindBuffer(GL_ARRAY_BUFFER, buffers[Vertices]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(cubVerts), cubVerts, GL_STATIC_DRAW);
		glVertexPointer(3, GL_FLOAT, 0, BUFFER_OFFSET(0));
		glEnableClientState(GL_VERTEX_ARRAY);


		glBindBuffer(GL_COLOR_ARRAY, buffers[Colors]);
		glBufferData(GL_COLOR_ARRAY, sizeof(cubeColors), cubeColors, GL_STATIC_DRAW);
		glColorPointer(3, GL_FLOAT, 0, BUFFER_OFFSET(0));
		glEnableClientState(GL_COLOR_ARRAY);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[Elements]);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cubeIndices), cubeIndices, GL_STATIC_DRAW);

		PrimType[Cube] = GL_QUADS;
		NumElements[Cube] = NumberOf(cubeIndices);
	}

	{

		float dTheta;
		/*We add one more vertex for the cone's apex*/
		GLfloat coneVerts[NumConePoints + 1][3] = {
			{ 0.0, 0.0, 1.0 }
		};

		GLfloat coneColors[NumConePoints + 1][3] = {
			{ 1.0, 1.0, 1.0 }
		};

		GLubyte coneIndices[NumConePoints + 1];

		dTheta = 2 * M_PI / (NumConePoints - 1);

		int i, idx;

		idx = 1;

		for (i = 0; i < NumConePoints; ++i, ++idx)
		{
			float theta = i * dTheta;

			coneVerts[idx][0] = cos(theta);
			coneVerts[idx][1] = sin(theta);
			coneVerts[idx][2] = 1.0;

			coneColors[idx][0] = cos(theta);
			coneColors[idx][1] = sin(theta);
			coneColors[idx][2] = 0.0;

			coneIndices[idx] = idx;
		}

		glBindVertexArray(VAO[Cone]);
		glGenBuffers(NumVBOs, buffers);
		glBindBuffer(GL_ARRAY_BUFFER, buffers[Vertices]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(coneVerts), coneVerts, GL_STATIC_DRAW);
		glVertexPointer(3, GL_FLOAT, 0, BUFFER_OFFSET(0));
		glEnableClientState(GL_VERTEX_ARRAY);

		glBindBuffer(GL_ARRAY_BUFFER, buffers[Colors]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(coneColors), coneColors, GL_STATIC_DRAW);
		glColorPointer(3, GL_FLOAT, 0, BUFFER_OFFSET(0));
		glEnableClientState(GL_COLOR_ARRAY);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[Elements]);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(coneIndices), coneIndices, GL_STATIC_DRAW);
		
		PrimType[Cone] = GL_TRIANGLE_FAN;
		NumElements[Cone] = NumberOf(coneIndices);
	}

}

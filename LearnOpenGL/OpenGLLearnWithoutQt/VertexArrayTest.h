/*
#include "LoadShaders.h"
#include "triangles.h"*/

#include "stdafx.h"

#pragma comment (lib, "glew32.lib")
using namespace std;

#define drawOneLineWithColor(x1, y1, z1, x2, y2, z2, r, g, b) 		glBegin(GL_LINES);\
glColor3f(r, g, b);\
glVertex3f(x1, y1, z1);\
glVertex3f(x2, y2, z2);\
glEnd();
namespace VertexArrayTest
{

	static GLint vertices[] = {
		25, 25,
		100, 325, 
		175, 25, 
		175, 325, 
		250, 25, 
		325, 325};
	static GLint vertices3i[] = {
		-50, -50, 50, //0
		-50, -50, -50, //1 
		50, -50, -50, //2
		50, -50, 50, //3
		50, 50, 50, //4
		50, 50, -50, //5
		-50, 50, -50, //6
		-50, 50, 50 //7
	};
	static GLint verticesU3i[] = {
		-1, -1, 1, //0
		-1, -1, -1, //1 
		1, -1, -1, //2
		1, -1, 1, //3
		1, 1, 1, //4
		1, 1, -1, //5
		-1, 1, -1, //6
		-1, 1, 1 //7
	};
	static GLfloat colors[] = { 
		1, 1, 1,
		1.0, 0.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 0.0, 1.0,
		0.8, 0.75, 0.75,
		0.35, 0.75, 0.35,
		0.5, 0.9, 0.5,
		0.7, 0.5, 0.5};

	static GLfloat interwined[] = {
		1.0, 0.0, 0.0, 0.0, 0.0, 0.0,   //0
		0.0, 1.0, 0.0, 0.0, 100.0, 0.0, //1
		0.0, 0.0, 1.0, 100.0, 100.0, 0.0, //2
		1.0, 1.0, 1.0, 100.0, 0.0, 0.0, //3
		0.5, 0.5, 0.5, 100.0, 100.0, 100.0, //4
		0.4, 0.4, 0.4, 000.0, 100.0, 100.0, 	//5	
		0.3, 0.3, 0.3, 100.0, 000.0, 100.0,//6
		0.2, 0.2, 0.2, 0.0, 0.0, 100.0 };//7

	static GLushort allIndices[] = { 
	4, 5, 6, 7, 1, 6, 5, 2,
	0, 7, 6, 1, 0, 1, 2, 3,
	0, 3, 4, 7, 2, 5, 4, 3, 
	2, 1, 6, 5 };

	//四个顶点  
	float pfVer[] = { 0.0f, 0.0f, 0.0f, 
		100.0f, 0.0f, 0.0f, 
		100.0f, 100.0f, 0.0f, 
		0.0f, 100.0f, 0.0f };

	//两个面  
	short piInd[] = { 0, 1, 2, 
		2, 3, 0 };

	GLfloat colors2[] = {
		0.0, 1.0, 0.0,
		0.0, 0.0, 1.0 };

	GLubyte oneIndices[] = {0, 1, 2, 3, 4, 5, 6};
	GLubyte twoIndices[] = { 7, 1, 8, 9, 10, 11 };

	double xpos = 120, ypos = 120, zpos = 120;
	double angleX = 70;
	double angleY = 0;
	bool bIsGreen = false;
	int linecount = 3;
	void showFunction(void)
	{
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);



		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		gluLookAt(120, 120, 120, 0, 0, 0, 0, 1, 0);
		glRotatef(angleX, angleY, 1, 0);
		//glTranslatef(-50, -50, -50);

		glLineWidth(3);
		drawOneLineWithColor(-200, 0, 0, 200, 0, 0, 1, 0, 0);
		drawOneLineWithColor(0, -200, 0, 0, 200, 0, 0, 1, 0);
		drawOneLineWithColor(0, 0, -200, 0, 0, 200, 0, 0, 1);

		//glRotatef(angle, 0, 0.5, 0);

		//glDrawElements(GL_QUADS, 24, GL_UNSIGNED_SHORT, (GLvoid*)allIndices);
		
		GLsizei count[] = { 7, 6 };
		GLvoid * indices[2] = { oneIndices, twoIndices };
		//glMultiDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_BYTE, indices, 2);
		//glDrawRangeElements(GL_LINE_LOOP, 0, 6, linecount, GL_UNSIGNED_BYTE, oneIndices);
		glDrawArrays(GL_LINE_LOOP, 0, linecount);

		glutSwapBuffers();
	}

	void idleFunc(void)
	{
		//printf("idle function!\n");
	}

	void reshapeFunc(int w, int h)
	{
		printf("Reshape: %d, %d\n", w, h);
		glViewport(0, 0, (GLsizei)w, (GLsizei)h);	
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity(); 
		gluPerspective(120, (double)w/(double)h, 1, 1000);
		//glOrtho(-120, 120, -120, 120, 1, 2000);
	}



	void keyboardFunc(unsigned char key, int x, int y)
	{
		printf("Press key: %d\n", key);

		if (122 == key) //z
		{
			xpos += 5;
		}
		else if ( 120 == key)//x
		{
			xpos -= 5;
		}

		if (99 == key) //c
		{
			ypos += 5;
		}
		else if (118 == key)//v
		{
			ypos -= 5;
		}

		if (98 == key) //b
		{
			zpos += 5;
		}
		else if (110 == key)//n
		{
			zpos -= 5;
		}
		if (43 == key) //+
		{
			linecount += 1;
		}
		else if (45 == key)//-
		{
			linecount -= 1;
		}
		glutPostRedisplay();
	}

	int lastMX = 0, lastMY = 0;
	int oriAngleX = angleX;
	int oriAngleY = angleY;
	void mousePressedMoveFunc(int x, int y)
	{
		int angleOffsetX = (x - lastMX) / 3;
		int angleOffsetY = (lastMY - y) / 10;
		angleX = (oriAngleX + angleOffsetX);
		//angleY = (oriAngleY + angleOffsetY);
		//printf("Angle offset: %d(%d)\n", angleOffsetX, angleX);
		glutPostRedisplay();
	}
		
	void mouseFunc(int button, int state, int x, int y)
	{
		printf("Mouse press: %d, %d at (%d, %d)\n", button, state, x, y);

		if (GLUT_LEFT_BUTTON == button && GLUT_DOWN == state)
		{
			lastMX = x;
			lastMY = y;
		}
	}

	int MainRun(int argc, char** argv)
	{
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

		glutInitWindowPosition(700, 200);
		glutInitWindowSize(500, 500);


		glutCreateWindow("PatchLion's first OpenGL windows!");

		cout << glGetString(GL_VERSION) << endl;
		cout << glGetString(GL_RENDERER) << endl;

		glShadeModel(GL_FLAT);
		glClearColor(0.0, 0.0, 0.0, 0.0);

		if (glewInit())
		{
			cerr << "Unable to initialize GLEW ... exiting" << endl;
			exit(1);
		}
		/*glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK); //剔除背面*/
		//启用数组
		
		GLint maxV = 0, maxI = 0;
		glGetIntegerv(GL_MAX_ELEMENTS_VERTICES, &maxV);
		glGetIntegerv(GL_MAX_ELEMENTS_INDICES, &maxI);

		printf("Max Vertices Count: %d           Max Indices Count: %d\n", maxV, maxI);

		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);


		glVertexPointer(3, GL_INT, 0, vertices3i);
		glColorPointer(3, GL_FLOAT, 0, colors);


/*

		glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), &interwined[0]);
		glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), &interwined[3]); */
		
		glutMotionFunc(&mousePressedMoveFunc);
		glutKeyboardFunc(&keyboardFunc);
		glutMouseFunc(&mouseFunc);
		glutReshapeFunc(&reshapeFunc);
		glutIdleFunc(&idleFunc);
		glutDisplayFunc(&showFunction);		//必须在初始化成功后设置

		glutMainLoop();

		return 0;
	}
}

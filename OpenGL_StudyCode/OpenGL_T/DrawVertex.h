/*
#include "LoadShaders.h"
#include "triangles.h"*/

#include <gl/glew.h>
#include <gl/freeglut.h>
#include <iostream>

#pragma comment (lib, "glew32.lib")
using namespace std;

#define PI 3.1415926535898

//使用0~9按键 切换绘制类型
namespace DrawVertex
{
	GLenum vertexType(int id)
	{
		switch (id)
		{
		case 0: return GL_POINTS;
		case 1: return GL_LINES;
		case 2: return GL_LINE_STRIP;
		case 3: return GL_LINE_LOOP;
		case 4: return GL_TRIANGLES;
		case 5: return GL_TRIANGLE_STRIP;
		case 6: return GL_TRIANGLE_FAN;
		case 7: return GL_QUADS;
		case 8: return GL_QUAD_STRIP;
		case 9: return GL_POLYGON;
		default: return GL_POINTS;
		}
	}

	int type = 0;
	void showFunction(void)
	{
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(vertexType(type));

		/*glVertex2f(-0.8, 0.4);
		glVertex2f(-0.8, -0.4);
		glVertex2f(-0.7, 0.5);
		glVertex2f(0, -0.5);
		glVertex2f(-0.6, 0.1);
		glVertex2f(0.8, 0.4);
		glVertex2f(0.9, 0.5);
*/

		int circle_points = 255;
		for (int i = 0; i < circle_points; i++)
		{
			double angle = 2 * PI*i / circle_points;
			double c = (double)i / 255.0;
			glColor3f(c, c, c);
			glVertex2f(cos(angle), sin(angle));
		}

		glEnd();
		glutSwapBuffers();
	}

	void idleFunc(void)
	{
		//printf("idle function!\n");
	}

	void reshapeFunc(int w, int h)
	{
		printf("Reshape: %d, %d\n", w, h);
		glViewport(0, 0, (GLsizei)w, (GLsizei)h);	//设置视口大小
		glLoadIdentity(); //将之前矩阵变换导致变化过的栈顶矩阵重新归位
		glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);	//平行修剪空间。这种投影意味着离观察者较远的对象看上去不会变小（与透视投影相反）
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}

	void keyboardFunc(unsigned char key, int x, int y)
	{
		printf("Press key: %d\n", key);

		if (key >= 48 && key <= 57)
		{
			type = key - 48;
		}
		else
		{
			type = -1;
		}

		glutPostRedisplay();
	}
	void mouseFunc(int button, int state, int x, int y)
	{
		printf("Mouse press: %d, %d at (%d, %d)\n", button, state, x, y);
	}
	int MainRun(int argc, char** argv)
	{
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

		glutInitWindowPosition(700, 200);
		glutInitWindowSize(300, 300);


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

		glutKeyboardFunc(&keyboardFunc);
		glutMouseFunc(&mouseFunc);
		glutReshapeFunc(&reshapeFunc);
		glutIdleFunc(&idleFunc);
		glutDisplayFunc(&showFunction);		//必须在初始化成功后设置

		glutMainLoop();

		return 0;
	}
}

// textures.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
//=============================================================
// ����ͷ�ļ�
//=============================================================
#include <fstream>
#include <iostream>

#include "math.h"
//=============================================================
// ����lib
//=============================================================
#pragma comment(lib, "glew32.lib")
using namespace std;
#define tx 0.525731112119133606
#define tz 0.850650808352039932
GLfloat vdata[12][3] = {
	{ -tx, 0.0, tz }, { tx, 0.0, tz }, { -tx, 0.0, -tz }, { tx, 0.0, -tz },
	{ 0.0, tz, tx }, { 0.0, tz, -tx }, { 0.0, -tz, tx }, { 0.0, -tz, -tx },
	{ tz, tx, 0.0 }, { -tz, tx, 0.0 }, { tz, -tx, 0.0 }, { -tz, -tx, 0.0 }
};
GLuint tindices[20][3] = {
	{ 1, 4, 0 }, { 4, 9, 0 }, { 4, 5, 9 }, { 8, 5, 4 }, { 1, 8, 4 },
	{ 1, 10, 8 }, { 10, 3, 8 }, { 8, 3, 5 }, { 3, 2, 5 }, { 3, 7, 2 },
	{ 3, 10, 7 }, { 10, 6, 7 }, { 6, 11, 7 }, { 6, 0, 11 }, { 6, 1, 0 },
	{ 10, 1, 6 }, { 11, 0, 9 }, { 2, 11, 9 }, { 5, 2, 9 }, { 11, 2, 7 }
};
//=============================================================
// ��������
//=============================================================
void Initialize();        // ��ʼ��Ӧ�ó���
void Uninitialize();    // ����Ӧ�ó���
void DrawFunc();                                    // glut���ص�����
void ReshapeFunc(int width, int height);            // glut�������ûص�����
void KeyboardFunc(unsigned char key, int x, int y);    // glut���̻ص�����
void MouseFunc(int button, int state, int x, int y);// glut��갴�����ͷŻص�����
void MotionFunc(int x, int y);                        // glut����ƶ��ص�����
void IdleFunc();                                    // glut���д���ص����� 
void DrawText(const char* text, float x, float y);    // ����Ļ����ʾ�ı�
//=============================================================
// ȫ�ֱ���
//=============================================================
const static float EPSILON = 0.000001f;
const static float PI = 3.1415926f;
const static float PI_2 = 6.2831852f;
// �������
const static int g_WindowPosX = 240;
const static int g_WindowPosY = 200;
int g_WindowWidth = 512;
int g_WindowHeight = 384;
const char* g_WindowTitle = "OpenGL ƮƮ����(www.cnblogs.com/kesalin)";
// ��ʾģʽ:˫���壬RGBA����Ȼ���
const static int g_DisplayMode = (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);    // GLUT_STENCIL GLUT_ACCUM
static float g_fov = 15.0f;
float g_rotateY = 0.0f;        // ��Y����ת����
float g_posX = 0.0f;
int runWithMain(int argc, char* argv[])
{
	// ��ʼ��opengl, glut, glew
	glutInit(&argc, argv);
	glutInitDisplayMode(g_DisplayMode);
	glewInit();
	// ����window
	glutInitWindowPosition(g_WindowPosX, g_WindowPosY);
	glutInitWindowSize(g_WindowWidth, g_WindowHeight);
	glutCreateWindow(g_WindowTitle);
	//glutFullScreen();
	// ��ʼ��Ӧ�ó���
	Initialize();
	// �趨glut�ص�����
	glutDisplayFunc(DrawFunc);
	glutReshapeFunc(ReshapeFunc);
	glutKeyboardFunc(KeyboardFunc);
	glutIdleFunc(IdleFunc);
	// ����glut�¼�����ѭ��
	glutMainLoop();
	// ����Ӧ�ó���
	Uninitialize();
	return 0;
}
void printbuffer()
{
	int imgbuf[500][380];
	glReadPixels(0, 0, 500, 380, GL_RED, GL_INT, imgbuf);
	ofstream otf("A.txt");
	for (int i = 0; i<500; i++)
	{
		for (int j = 0; j<380; j++)
		{
			otf << imgbuf[i][j];
		}
	}
	otf.close();
}
//=============================================================
// ��������
//=============================================================
// ����Ļ����ʾ�ı���x �� y Ϊ��Ļ����
void DrawText(const char* text, float x, float y)
{
	// ���OpenGL״̬
	bool isDepthOpen = false;
	bool isStencilOpen = false;
	bool isLightOpen = false;
	bool isFogOpen = false;
	if (glIsEnabled(GL_DEPTH_TEST))
	{
		isDepthOpen = true;
		glDisable(GL_DEPTH_TEST);
	}
	if (glIsEnabled(GL_STENCIL_TEST))
	{
		isStencilOpen = true;
		glDisable(GL_STENCIL_TEST);
	}
	if (glIsEnabled(GL_LIGHTING))
	{
		isLightOpen = true;
		glDisable(GL_LIGHTING);
	}
	if (glIsEnabled(GL_FOG))
	{
		isFogOpen = true;
		glDisable(GL_FOG);
	}
	int font = (int)GLUT_BITMAP_8_BY_13;
	// ����������ɫ
	glColor3f(1.0, 1.0, 0.0);
	/*
	* ������ͶӰ
	*/
	glMatrixMode(GL_PROJECTION);
	// ���浱ǰͶӰ����
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, g_WindowWidth, 0, g_WindowHeight);
	// ��תY�ᣨ����Ϊ������(�봰������һ��)
	glScalef(1, -1, 1);
	// ��ԭ���ƶ�����Ļ���Ϸ�(�봰������һ��)
	glTranslatef(0, -g_WindowHeight, 0);
	glMatrixMode(GL_MODELVIEW);
	// ���浱ǰģ����ͼ����
	glPushMatrix();
	glLoadIdentity();
	// ��������λ��
	glRasterPos2f(x, y);
	// ������������ַ�(ʹ����ʾ�б�)
	for (const char* c = text; *c != '/0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
	}
	// �ָ�֮ǰ�����ģ����ͼ����
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	// �ָ�֮ǰ�����ͶӰ����
	glPopMatrix();
	// ����ģ����ͼ����״̬
	glMatrixMode(GL_MODELVIEW);
	// �ָ�OpenGL״̬
	if (isDepthOpen)
	{
		glEnable(GL_DEPTH_TEST);
	}
	if (isStencilOpen)
	{
		glEnable(GL_STENCIL_TEST);
	}
	if (isLightOpen)
	{
		glEnable(GL_LIGHTING);
	}
	if (isFogOpen)
	{
		glEnable(GL_FOG);
	}
}
// ��ʼ��Ӧ�ó���
void Initialize()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	GLfloat mat_specular[] = { 0.0, 0.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	GLfloat light_position[] = { 9.0, 1.0, 20.0, 0.0 };
	GLfloat white_light[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat lmodel_ambient[] = { 0.1, 0.1, 0.1, 1.0 };
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	// �����ӿڣ�ͶӰ��Ϣ
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(g_fov, (GLfloat)g_WindowWidth / g_WindowHeight, 1.0, 30.0);
}
// ����Ӧ�ó���
void Uninitialize()
{
	// nothing
}
// ���д���
void IdleFunc()
{
	//g_rotateY += 0.2f;
	// �����ػ�
	glutPostRedisplay();
}
// ��溯��
float ya = 0.0f;
void wujiao()
{
	GLfloat r = 2.0f;//�������ΰ뾶
	GLfloat r2 = 0.75f;//�ڲ�����ΰ뾶
	GLfloat s[15];
	s[0] = r*sin(2 * 72 * PI / 180);
	s[1] = r*cos(2 * 72 * PI / 180);
	s[2] = 0.0f;
	s[3] = r*sin(4 * 72 * PI / 180);
	s[4] = r*cos(4 * 72 * PI / 180);
	s[5] = 0.0f;
	s[6] = r2*sin(36 * PI / 180);
	s[7] = r2*cos(36 * PI / 180);
	s[8] = 0.0f;
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, s);
	int s1[] = { 0, 1, 2 };
	glDrawElements(GL_POLYGON, 3, GL_UNSIGNED_INT, s1);
}
void normalize(float v[3]){
	GLfloat d = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
	if (d == 0.0){
		return;
	}
	v[0] /= d;
	v[1] /= d;
	v[2] /= d;
}
void normcrosspord(float v1[3], float v2[3], float out[3]){
	out[0] = v1[1] * v2[2] - v1[2] * v2[1];
	out[1] = v1[2] * v2[0] - v1[0] * v2[2];
	out[2] = v1[0] * v2[1] - v1[1] * v2[0];
	normalize(out);
}
void drawtriangle(float *v1, float *v2, float *v3){
	glBegin(GL_TRIANGLES);
	glNormal3fv(v1);
	glVertex3fv(v1);
	glNormal3fv(v2);
	glVertex3fv(v2);
	glNormal3fv(v3);
	glVertex3fv(v3);
	glEnd();
}
void subdivide(float *v1, float *v2, float *v3, long depth){
	GLfloat v12[3], v23[3], v31[3];
	if (depth == 0){
		drawtriangle(v1, v2, v3);
		return;
	}
	for (int i = 0; i<3; i++){
		v12[i] = (v1[i] + v2[i]) / 2.0;
		v23[i] = (v2[i] + v3[i]) / 2.0;
		v31[i] = (v3[i] + v1[i]) / 2.0;
	}
	normalize(v12);
	normalize(v23);
	normalize(v31);
	subdivide(v1, v12, v31, depth - 1);
	subdivide(v2, v23, v12, depth - 1);
	subdivide(v3, v31, v23, depth - 1);
	subdivide(v12, v23, v31, depth - 1);
}
void DrawFunc()
{
	// ����
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (int i = 0; i<20; i++){
		subdivide(&vdata[tindices[i][0]][0], &vdata[tindices[i][1]][0], &vdata[tindices[i][2]][0], 3);
	}
	glutSwapBuffers();
}
// ��Ӧ���������¼�
void ReshapeFunc(int width, int height)
{
	g_WindowWidth = width;
	g_WindowHeight = height;
	glViewport(0, 0, g_WindowWidth, g_WindowHeight);
	//
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(g_fov, (GLfloat)g_WindowWidth / g_WindowHeight, 1.0, 30.0);//--------
	gluLookAt(0.0f, 0.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);//--------
	//
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
// ��Ӧ�����¼�
void KeyboardFunc(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'A':
	case 'a':
		// �����ƶ�
		g_posX -= 0.05f;
		if (g_posX < -4.0f)
		{
			g_posX = -4.0f;
		}
		break;
	case 'D':
	case 'd':
		// �����ƶ�
		g_posX += 0.05f;
		if (g_posX > 4.0f)
		{
			g_posX = 4.0f;
		}
		break;
	case 27:
		exit(0);
		break;
	case '+':
	case '=':
		g_fov -= 5;
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(g_fov, (GLfloat)g_WindowWidth / g_WindowHeight, 1.0, 30.0);//--------
		gluLookAt(0.0f, 0.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);//--------
		break;
	case '-':
	case '_':
		g_fov += 5;
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(g_fov, (GLfloat)g_WindowWidth / g_WindowHeight, 1.0, 30.0);//--------
		gluLookAt(0.0f, 0.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);//--------
		break;
	case 'p':
	case 'P':
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		GLfloat p[16];
		glGetFloatv(GL_PROJECTION_MATRIX, p);
		for (int i = 0; i<16; i++)
			printf("%f  ", p[i]);
		glPopMatrix();
		break;
	case ',':
	case '<':
		ya += 5;
		break;
	case '.':
	case '>':
		ya -= 5;
		break;
	case 'z':
	case 'Z':
		printbuffer();
		break;
	default:
		break;
	}
}
// ��Ӧ��갴�����ͷ��¼�
void MouseFunc(int button, int state, int x, int y)
{
#if 0
	switch (button)
	{
	case GLUT_WHEEL_UP://�ϰ汾��glut�ⲻ֧������м���Ϣ����Ӧ,����Ҫ��glut.lib,glut.h,glut.dll�����ļ����µ��°汾.
		break;
	case GLUT_WHEEL_DOWN://�ϰ汾��glut�ⲻ֧������м���Ϣ����Ӧ,����Ҫ��glut.lib,glut.h,glut.dll�����ļ����µ��°汾.
		break;
	case GLUT_LEFT_BUTTON:
	{
		if (state == GLUT_UP)
		{
		}
		else if (state == GLUT_DOWN)
		{
		}
	}
	break;
	case GLUT_RIGHT_BUTTON:
	{
		if (state == GLUT_UP)
		{
		}
		else if (state == GLUT_DOWN)
		{
		}
	}
	break;
	case GLUT_MIDDLE_BUTTON:
	{
		if (state == GLUT_UP)
		{
		}
		else if (state == GLUT_DOWN)
		{
		}
	}
	break;
	}
#endif
}
// ��Ӧ����ƶ��¼�
void MotionFunc(int x, int y)
{
	// nothing
}

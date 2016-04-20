// textures.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
//=============================================================
// 包含头文件
//=============================================================
#include <fstream>
#include <iostream>

#include "math.h"
//=============================================================
// 导入lib
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
// 函数声明
//=============================================================
void Initialize();        // 初始化应用程序
void Uninitialize();    // 清理应用程序
void DrawFunc();                                    // glut描绘回调函数
void ReshapeFunc(int width, int height);            // glut窗口重置回调函数
void KeyboardFunc(unsigned char key, int x, int y);    // glut键盘回调函数
void MouseFunc(int button, int state, int x, int y);// glut鼠标按下与释放回调函数
void MotionFunc(int x, int y);                        // glut鼠标移动回调函数
void IdleFunc();                                    // glut空闲处理回调函数 
void DrawText(const char* text, float x, float y);    // 在屏幕上显示文本
//=============================================================
// 全局变量
//=============================================================
const static float EPSILON = 0.000001f;
const static float PI = 3.1415926f;
const static float PI_2 = 6.2831852f;
// 窗口相关
const static int g_WindowPosX = 240;
const static int g_WindowPosY = 200;
int g_WindowWidth = 512;
int g_WindowHeight = 384;
const char* g_WindowTitle = "OpenGL 飘飘白云(www.cnblogs.com/kesalin)";
// 显示模式:双缓冲，RGBA，深度缓存
const static int g_DisplayMode = (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);    // GLUT_STENCIL GLUT_ACCUM
static float g_fov = 15.0f;
float g_rotateY = 0.0f;        // 绕Y轴旋转变量
float g_posX = 0.0f;
int runWithMain(int argc, char* argv[])
{
	// 初始化opengl, glut, glew
	glutInit(&argc, argv);
	glutInitDisplayMode(g_DisplayMode);
	glewInit();
	// 创建window
	glutInitWindowPosition(g_WindowPosX, g_WindowPosY);
	glutInitWindowSize(g_WindowWidth, g_WindowHeight);
	glutCreateWindow(g_WindowTitle);
	//glutFullScreen();
	// 初始化应用程序
	Initialize();
	// 设定glut回调函数
	glutDisplayFunc(DrawFunc);
	glutReshapeFunc(ReshapeFunc);
	glutKeyboardFunc(KeyboardFunc);
	glutIdleFunc(IdleFunc);
	// 进入glut事件处理循环
	glutMainLoop();
	// 清理应用程序
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
// 函数定义
//=============================================================
// 在屏幕上显示文本，x 和 y 为屏幕坐标
void DrawText(const char* text, float x, float y)
{
	// 检查OpenGL状态
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
	// 设置字体颜色
	glColor3f(1.0, 1.0, 0.0);
	/*
	* 设置正投影
	*/
	glMatrixMode(GL_PROJECTION);
	// 保存当前投影矩阵
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, g_WindowWidth, 0, g_WindowHeight);
	// 反转Y轴（朝下为正方向）(与窗口坐标一致)
	glScalef(1, -1, 1);
	// 将原点移动到屏幕左上方(与窗口坐标一致)
	glTranslatef(0, -g_WindowHeight, 0);
	glMatrixMode(GL_MODELVIEW);
	// 保存当前模型视图矩阵
	glPushMatrix();
	glLoadIdentity();
	// 设置文字位置
	glRasterPos2f(x, y);
	// 依次描绘所有字符(使用显示列表)
	for (const char* c = text; *c != '/0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
	}
	// 恢复之前保存的模型视图矩阵
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	// 恢复之前保存的投影矩阵
	glPopMatrix();
	// 返回模型视图矩阵状态
	glMatrixMode(GL_MODELVIEW);
	// 恢复OpenGL状态
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
// 初始化应用程序
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
	// 设置视口，投影信息
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(g_fov, (GLfloat)g_WindowWidth / g_WindowHeight, 1.0, 30.0);
}
// 清理应用程序
void Uninitialize()
{
	// nothing
}
// 空闲处理
void IdleFunc()
{
	//g_rotateY += 0.2f;
	// 请求重绘
	glutPostRedisplay();
}
// 描绘函数
float ya = 0.0f;
void wujiao()
{
	GLfloat r = 2.0f;//外侧五边形半径
	GLfloat r2 = 0.75f;//内侧五边形半径
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
	// 清屏
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (int i = 0; i<20; i++){
		subdivide(&vdata[tindices[i][0]][0], &vdata[tindices[i][1]][0], &vdata[tindices[i][2]][0], 3);
	}
	glutSwapBuffers();
}
// 响应窗口重置事件
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
// 响应按键事件
void KeyboardFunc(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'A':
	case 'a':
		// 向左移动
		g_posX -= 0.05f;
		if (g_posX < -4.0f)
		{
			g_posX = -4.0f;
		}
		break;
	case 'D':
	case 'd':
		// 向右移动
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
// 响应鼠标按下与释放事件
void MouseFunc(int button, int state, int x, int y)
{
#if 0
	switch (button)
	{
	case GLUT_WHEEL_UP://老版本的glut库不支持鼠标中键消息的响应,所以要将glut.lib,glut.h,glut.dll三个文件更新到新版本.
		break;
	case GLUT_WHEEL_DOWN://老版本的glut库不支持鼠标中键消息的响应,所以要将glut.lib,glut.h,glut.dll三个文件更新到新版本.
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
// 响应鼠标移动事件
void MotionFunc(int x, int y)
{
	// nothing
}

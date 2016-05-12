#ifndef PixelOper_SingleBuffer_h__
#define PixelOper_SingleBuffer_h__

#include "stdafx.h"

#define checkImageWidth	 64
#define checkImageHeight	6

namespace  PixelOper_SingleBuffer
{
	GLubyte checkImage[checkImageWidth][checkImageHeight][3];
	static GLdouble zoomFactor = 1.0;
	static GLint height;

	void makeCheckImage(void)
	{
		int i, j, c;
		for (i = 0; i < checkImageHeight; i++) {
			for (j = 0; j < checkImageWidth; j++) {
				c = ((((i & 0x8) == 0) ^ (((j & 0x8)) == 0))) * 255;
				checkImage[i][j][0] = (GLubyte)c;
				checkImage[i][j][1] = (GLubyte)c;
				checkImage[i][j][2] = (GLubyte)c;
			}
		}
	}
	void init(void)
	{
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glShadeModel(GL_FLAT);
		makeCheckImage();
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	}
	void display(void)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glRasterPos2i(0, 0);
		glDrawPixels(checkImageWidth, checkImageHeight, GL_RGB, GL_UNSIGNED_BYTE, checkImage);
		glFlush();
	}
	void reshape(int w, int h)
	{
		glViewport(0, 0, (GLsizei)w, (GLsizei)h);
		height = h;
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}
	void motion(int x, int y)
	{
		static GLint screeny;
		screeny = height - (GLint)y;
		glRasterPos2i(x, screeny);
		glPixelZoom(zoomFactor, zoomFactor);
		glCopyPixels(0, 0, checkImageWidth, checkImageHeight, GL_COLOR);
		glPixelZoom(1.0, 1.0);
		glFlush();
	}
	void keyboard(unsigned char key, int x, int y)
	{
		switch (key) {
		case'r':
		case'R':
			zoomFactor = 1.0;
			glutPostRedisplay();
			break;
		case'z':
			zoomFactor += 0.5;
			if (zoomFactor >= 3.0) {
				zoomFactor = 3.0;
			}
			break;
		case'Z':
			zoomFactor -= 0.5;
			if (zoomFactor <= 0.5) {
				zoomFactor = 0.5;
			}
			break;
		case27:
			exit(0);
			break;
		default:
			break;
		}
	}
	int runMain(int argc, char** argv)
	{
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
		glutInitWindowSize(250, 250);
		glutInitWindowPosition(100, 100);
		glutCreateWindow(argv[0]);
		init();


		glutDisplayFunc(PixelOper_SingleBuffer::display);
		glutReshapeFunc(PixelOper_SingleBuffer::reshape);
		glutKeyboardFunc(PixelOper_SingleBuffer::keyboard);
		glutMotionFunc(PixelOper_SingleBuffer::motion);

	
		glutMainLoop();
		return 0;
	}
}
#endif // PixelOper_SingleBuffer_h__

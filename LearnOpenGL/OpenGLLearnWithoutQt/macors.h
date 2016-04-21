#ifndef macors_h__
#define macors_h__

#ifndef GL_PI
#define GL_PI 3.1415926
#endif
#ifndef GL_RADIUX
#define GL_RADIUX  0.2f
#endif

#define drawLine3fWithColor(x1, y1, z1, x2, y2, z2, r, g, b) 		glBegin(GL_LINES);\
glColor3f(r, g, b);\
glVertex3f(x1, y1, z1);\
glVertex3f(x2, y2, z2);\
glEnd();

#define drawOneLine2f(x1, y1, x2, y2) 		glBegin(GL_LINES);\
glVertex2f(x1, y1);\
glVertex2f(x2, y2);\
glEnd();

#define drawOneLine2fWithColor(x1, y1, x2, y2, r, g, b) 		glBegin(GL_LINES);\
glColor3f(r, g, b);\
glVertex2f(x1, y1);\
glVertex2f(x2, y2);\
glEnd();

#ifndef BUFFER_OFFSET
#define BUFFER_OFFSET(offset) ((GLvoid*)(offset))
#endif

#endif // macors_h__

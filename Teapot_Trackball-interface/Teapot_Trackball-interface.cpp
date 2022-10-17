#include<gl/glut.h>
#define _USE_MATH_DEFINES
#include<math.h>

#define WIDTH 600
#define HIGHT 500

GLdouble angle = 0.0, angle1 = 0.0;
GLdouble Multi = 0.005;
int check = 0;

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glRotated(angle, 0.0, 1.0, 0.0);
	glRotated(angle1, 1.0, 0.0, 0.0);
	glutWireTeapot(0.5);
	glutSwapBuffers();
	glFlush();
}

void Resh(int w, int h)
{
	glViewport(0, 0, w, h);
	GLfloat width = (GLfloat)w / (GLfloat)WIDTH;
	GLfloat hight = (GLfloat)h / (GLfloat)HIGHT;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0 * width, 1.0 * width, -1.0 * hight, 1.0 * hight, -1.0, 1.0);
}
void id()
{
	glutPostRedisplay();
}

void Mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		check = 1;
	}
	else
	{
		check = 0;
	}
}

void DragMouse(int x, int y)
{
	if (check == 1)
	{
		angle += atan2f((GLdouble)x, (GLdouble)y) * 180 / M_PI * Multi;
		angle1 += atan2f((GLdouble)y, (GLdouble)x) * 180 / M_PI * Multi;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(WIDTH, HIGHT);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("TeaPot");
	glClearColor(0.4, 0.4, 0.4, 0.0);
	glutDisplayFunc(Display);
	glutReshapeFunc(Resh);
	glutMouseFunc(Mouse);
	glutMotionFunc(DragMouse);
	glutIdleFunc(id);
	glutMainLoop();
}
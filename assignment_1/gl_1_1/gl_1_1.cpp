#include<GL/glut.h>

void Display() {

	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(-0.5, 0.5, 0.0);
	glEnd();
	glFlush();
}


int main(int argc, char* argv[])
{
// freeglut  ERROR:  Function <glutCreateWindow> called without first calling 'glutInit'.

	glutInit(&argc, argv);
	glutCreateWindow("Hello World!");
	glutDisplayFunc(Display);
	glutMainLoop();
	return 0;
}

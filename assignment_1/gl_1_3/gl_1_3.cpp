#include <GL/glut.h> 

GLvoid drawScene(GLvoid);

void main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	//�ʱ�ȭ �Լ���
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); // ���÷��� ��� ����
	glutInitWindowPosition(100, 100); // �������� ��ġ����
	glutInitWindowSize(500, 500); // �������� ũ�� ����
	glutCreateWindow("rheefine"); // ������ ���� (������ �̸�)
	glutDisplayFunc(drawScene); // ��� �Լ��� ����
	glutMainLoop();
}

GLvoid drawScene(GLvoid)
{
	glClearColor(1, 1, 0, 1); // �������� 'blue' �� ����
	glClear(GL_COLOR_BUFFER_BIT); // ������ ������ ��ü�� ĥ�ϱ�
	glColor4f(1, 0, 0, 1); // �׸��� ���� 'red' ���� ����
	glRectf(-0.5f, -0.5f, 0.5f, 0.5f); // �簢�� �׸���
	glFlush(); // ȭ�鿡 ����ϱ�
}

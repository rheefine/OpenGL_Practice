#include <GL/glut.h>

GLvoid drawScene(GLvoid)
{
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // �������� 'blue' �� ����
	glClear( GL_COLOR_BUFFER_BIT ); // ������ ������ ��ü�� ĥ�ϱ�
	glFlush(); // ȭ�鿡 ����ϱ�
}

void main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	// �ʱ�ȭ �Լ���
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); // ���÷��� ��� ����
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500); // �������� ũ�� ����
	glutCreateWindow("rheefine"); // ������ ���� (������ �̸�)
	glutDisplayFunc(drawScene); // ��� �Լ��� ����
	glutMainLoop();
}

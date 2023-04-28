#include <GL/glut.h>

GLvoid drawScene(GLvoid)
{
	glClearColor(1, 1, 1, 1); // �������� 'white' �� ����
	glClear(GL_COLOR_BUFFER_BIT); // ������ ������ ��ü�� ĥ�ϱ�
	glColor4f(0, 0, 0, 1); // �׸��� ���� 'black' ���� ����
	glRotatef(90, 1, 1, 1); // ��������
	// ����
	glutWireSphere(1, 100, 100);
	// ������
	glutWireTeapot(0.5);
	glFlush(); // ȭ�鿡 ����ϱ�
}

void main(int argc, char** argv)
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

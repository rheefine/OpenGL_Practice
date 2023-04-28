#include <GL/glut.h>

GLvoid drawScene(GLvoid)
{
	glClearColor(1, 1, 1, 1); // 바탕색을 'white' 로 지정
	glClear(GL_COLOR_BUFFER_BIT); // 설정된 색으로 전체를 칠하기
	glColor4f(0, 0, 0, 1); // 그리기 색을 'black' 으로 지정
	glRotatef(90, 1, 1, 1); // 시점변경
	// 원구
	glutWireSphere(1, 100, 100);
	// 주전자
	glutWireTeapot(0.5);
	glFlush(); // 화면에 출력하기
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	//초기화 함수들
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); // 디스플레이 모드 설정
	glutInitWindowPosition(100, 100); // 윈도우의 위치지정
	glutInitWindowSize(500, 500); // 윈도우의 크기 지정
	glutCreateWindow("rheefine"); // 윈도우 생성 (윈도우 이름)
	glutDisplayFunc(drawScene); // 출력 함수의 지정
	glutMainLoop();
}

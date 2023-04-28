#include <GL/glut.h>
#include <cstring>
using namespace std;

GLfloat point[10][2];
GLfloat matrix_2[3][3] = { {2.0f, -4.0f, 2.0f}, {-3.0f, 4.0f, -1.0f}, {1.0f, 0.0f, 0.0f} };
GLfloat matrix_3[4][4] = { {-1.0f, 3.0f, -3.0f, 1.0f},
                          {2.0f, -5.0f, 4.0f, -1.0f},
                          {-1.0f, 0.0f, 1.0f, 0.0f},
                          {0.0f, 2.0f, 0.0f, 0.0f} };

void reshape(GLint w, GLint h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0, 10.0, -10.0, 10.0, -1.0, 30.0);
}

// 점 찍기
GLvoid drawPoints() {
    glPointSize(7.0f);

    glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
    glBegin(GL_POINTS);

    for (int i = 0; i < 10; i++)
    {
        point[i][0] = i * 2.0f - 9.0f;
    }

    point[0][1] = 9.0f;
    point[1][1] = 9.0f;
    point[2][1] = 6.0f;
    point[3][1] = 8.0f;
    point[4][1] = 4.0f;
    point[5][1] = -9.0f;
    point[6][1] = 7.0f;
    point[7][1] = 6.0f;
    point[8][1] = 9.0f;
    point[9][1] = -4.0f;

    
    for (int i = 0; i < 10; i++)
        glVertex2f(point[i][0], point[i][1]);
    glEnd();
}

// cubic spline
GLvoid drawCardinal() {
    // init & variable
    glColor4f(0.0f, 0.0f, 0.0f, 0.0f);
    GLfloat result[4][2];
    GLfloat t = 0.0f;
    GLfloat x, y;

    // Section 1.
    // quadratic function
    memset(result, 0, sizeof(result));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result[i][0] += matrix_2[i][j] * point[j][0];
            result[i][1] += matrix_2[i][j] * point[j][1];
        }
    }

    glBegin(GL_LINE_STRIP);
    while (t < 0.5f) {
        x = result[2][0] + t * (result[1][0] + result[0][0] * t);
        y = result[2][1] + t * (result[1][1] + result[0][1] * t);
        glVertex2f(x, y);
        t += 0.01f;
    }
    glEnd();

    // Section 2.
    // cubic spline
    for (int cubic_case = 0; cubic_case < 10 - 3; cubic_case++)
    {
        memset(result, 0, sizeof(result));
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                result[i][0] += matrix_3[i][j] * point[j + cubic_case][0];
                result[i][1] += matrix_3[i][j] * point[j + cubic_case][1];
            }
        }

        t = 0.0f;
        glBegin(GL_LINE_STRIP);
        while (t < 1.0f) {
            x = (result[3][0] + t * (result[2][0] + t * (result[1][0] + result[0][0] * t))) * 0.5f;
            y = (result[3][1] + t * (result[2][1] + t * (result[1][1] + result[0][1] * t))) * 0.5f;
            glVertex2f(x, y);
            t += 0.01f;
        }
        glEnd();
    }

    // Section 3.
    // quadratic function
    memset(result, 0, sizeof(result));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result[i][0] += matrix_2[i][j] * point[j + 10 - 3][0];
            result[i][1] += matrix_2[i][j] * point[j + 10 - 3][1];
        }
    }

    t = 0.5f;
    glBegin(GL_LINE_STRIP);
    while (t < 1.0f) {
        x = result[2][0] + t * (result[1][0] + result[0][0] * t);
        y = result[2][1] + t * (result[1][1] + result[0][1] * t);
        glVertex2f(x, y);
        t += 0.01f;
    }
    glEnd();
}


GLvoid display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //점 찍기
    drawPoints();

    // 점을 기준으로 곡선 그리기
    drawCardinal();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("cubic spline");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMainLoop();
    return (0);
}

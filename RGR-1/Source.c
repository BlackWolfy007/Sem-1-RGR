#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <glut.h>

#define part1
#ifdef part1
//===================================================================
//  ��������-����������� ������ �� �����������
//  ������� #2
//  ������ ��-021 ������ �.�.
//===================================================================

// ----------------------------------------------------------
// ���������� �������
// ----------------------------------------------------------
void display();
void specialKeys(int key, int x, int y);

// ----------------------------------------------------------
// ���������� ����������
// ----------------------------------------------------------
double rotate_y = 0;
double rotate_x = 0;

// ----------------------------------------------------------
// ����� �������
// ----------------------------------------------------------
void display() {

    //  ������� ����� ����
    glClearColor(0.13, 0, 0.38, 1);

    //  ������� ������ � ������
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //  ������� �������
    glLoadIdentity();
    
    //  ��������� ��������� � ������������ 
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);

    //  ����� ����
    glBegin(GL_POLYGON);
    glColor3f(0.25, 0.25, 0.25);
    glVertex3f(0.25, 0, -0.25);       
    glVertex3f(0, 0.5, 0);      
    glVertex3f(-0.25, 0, -0.25);      
    glEnd();

    //  ������ ����� ����
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.5, 0);
    glVertex3f(0.25, 0, 0.25);
    glVertex3f(0, 0.5, 0);
    glVertex3f(-0.25, 0, 0.25);
    glEnd();

    //  ������ ������� ����
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(0.25, 0, -0.25);
    glVertex3f(0, 0.5, 0);
    glVertex3f(0.25, 0, 0.25);
    glEnd();

    //  ����� ������� ����
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.65, 1);
    glVertex3f(-0.25, 0, 0.25);
    glVertex3f(0, 0.5, 0);
    glVertex3f(-0.25, 0, -0.25);
    glEnd();

    //  ����� ���
    glBegin(GL_POLYGON);
    glColor3f(0.65, 1, 0);
    glVertex3f(0.25, 0, -0.25);
    glVertex3f(0, -0.5, 0);
    glVertex3f(-0.25, 0, -0.25);
    glEnd();

    //  ������ ����� ���
    glBegin(GL_POLYGON);
    glColor3f(0.55, 0, 1.0);
    glVertex3f(0.25, 0, 0.25);
    glVertex3f(0, -0.5, 0);
    glVertex3f(-0.25, 0, 0.25);
    glEnd();

    //  ������ ������� ���
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.68);
    glVertex3f(0.25, 0, -0.25);
    glVertex3f(0, -0.5, 0);
    glVertex3f(0.25, 0, 0.25);
    glEnd();

    //  ����� ������� ���
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.82);
    glVertex3f(-0.25, 0, 0.25);
    glVertex3f(0, -0.5, 0);
    glVertex3f(-0.25, 0, -0.25);
    glEnd();

    //  ������� �������
    glFlush();
    glutSwapBuffers();

}

// ----------------------------------------------------------
//  ����� ������� ��� ������ � �����������
// ----------------------------------------------------------
void specialKeys(int key, int x, int y) {
    
    switch (key) {
    //  ������� "Right" - ��������� �� 1 �������� ������
    case GLUT_KEY_RIGHT:
        rotate_y += 1;
        break;
    //  ������� "Left" - ��������� �� 1 �������� �����
    case GLUT_KEY_LEFT:
        rotate_y -= 1;
        break;
    //  ������� "Up" - ��������� �� 1 �������� �����
    case GLUT_KEY_UP:
        rotate_x += 1;
        break;
    //  ������� "Down" - ��������� �� 1 �������� ����
    case GLUT_KEY_DOWN:
        rotate_x -= 1;
        break;
    }

    //  ���������� ��������� ����
    glutPostRedisplay();

}


// ----------------------------------------------------------
//  ����� ������� ��� ������ � �����
// ----------------------------------------------------------
void mouse(int button, int state, int x, int y)
{

    switch (button) {
    //  ����� ������ ���� - ������� �� ��������� ����� ����� �� 5 ��������
    case GLUT_LEFT_BUTTON:
        rotate_x -= 5;
        rotate_y -= 5;
        break;
    //  ������ ������ ���� - ������� �� ��������� ������ ����� �� 5 ��������
    case GLUT_RIGHT_BUTTON:
        rotate_x -= 5;
        rotate_y += 5;
        break;
    }

    //  ���������� ��������� ����
    glutPostRedisplay();
}

int main(int argc, char* argv[]) {

    //  ������������� GlUT
    glutInit(&argc, argv);

    //  ������������� ������� ������ � ���������� Z
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    //  ������� ������� ����������� ����
    glutInitWindowSize(700, 700);

    //  ����� ���� � ����������� �����������
    glutCreateWindow("�������");

    //  ������������� ������� �����
    glEnable(GL_DEPTH_TEST);

    //  ����� ������� � ���������� ��������� ���������� � ����
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutMouseFunc(mouse);

    //  ������������ ������ ������
    glutMainLoop();

    //  ����� �� ���������
    return 0;

}
#endif



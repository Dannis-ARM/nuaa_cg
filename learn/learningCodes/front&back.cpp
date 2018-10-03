#include<gl/glut.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT, GL_FILL);//�����������ģʽ
	glPolygonMode(GL_BACK, GL_LINE);//���÷�������ģʽ
	glFrontFace(GL_CCW);//������ʱ�뷽��Ϊ����
	glBegin(GL_POLYGON);//�����·�����ʱ�����һ��������
	glVertex2f(-0.5, -0.5);
	glVertex2f(0.0, -0.5);
	glVertex2f(0.0, 0.0);
	glVertex2f(-0.5, 0.0);
	glEnd();
	glBegin(GL_POLYGON);//�����Ϸ���˳ʱ�����һ��������
	glVertex2f(0.0, 0.0);
	glVertex2f(0.0, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, 0.0);
	glEnd();
	glFlush();
}

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, 0.0, -1.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("test");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
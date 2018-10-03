#include<gl/glut.h>
#include<iostream>

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	// ���ı��δ�
	glBegin(GL_QUAD_STRIP);
	glVertex2f(-1.0, -1.0);
	glVertex2f(-0.9, 0.5);
	glVertex2f(-0.8, -0.5);
	glVertex2f(-0.7, 1.0);
	glVertex2f(-0.6, -1.0);
	glVertex2f(-0.5, 0.5);
	glVertex2f(-0.4, -0.5);
	glVertex2f(-0.3, 1.0);
	glVertex2f(-0.2, -1.0);
	glVertex2f(-0.1, 0.5);
	glVertex2f(-0.0, -0.5);
	glEnd();
	glColor3f(0.9, 0.5, 0.1);
	glPointSize(9.0);
	// ����
	glBegin(GL_POINTS);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.5, 0.5);
	glEnd();
	glLineWidth(4.0);
	glColor3f(0.5, 0.5, 0.8);
	// ����
	glBegin(GL_LINES);
	glVertex2f(-0.5, -0.9);
	glVertex2f(0.7, 0.8);
	glLineWidth(2.0);
	glColor3f(0.7, 0.3, 0.3);
	double t = -0.7;
	for (int i = 0; i < 11; i++) {
		glVertex2f(-0.7, -0.7);
		glVertex2f(cos(t), sin(t));
		t = t + 0.05*3.14159;
	}
	glEnd();
	glLineWidth(1.0);
	glColor3f(0.0, 1.0, 0.0);
	// ��Բ
	glBegin(GL_LINE_LOOP);
	int n = 100;
	double k;
	for (int i = 0; i < n; i++) {
		k = i * 2.0 * 3.14159 / n;
		glVertex2f(cos(k), 0.4*sin(k));
	}
	glEnd();
	// ����λ�͸��Բ
	glEnable(GL_BLEND); // �򿪻��
	glDisable(GL_DEPTH_TEST); // �ر���Ȳ���
	glBlendFunc(GL_SRC_ALPHA, GL_ONE); // ����Դ����alphaͨ��ֵ�İ�͸����Ϻ���
	glColor4f(1.0, 1.0, 0.0, 0.3);
	glBegin(GL_POLYGON);
	n = 40;
	double m;
	for (int i = 0; i < n; i++) {
		m = i*2.0*3.14159 / n;
		glVertex2f(cos(m), sin(m));
	}
	glEnd();
	glColor3f(1.0, 1.0, 1.0);
	// ������
	glBegin(GL_LINES);
		glVertex2f(-1.0, 0); glVertex2f(1.0, 0);
		glVertex2f(0.0, 1.0); glVertex2f(0.0, -1.0);
	glEnd();
	n = 1000;
	glColor3f(0.0, 0.0, 1.0);
	glLineWidth(3.0);
	double xMin = -10.0, xMax = 10.0, x, dx = (xMax - xMin) / n;
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i <= n; i++) {
		x = xMin + i*dx;
		glVertex2f(x*0.2, 0.6*tan(x));
	}
	glEnd();
	glFlush();
}

void init() {
	glClearColor(0.35, 0.35, 0.35, 0.5);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(400, 400);
	glutCreateWindow("helloworld");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;
}
#include<gl/glut.h>
#include<math.h>
GLfloat FRUSTDIM = 120.0;
GLfloat angle1 = 15.708, angle2 = -7.85;

// �任����
GLfloat m1[16] = {
	1.0, 0.0, 0.0, 0.0,
	0.0, 1.0, 0.0, 0.0,
	0.0, 0.0, 1.0, 0.0,
	50.0, 50.0, 50.0, 1.0
};
GLfloat m2[16] = {
	cos(angle1),sin(angle1),0.0,0.0,
	-sin(angle1),cos(angle1),0.0,0.0,
	0.0,0.0,1.0,0.0,
	0.0,0.0,0.0,1.0
};
GLfloat m3[16] = {
	1.0,0.0,0.0,0.0,
	0.0,cos(angle2),sin(angle2),0.0,
	0.0,-sin(angle2),cos(angle2),0.0,
	0.0,0.0,0.0,1.0
};

void initial() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT );
	glFrontFace(GL_CCW);
	glEnable(GL_COLOR_MATERIAL);
}
void drawCoordinateAxis() {
	// ����������
	glBegin(GL_POLYGON);		// Y
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 150.0, 0.0);
	glVertex3f(1.0, 150.0, 0.0);
	glVertex3f(1.0, 0.0, 0.0);
	glEnd();

	glBegin(GL_POLYGON);		// Z
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 150.0);
	glVertex3f(1.0, 0.0, 150.0);
	glVertex3f(1.0, 0.0, 0.0);
	glEnd();

	glBegin(GL_POLYGON);		// X
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(150.0, 0.0, 0.0);
	glVertex3f(150.0, 0.0, 1.0);
	glVertex3f(0.0, 0.0, 1.0);
	glEnd();
}
void display() {
	glTranslatef(-150.0, -150.0, -550.0);		// ����ȫ������ԭ��Ϊ(0,0,0)
	
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	// ���ƾ�������
	drawCoordinateAxis();

	// ���Ƶ�G1
	glPointSize(2.0);
	glBegin(GL_POINTS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(30.0, 50.0, 20.0);
	glEnd();

	// �����������߿�
	glPushMatrix();
		glTranslatef(25.0,25.0,25.0);
		glColor3f(0.0, 0.0, 0.0);
		glutSolidCube(50.0);
	glPopMatrix();

	// �任����
	glMultMatrixf(m1);
	glMultMatrixf(m2);
	glMultMatrixf(m3);
		
	//glTranslatef(50.0, 50.0, 50.0);
	//glRotatef(180.0, 0.0, 0.0, 1.0);
	//glRotatef(-90.0, 1.0, 0.0, 0.0);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	// ������������
	drawCoordinateAxis();

	// ���Ƶ�G2 �����غ�
	glPointSize(2.0);
	glBegin(GL_POINTS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(20.0, 30.0, 0.0);
	glEnd();

	glFlush();
}
void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w*1.5, (GLsizei)h*1.5);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-FRUSTDIM, FRUSTDIM, -FRUSTDIM, FRUSTDIM, 200., 600.);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 800);
	glutCreateWindow("�κ���ҵ1����ά��������ת����");
	initial();
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutMainLoop();
}
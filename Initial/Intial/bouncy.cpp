//#include <stdio.h>
//#include"glut.h"
//
//static int flag = 0;
//float tx, ty, tz = 0.0;
//float letter_x = 0.5, letter_y = 0.0, letter_z = 0.0;
//
//void updateBall()
//{
//	if (!flag)
//	{
//		letter_y += 0.05;
//		if (letter_y>1.0)
//			flag = 1;
//	}
//	if (flag)
//	{
//		letter_y -= 0.05;
//		if (letter_y<-1)
//			flag = 0;
//	}
//}
//void letter_G1()
//{
//
//	glColor3f(0.1, 1.1, 0.0);
//	glLineWidth(10.0);
//	glBegin(GL_LINE_STRIP);
//	glVertex2i(210, 200);
//	glVertex2i(160, 200);
//	glVertex2i(160, 100);
//	glVertex2i(210, 100);
//	glVertex2i(210, 150);
//	glVertex2i(185, 150);
//	glEnd();
//
//}
//void display()
//{
//	glPushMatrix();
//	letter_G1();
//	glPopMatrix();
//
//
//	glTranslatef(letter_x, letter_y, letter_z);
//	glutSolidSphere(0.3, 60, 23);
//	glPopMatrix();
//
//	updateBall();
//
//
//	glutSwapBuffers();
//}
//void idle()
//{
//	glutPostRedisplay();
//
//}
//void init(void)
//{
//	glClearColor(0.2, 0.0, 0.2, 0.0);  //background color 
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0.0, 700.0, 0.0, 800.0);
//}
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(50, 50);
//	glutCreateWindow("Bouncing");
//	glutIdleFunc(idle);
//	glutDisplayFunc(display);
//	init();
//	glutMainLoop();
//	return 0;
//
//
//}

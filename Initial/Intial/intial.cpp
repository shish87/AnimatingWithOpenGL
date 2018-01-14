#include <stdio.h>  
#include "glut.h"
#include<math.h>

float tx = 0.0;
float ty = 0.0; 
float sx=1.0; 
float sy=1.0;
int counter = 0; 

float theta = 0.0f;
float beta = 0.0f;
int refreshMills = 30;




void letter_S()
{
	
	glColor3f(1.0, 0.1, 0.0);
	glLineWidth(10.0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(150, 200);
	glVertex2i(100, 200);
	glVertex2i(100, 150);
	glVertex2i(150, 150);
	glVertex2i(150, 100);
	glVertex2i(100, 100);
	glEnd();
}



void letter_G()
{
	
	glColor3f(0.1, 1.1, 0.0);
	glLineWidth(10.0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(210, 200);
	glVertex2i(160, 200);
	glVertex2i(160, 100);
	glVertex2i(210, 100);
	glVertex2i(210, 150);
	glVertex2i(185, 150);
	glEnd();

}

void SpecialInput(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		glTranslatef(0.0f, 10.0f, 0.0f);
		glutPostRedisplay();
		break;

	case GLUT_KEY_DOWN:
		glTranslatef(0.0f, -10.0, 0.0);
		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT:
		glTranslatef(10.0f, 0.0f, 0.0f);
		glutPostRedisplay();
		break;
	case GLUT_KEY_LEFT:
		glTranslatef(-10.0f, 0.0f, 0.0f);
		glutPostRedisplay();
		break;
	}
}

void window_special_key(unsigned char key, int x, int y)
{
	float colors[][3] = { { 1.0f, 0.0f, 1.0f },{ 1.0f, 1.0f, 0.0f },{ 1.1f, 1.0f, 1.0f } };
	static int colorFrame;
	switch (key) {


	case 'r':
		beta = beta - 1.57; 		
		glutPostRedisplay();
		break;

	case 'l':
		
			beta = beta + 1.57;
			glutPostRedisplay();
			break;
		
	case 't':
		tx = tx + 2;
		ty = ty + 2;			
		glutPostRedisplay();
		break;
	case 's':
		sx = sx*1.2;
		sy = sy*1.2;		
		glutPostRedisplay();					
		break;
	case 'd':
		sx = sx*0.8;
		sy = sy*0.8;
		break;

	case 'c':

		
		glClearColor(colors[colorFrame][0], colors[colorFrame][1], colors[colorFrame][2], 0.0f);
		colorFrame += 1;
		glutPostRedisplay();
		break;
			
	default:
		printf("Pressing %d doesn't do anything.\n", key);
		break;

    case 27: 	// escape key “Esc” 
		exit(0);
		break;
	
	}
}
void Timer(int value) {
	glutPostRedisplay();      
	glutTimerFunc(refreshMills, Timer, 0); 
}
void idle()
{
	glutPostRedisplay();

}

void displayInitials()
{
	    glClear(GL_COLOR_BUFFER_BIT);
		glPushMatrix();
		
		
		glTranslatef(350.0, 350.0, 0.0);
		while (theta <= 1440) {
			glRotatef(theta, 0.0f, 0.0f, 1.0f);
			theta += 2.0f;
			break;
		}
		
		glRotatef(beta, 0.0f, 0.0f, 1.0f);
		glTranslatef(100 * (1 - sx), 100 * (1 - sy), 0.0);
		glScalef(sx, sy, 1.0);
		letter_S();
		letter_G();
		glPopMatrix();  
		glutSwapBuffers();
		theta += 2.0f;
		glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 700.0, 0.0, 800);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}

void init(void)
{
	
	glClearColor(0.2, 0.0, 0.2, 0.0);  
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 700.0, 0.0, 800.0);
}



int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(700, 800);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Drawing Initials");
	
	glutDisplayFunc(displayInitials);
	glutSpecialFunc(SpecialInput);
	glutTimerFunc(refreshMills, Timer, 0);
	glutKeyboardFunc(window_special_key);
	
	
	printf("PRESS: \n's' to scale up and 'd' to scale down SG around (100,100), \n use arrow key to move SG to the right, left, up and down \n 'c' to change background colour \n't' to translate X.\n 'r' and 'l' to Rotate SG toward Right and Left respectively \n");
	init();
	glutMainLoop();
	return 0;

	
		

}

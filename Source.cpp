#include <stdio.h>
#include <math.h>
#include<cmath>
#include<ctime>
#include <GL\glut.h>


#define PI 3.14159265358979323846
double drawW = 400, drawH = 300;

 
void reshape(int width, int height){
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	float ratio = (float)width / height;
	if (width > height)
	{
		glOrtho(-drawW * ratio, drawW * ratio, -drawH, drawH, -1, 1);}
	else
	{
		glOrtho(-drawW, drawW, -drawH / ratio, drawH / ratio, -1, 1);
}
	glClearColor(1, 1, 1, 1);}



void drawArc(double cx, double cy, double start, double end, double radius)
{
	double steps = 30;
	double delta = (end - start) / steps;
	glBegin(GL_LINE_STRIP);
	double angle = start;
	for (int i = 0; i <= steps; i++)
	{
		double x = cx + radius * cos(angle);
		double y = cy + radius * sin(angle);
		glVertex2f(x, y);
		angle += delta;

	}

	glEnd();

}


void drawCircle(double cx, double cy, double radius)
{
	double steps = 30;
	double delta = 2 * PI / steps;
	glBegin(GL_TRIANGLE_FAN);
	double angle = 0;
	glVertex2f(cx, cy);
	for (int i = 0; i <= steps; i++)
	{
		double x = cx + radius * cos(angle);
		double y = cy + radius * sin(angle);
		glVertex2f(x, y);
		angle += delta;
	}
	glEnd();
	glFlush();

}


void Snake()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1, 0, 0);	
	drawCircle(115,0, 20);  //face
	drawCircle(90, 0, 10);
	drawCircle(80, 0,10);
	drawCircle(70, 0, 10);
	drawCircle(60, 0, 10);
	drawCircle(50, 0, 10);
	drawCircle(40, 0, 10);
	drawCircle(30, 0,  5);
	glPopMatrix();
	//________________________//

		glColor3f(0, 1, 1);
		drawCircle(119, 7, 4);	
		drawCircle(119, -7, 4);	
	//_______________________//
	
	glColor3f(0, 0, 0);
	drawCircle(145,0,4);
	glEnd();
	glFlush();
	

	
	
}
void pointt() {
	glColor3f(0, 0, 0);
	drawCircle(145, 0, 4);
	glEnd();
	glFlush();
}
void point()
{
	
	glutDisplayFunc(Snake);
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 1, 1);
	srand(time(NULL));
	int x = (rand() % 200) + 1;
	int y = (rand() % 200) + 1;
	glEnable(GL_POINT_SMOOTH);
	glPointSize(15);
	glBegin(GL_POINTS);
	glVertex2f(x, y);

	glEnd();
	glFlush();

	
}



void processNormalKeys(unsigned char key, int x, int y)
{
	switch (key)
	{
	

	case 'R': 
	case 'r':
	case '6':
		glTranslated(10, 0, 0);
		Snake();
		glutDisplayFunc(pointt);
		break;
		


	case 'L':
	case 'l':
	case '4':
		glTranslated(-10, 0, 0);
		Snake();
		break;

	case 'U': 
	case 'u':
	case '8':
		glRotated(90, 0, 0, 1);
		Snake();
		break;
	case 'D': 
	case 'd':
	case '2':
		glRotated(-90, 0, 0, 1);
		Snake();
	
		break;
		

	
	case 'P':
	case 'p':
	case '5':
		glRotated(180, 0, 0, 1);
		Snake();
		break;
	case 'T':
	case 't':
	case '9':
		glRotated(10, 0, 0, 1);
		Snake();
		break;
	case 'E':
	case 'e':
	case '3':
		glRotated(-10, 0, 0, 1);
		Snake();
		break;

	}
}


int main()
{	
	glutInitWindowSize(1250,650);
	glClearColor(1, 1, 1, 1);
	glutCreateWindow("Snake");
	glutDisplayFunc (point);
	glutReshapeFunc(reshape);
	//glutDisplayFunc(Snake);
	glutKeyboardFunc(processNormalKeys);
	glutMainLoop();
	return 0;
}

// ABALL.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include <memory>
#include "Ball.h"
#include "Bar.h"

using namespace std;

const int windowWidth = 800;
const int windowHeight = 600;

shared_ptr<Ball> ball;
shared_ptr<Bar> player;


GLfloat xstep = 150;
GLfloat ystep = 150;

float framesPerSecond = 0.0f;
bool calculateDone = false;
float FPS = 0;
int time = 0;

void CalculateFrameRate()
{
	static float lastTime = 0.0f;       // This will hold the time from the last frame
	float currentTime = GetTickCount() * 0.001f;
	++framesPerSecond;
	if (currentTime - lastTime > 1.0f)
	{
		lastTime = currentTime;
		fprintf(stderr, "\nCurrent Frames Per Second: %d\n\n", (int)framesPerSecond);

		FPS = framesPerSecond;
		framesPerSecond = 0;
		if (time < 2) {
			time++;
		}
		if (time == 2) {
			calculateDone = true;
		}
	}
}


void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	ball->paint();
	player->paint();
	glutSwapBuffers();
	CalculateFrameRate();

}

void timerFunc(void){
	if (!calculateDone)
	{
		glutPostRedisplay();
		return;
	}
	ball->move(windowWidth,windowHeight, FPS);
	glutPostRedisplay();
	
}

void specialkey(int key, int mx, int my) {
	switch (key)
	{
	case GLUT_KEY_UP:
		player->move();
		glutPostRedisplay();
	default:
		break;
	}
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(windowWidth, windowHeight);

	glutCreateWindow("第一个OpenGL程序");

	gluOrtho2D(-windowWidth/2, windowWidth/2, -windowHeight/2, windowHeight/2);

	ball = make_shared<Ball>(100, 50, 20,xstep, ystep);
	player = make_shared<Bar>(380, 30, 50, 100);
	glutDisplayFunc(myDisplay);
	glutSpecialFunc(specialkey);
	glutIdleFunc(timerFunc);

	glutMainLoop();
	return 0;
}
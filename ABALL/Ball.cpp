#include "stdafx.h"
#include "Ball.h"

void Ball::paint() {
	int n = 100;
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < n; i++)
	{
		glVertex2f(centerX + (radius*cos(i * 2 * PI / n)), centerY + (radius*sin(i * 2 * PI / n)));
	}
	glEnd();
}

void Ball::move(int windowWidth, int windowHeight, float FPS) {
	if (centerX > windowWidth/2 - radius || centerX - radius < -windowWidth/2)
	{
		xstep = -xstep;
	}
	if (centerY > windowHeight/2 - radius || centerY - radius < -windowHeight/2)
	{
		ystep = -ystep;
	}

	if (centerX > windowWidth/2 - radius)
	{
		centerX = windowWidth/2 - radius - 1;
	}
	if (centerY > windowHeight/2 - radius)
	{
		centerY = windowHeight/2 - radius - 1;
	}

	GLfloat movX = xstep / FPS;
	GLfloat movY = ystep / FPS;
	centerX += movX;
	centerY += movY;
}

#pragma once
#include <GL/glut.h>
#include <math.h>
#define PI 3.14159265759f

class Ball
{
public:
	Ball() = default;
	~Ball() = default;
	Ball(GLfloat x, GLfloat y, GLfloat r, GLfloat xs, GLfloat ys): centerX(x), centerY(y), radius(r), xstep(xs), ystep(ys){}
	void paint();
	void move(int windowWidth, int windowHeight, float FPS);

private:
	GLfloat centerX;
	GLfloat centerY;
	GLfloat radius;
	GLfloat xstep;
	GLfloat ystep;
};


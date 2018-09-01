#pragma once
#include <GL/glut.h>

class Bar
{
public:
	Bar() = default;
	Bar(GLfloat x, GLfloat y, GLfloat w, GLfloat h) : posX(x), posY(y), width(w), height(h) {}
	~Bar() = default;
	void paint();
	void move();

private:
	GLfloat posX;
	GLfloat posY;
	GLfloat width;
	GLfloat height;
};

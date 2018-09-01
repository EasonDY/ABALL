#include "stdafx.h"
#include "Bar.h"

void Bar::paint() {
	glRectf(posX, posY, posX + width, posY - height);
}

void Bar::move() {
	posY += 10;
}
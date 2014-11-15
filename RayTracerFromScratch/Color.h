#pragma once
#include "vector.h"
class Color :
	public Vector
{
public:
	Color(void): Vector(){};
	Color(float r, float g, float b) : Vector(r, g, b){};
	~Color(void);
};

Color *colMult(Color *c1, Color *c2);
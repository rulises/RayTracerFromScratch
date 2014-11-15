#pragma once
#include "Vector.h"
#include "Common.h"
class Ray
{
public:
	Ray(void):position(Vector()), direction(Vector()){};
	Ray(Vector in_position, Vector in_direction):position(in_position), direction(in_direction){};
	~Ray(void);

    Vector position;
    Vector direction;
};


#pragma once
#include "object.h"
class Sphere :
	public Object
{
public:
	Sphere(void): Object(), radius(-1.0){};
	Sphere(Vector pos, int mat, float r): Object(pos, mat), radius(r) {};
	~Sphere(void);
    
    float radius;
    
};

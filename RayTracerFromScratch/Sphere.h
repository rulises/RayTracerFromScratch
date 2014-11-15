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


	// conversion from A (constructor):
	Sphere (const Object& x) {}
	// conversion from A (assignment):
	Sphere& operator= (const Object& x) {return *this;}

};

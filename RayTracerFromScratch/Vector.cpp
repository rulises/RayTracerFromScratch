#include "Vector.h"

Vector::Vector(void) : x(0.0), y(0.0), z(0.0) {
}

Vector::Vector(float a, float b, float c) 
{
    x = a;
    y = b;
    z = c;
}

Vector::~Vector(void)
{
}



Vector vecScale(Vector *v1, float k)
{
    Vector ret = Vector(k*v1->x, k*v1->y, k*v1->z);
    return ret;
}

Vector vecAdd(Vector *v1, Vector * v2)
{
    Vector ret = Vector(v1->x + v2->x, v1->y + v2->y, v1->z + v2->z);
    return ret;
}

Vector vecMinus(Vector *v1, Vector *v2)
{
    Vector ret = Vector(v1->x - v2->x, v1->y - v2->y, v1->z - v2->z);
   
    return ret;
}

Vector vecCross(Vector *v1, Vector *v2)
{
    Vector ret = Vector();
   
    return ret;
}

float vecDot(Vector *v1, Vector *v2)
{
    float ret = v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
    return ret;
}
float vecMagnitude(Vector *v1)
{
    float ret = v1->x * v1->x + v1->y * v1->y + v1->z * v1->z;
    return ret;
}
Vector vecTimes(Vector *c1, Vector *c2)
{
	Vector ret = Vector(c1->x*c2->x,c1->y*c2->y, c1->z *c2->z );
    return ret;
}
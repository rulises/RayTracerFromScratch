#pragma once
class Vector
{
public:
    Vector(float a, float b, float c);
    Vector(void);
	~Vector(void);

	float x;
    float y;
    float z;
};

Vector vecScale(Vector *v1, float k);
Vector vecAdd(Vector *v1, Vector *v2);
Vector vecMinus(Vector *v1, Vector *v2);
Vector vecCross(Vector *v1, Vector *v2);
Vector vecTimes(Vector *v1, Vector *v2);
float vecDot(Vector *v1, Vector *v2);
float vecMagnitude(Vector *v1);


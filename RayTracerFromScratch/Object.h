#pragma once
#include "Vector.h"
#include "Material.h"
class Object
{
public:
	Object(void):position(Vector()),material(-1){};
	Object(Vector pos, int mat):position(pos), material(mat) {};
	virtual ~Object(){};

    Vector position;
    int material;
};


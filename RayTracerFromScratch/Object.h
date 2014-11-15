#pragma once
#include "Vector.h"
#include "Material.h"
class Object
{
public:
	Object(void):position(Vector()),material(-1.0){};
	Object(Vector pos, int mat):position(pos), material(mat) {};
	~Object(void);

    Vector position;
    int material;
};


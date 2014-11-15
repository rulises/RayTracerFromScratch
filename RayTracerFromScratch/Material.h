#pragma once
#include "Color.h"
class Material
{
public:
	Material(void) : reflection(-1.0), power(-1.0), diffuse(Color()), specular(Color()) {};
	Material(Color s, Color d, float r, float p) : reflection(r), power(p), diffuse(d), specular(s) {};
	~Material(void);

    float reflection;
    float power;
    Color diffuse;
    Color specular;
    //Color *emissive;
    //Color *ambient;
};


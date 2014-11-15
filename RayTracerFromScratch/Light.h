#pragma once

#include "Vector.h"
#include "Color.h"

class Light 
{
public:
	Light(void): position(Vector()), intensity(Color()) {};
	Light(Vector in_position, Color in_intensity):position(in_position), intensity(in_intensity){};

	~Light(void);
    
    Vector position;
    Color intensity;

};

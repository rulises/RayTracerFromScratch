#pragma once
#include <stdio.h>
#include "Common.h"
#include "Scene.h"
#include "Ray.h"
#include "TraceFunc.h"

class RayTracer
{
public:
	RayTracer(void);
	~RayTracer(void);

    Scene scene;

    void render(unsigned char *img);
	float shade(Ray *ray, Vector * natural_color, int obj_idx, float depth,float coef);
};

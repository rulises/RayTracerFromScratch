#pragma once
#include "Ray.h"
#include "Sphere.h"
#include "Common.h"
#include <math.h>

#define min(a,b) (((a) < (b)) ? (a) : (b))

/* Function prototypes */
bool intersectRayObject(Ray *ray, Object *object, float *t);
bool intersectRaySphere(Ray *ray, Sphere *sphere, float *t);

        


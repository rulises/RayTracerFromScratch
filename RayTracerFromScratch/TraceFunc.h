#pragma once
#include "Ray.h"
#include "Sphere.h"
#include "Common.h"
#include <math.h>

#define min(a,b) (((a) < (b)) ? (a) : (b))

/* Function prototypes */
bool intersectRaySphere(Ray *ray, Sphere *sphere, float *t);

        


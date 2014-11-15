#include "TraceFunc.h"


bool intersectRaySphere(Ray *ray, Sphere *sphere, float *t)
{
        bool ret = FALSE;
            /* Compute A, B and C coefficients */
        //printf("Ray Pos: %d\n", ray->position->x);
        //printf("Sphere Pos: %d\n", sphere->position->x);
        float a = vecDot(&ray->direction, &ray->direction);
        Vector dist = vecMinus(&ray->position, &sphere->position);
        float b = 2 * vecDot(&dist, &ray->direction);
        float c = vecDot(&dist, &dist) - (sphere->radius * sphere->radius);
 
        /* Find discriminant */
        float disc = b * b - 4 * a * c;

        /* If discriminant is negative, there are no real roots.
         * Return false as the ray misses the sphere. */
        if(disc < 0)
                return FALSE;
        
        /* Compute q */
        float discSqrt = sqrtf(disc);
        float q;
        
        if(b < 0)
                q = (-b - discSqrt)/2.0;
        else
                q = (-b + discSqrt)/2.0;
        
        /* The roots */
        float t0 = q / a;
        float t1 = c / q;
        
        if(t0 > t1)
                t0 = t1;
        
        /* Verify t0 larger than 0 and less than the original t */
        if((t0 > 0.001f) && (t0 < *t)){
                *t = t0;
                ret = TRUE;
        }
        
        return ret;
}

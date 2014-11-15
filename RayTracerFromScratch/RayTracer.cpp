#include "RayTracer.h"
#define NUMTHREADS 1

RayTracer::RayTracer(void)
{
    scene = Scene();
    defaultScene(&scene);
}


RayTracer::~RayTracer(void)
{
}

float RayTracer::shade(Ray *ray, Vector * natural_color, int obj_idx, int depth, float coef){

	// Find the normal for this new vector at the point of intersection
	Vector point_intersect =  Vector(vecScale(&ray->direction, depth));
	Vector new_position =  Vector(vecAdd(&ray->position,&point_intersect));
	Vector normal = Vector(vecMinus(&new_position, &scene.spheres[obj_idx].position));
	float magnitude = vecMagnitude( &normal);
	if(magnitude == 0.0f) return -1;
	float div = 1.0f / sqrtf(magnitude);
	normal = vecScale(&normal, div);

	//Start with the object's material
	Material current_material =  scene.materials[obj_idx];
	//Get the lightning
	for each (Light light in scene.lights)
	{
		Vector distance_isect = vecMinus(&light.position,&new_position);
		if (vecDot(&normal,&distance_isect) <= 0.0f) continue;
		float magnitude = vecMagnitude( &distance_isect);
		if(sqrtf(magnitude) == 0.0f) continue;
		float div = 1.0f / sqrtf(magnitude);
		Vector normal_light = vecScale(&distance_isect, div);
                               
        Ray lightRay = Ray(new_position, normal_light);


		float illumination = vecDot(&lightRay.direction, &normal) * coef;
		Vector color = vecTimes( &vecScale(&light.intensity,illumination),&current_material.diffuse);
		natural_color->x += color.x;
		natural_color->y += color.y;
		natural_color->z += color.z;
	}
	coef *= current_material.reflection;
	float reflect = 2.0f * vecDot(&ray->direction, &normal);
	ray->position = Vector(new_position);
    Vector tmp =  Vector(vecScale(&normal, reflect));
	ray->direction = Vector(vecMinus(&ray->direction, &tmp));
    return coef;
                                        // Calculate the shadows 
                                       /* bool inShadow = FALSE;
                                        unsigned int k;
                                        for (k = 0; k < SPHERES; ++k) {
                                                if (collideRaySphere(&lightRay, &myScene.spheres[k], &t)){
                                                        inShadow = TRUE;
                                                        break;
                                                }
                                        }
										  */     
                                        //if (!inShadow){
                                                //Diffuse reflaction using Lambert

                                       // }  
 
}
void RayTracer::render(unsigned char *img){

        int x,y;
        for (y = 0; y < HEIGHT; y++){
                for (x = 0; x < WIDTH; x++) {
  
                        float coef = 1.0f;
                        int level = 0;
						Vector natural_color = Vector(0.0f, 0.0f, 0.0f);
						//Cast a ray per pixel
                        Vector pos =  Vector((float)x,(float)y,-10000.0f);
                        Vector dir =  Vector(0.0, 0.0, 1.0);
                        Ray ray  = Ray(pos,dir);
						do{
							//Find closest intersection
							float t = 20000.0f;
							int current_sphere_idx = -1;
							for (int i= 0; i < scene.spheres.size(); i++){
								if (intersectRaySphere(&ray, &(scene.spheres[i]), &t)){
										current_sphere_idx = i;
									}
							}
							if(current_sphere_idx == -1) break;
							coef = shade(&ray, &natural_color, current_sphere_idx, t, coef);
							if(coef == -1) break;
							level++;
						} while ((coef > 0.0f) && (level < 10));

                        img[(x+y*scene.width)*3+2] = (unsigned char)min(natural_color.x*255.0f, 255.0f);
                        img[(x+y*scene.width)*3+1] = (unsigned char)min(natural_color.y*255.0f, 255.0f);
                        img[(x+y*scene.width)*3+0] = (unsigned char)min(natural_color.z*255.0f,255.0f);
                }
        }
}
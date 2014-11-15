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

void RayTracer::render(unsigned char *img){

        int x,y;
        for (y = 0; y < HEIGHT; y++){
                for (x = 0; x < WIDTH; x++) {
                        
                        float red = 0, green = 0, blue = 0;
                        float coef = 1.0f;
                        int level = 0;

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

							Vector scaled =  Vector(vecScale(&ray.direction, t));
							Vector newStart =  Vector(vecAdd(&ray.position,&scaled));
                        
							// Find the normal for this new vector at the point of intersection
							Vector normal = Vector(vecMinus(&newStart, &scene.spheres[current_sphere_idx].position));
							float temp = vecDot(&normal, &normal);
							if(temp == 0.0f) break;

							temp = 1.0f / sqrtf(temp);
							normal = vecScale(&normal, temp);

							// Get current material to determine the colour 
							Material current_material =  scene.materials[current_sphere_idx];

							// Find the value of the light at this point 
							 unsigned int j;
                                for (j = 0; j < LIGHTS; ++j){
                                        Light current = scene.lights[j];
                                        Vector dist = vecMinus(&current.position,&newStart);
                                        if (vecDot(&normal,&dist) <= 0.0f) continue;
                                        float t = sqrtf(vecDot(&dist,&dist));
                                        if (t <= 0.0f) continue;
                                        Ray lightRay;
                                        lightRay.position = newStart;
                                        lightRay.direction = vecScale(&dist,(1/t)); 
                                        
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
										float lambert = vecDot(&lightRay.direction, &normal) * coef;
                                                red += lambert * current.intensity.x * current_material.diffuse.x;
												green += lambert * current.intensity.y * current_material.diffuse.y;
												blue += lambert * current.intensity.z * current_material.diffuse.z;
                                       // }  
 
                                }

								// Iterate over the reflection 
                                coef *= current_material.reflection;
								float reflect = 2.0f * vecDot(&ray.direction, &normal);
								ray.position = newStart;
                                Vector tmp =  Vector(vecScale(&normal, reflect));
								ray.direction = Vector(vecMinus(&ray.direction, &tmp));
                                level++;
                                // Limit iteration depth to 10   
						} while ((coef > 0.0f) && (level < 10));

                        img[(x+y*scene.width)*3+2] = (unsigned char)min(red*255.0f, 255.0f);
                        img[(x+y*scene.width)*3+1] = (unsigned char)min(green*255.0f, 255.0f);
                        img[(x+y*scene.width)*3+0] = (unsigned char)min(blue*255.0f,255.0f);
                }
        }
}
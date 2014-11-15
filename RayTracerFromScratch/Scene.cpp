#include "Scene.h"



static const float myMaterials[MATERIALS][8]={ {0.8, 0.8, 0.0, 0.5, 1.0, 1.0, 1.0, 60},
                                               {0.0, 0.8, 0.8, 0.5, 1.0, 1.0, 1.0, 60},
                                               {0.8, 0.0, 0.8, 0.5, 1.0, 1.0, 1.0, 60},
                                               {0.2, 0.4, 0.6, 0.5, 1.0, 1.0, 1.0, 60}
                                             };
/* Scene Spheres */
/* pos x, pos y, pos z, size, material index */ 
static const float mySpheres[OBJECTS-1][5]={ {150.0, 400.0, 50.0, 50, 0},
                                           {500.0, 200.0, 100.0, 50, 1},
                                           {300.0, 140.0, 200.0, 50, 2}
                                         };
/* Scene Lights */
/* pos x, pos y, pos z, r, g, b */
static const float myLights[LIGHTS][6]={ {0.000, 240.0, 40.000, 1.0, 1.0, 1.0},
                                         {320.0, 300.0, -10000.0, 0.6, 0.7, 1.0}
                                       };

Scene::Scene(void)
{
}


Scene::~Scene(void)
{
}

void Scene::addMaterial(Material * mat)
{
	materials.push_back(*mat);
}
void Scene::addObject(Object * o)
{
	objects.push_back(o);
}
void Scene::addLight(Light * l)
{
	lights.push_back(*l);
}
void defaultScene(Scene *scene){
    
        int i=0;

        /* Set scene size */
        scene->width  = WIDTH;
        scene->height = HEIGHT;

        /* Populate all materials */
		 
        for (i=0; i < MATERIALS; i++){
                Color spec =  Color(myMaterials[i][4],myMaterials[i][5],myMaterials[i][6]);
                Color diff =  Color(myMaterials[i][0],myMaterials[i][1],myMaterials[i][2]);
                float ref = myMaterials[i][3];
                float pow = myMaterials[i][7];
                Material *mat = new Material(spec, diff, ref, pow);
				scene->addMaterial(mat);
        }
        /* Populate all objects */
        for (i=0; i < OBJECTS; i++){
                Vector pos = Vector(mySpheres[i][0],mySpheres[i][1],mySpheres[i][2]);
                float r = mySpheres[i][3];
                int mat = (int)mySpheres[i][4];
                Object *o = new Sphere(pos,mat,r);
                scene->addObject(o);
        }
        /* Populate all lights */
        for (i=0; i < LIGHTS; i++){
                Vector pos = Vector(myLights[i][0],myLights[i][1],myLights[i][2]);
                Color col = Color(myLights[i][3],myLights[i][4],myLights[i][5]);
                Light *l = new Light(pos, col);
                scene->addLight(l);
        }
}
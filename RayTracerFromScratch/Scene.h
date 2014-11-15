#include <vector>	
#include "Light.h"
#include "Material.h"
#include "Sphere.h"
#include "Common.h"
#pragma once

/* default values */
#define MATERIALS   4
#define LIGHTS      2
#define SPHERES     4

class Scene
{
public:
	Scene(void);
	~Scene(void);

    int width;
    int height;
    std::vector<Light> lights;
    //std::list<Object> *objects;
    std::vector<Sphere> spheres;
	std::vector<Material> materials;

    void addMaterial(Material * mat);
    void addSphere(Sphere * s);
    void addLight(Light *l);
};

void defaultScene(Scene *scene);


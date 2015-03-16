#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <string>
#include "Solid.h"
#include "Light.h"
#include "Camera.h"

class Scene {
public:
	Scene();
	~Scene();
	void Add(std::vector<Solid> solids);
	void Add(std::vector<Camera> cameras);
	void Add(std::vector<Light> lights);
	std::vector<Solid> Solids() const;
	std::vector<Camera> Cameras() const;
	std::vector<Light> Lights() const;
	void Set(std::vector<Solid> solids);
	void Set(std::vector<Camera> cameras);
	void Set(std::vector<Light> lights);
	void Clear(std::string mode);
private:
	std::vector<Solid> solids;
	std::vector<Camera> cameras;
	std::vector<Light> lights;
};

#endif

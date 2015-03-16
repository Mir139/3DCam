#include "Scene.h"

using namespace std;

Scene::Scene() {
}

Scene::~Scene() {
}

void Scene::Add(vector<Solid> solids) {
	copy(solids.begin(), solids.end(), std::back_inserter(this->solids));
}

void Scene::Add(vector<Camera> cameras) {
	copy(cameras.begin(), cameras.end(), std::back_inserter(this->cameras));
}

void Scene::Add(vector<Light> lights) {
	copy(lights.begin(), lights.end(), std::back_inserter(this->lights));
}

vector<Solid> Scene::Solids() const {
	return this->solids;
}

vector<Camera> Scene::Cameras() const {
	return this->cameras;
}

vector<Light> Scene::Lights() const {
	return this->lights;
}

void Scene::Set(vector<Solid> solids) {
	this->solids = solids;
}

void Scene::Set(vector<Camera> cameras) {
	this->cameras = cameras;
}

void Scene::Set(vector<Light> lights) {
	this->lights = lights;
}

void Scene::Clear(string mode) {
	if(mode == "all") {
		this->solids.clear();
		this->cameras.clear();
		this->lights.clear();
	}
	else if(mode == "solid") {
		this->solids.clear();
	}
	else if(mode == "camera") {
		this->cameras.clear();
	}
	else if(mode == "light") {
		this->lights.clear();
	}
	else {
		this->solids.clear();
		this->cameras.clear();
		this->lights.clear();
	}
}

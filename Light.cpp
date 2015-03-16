#include "Light.h"

using namespace std;

Light::Light() : Point() {
	this->orientation[0] = 1;
}

Light::Light(double x, double y, double z) : Point(x, y, z) {
	this->orientation[0] = 1;
}

Light::Light(double * coords) : Point(coords) {
	this->orientation[0] = 1;
}

const double * Light::Orientation() const {
	return this->orientation;
}

double Light::Orientation(int n) const {
	if(n >= 0 && n <= 2) {
		return this->orientation[n];
	}
	else { return 0; }
}

void Light::SetOrientation(double * orientation) {
	if(sizeof(orientation) == 3) {
		this->orientation[0] = orientation[0];
		this->orientation[1] = orientation[1];
		this->orientation[2] = orientation[2];
	}
}

string Light::Type() const {
	return this->type;
}

void Light::SetType(string type) {
	this->type = type;
}

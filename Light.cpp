#include "Light.h"

using namespace std;

Light::Light() : Point() {
    this->orientation = {1, 0, 0};
}

Light::Light(double x, double y, double z) : Point(x, y, z) {
    this->orientation = {1, 0, 0};
}

Light::Light(std::vector<double> coords) : Point(coords) {
    this->orientation = {1, 0, 0};
}

const std::vector<double> Light::Orientation() const {
	return this->orientation;
}

double Light::Orientation(int n) const {
	if(n >= 0 && n <= 2) {
		return this->orientation[n];
	}
	else { return 0; }
}

void Light::SetOrientation(std::vector<double> orientation) {
	if(sizeof(orientation) == 3) {
        this->orientation = orientation;
	}
}

string Light::Type() const {
	return this->type;
}

void Light::SetType(string type) {
	this->type = type;
}

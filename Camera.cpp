#include "Camera.h"

using namespace std;

Camera::Camera() : Point() {
	this->orientation[0] = 1;
	this->focal = 1;
	SetPlanCam();
}

Camera::Camera(double x, double y, double z) : Point(x, y, z) {
	this->orientation[0] = 1;
	this->focal = 1;
	SetPlanCam();
}

Camera::Camera(double * coords) : Point(coords) {
	this->orientation[0] = 1;
	this->focal = 1;
	SetPlanCam();
}

Camera::~Camera() {
}

const double * Camera::Orientation() const {
	return this->orientation;
}

double Camera::Orientation(int n) const {
	if(n >= 0 && n <= 2) {
		return this->orientation[n];
	}
	else {
		return 0;
	}
}

void Camera::SetOrientation(double * orientation) {
	if(sizeof(orientation) == 3) {
		this->orientation[0] = orientation[0];
		this->orientation[1] = orientation[1];
		this->orientation[2] = orientation[2];
		SetPlanCam();
	}
}

double Camera::Focal() const {
	return this->focal;
}

void Camera::SetFocal(double focal) {
	if(focal > 0) {
		this->focal = focal;
		SetPlanCam();
	}
}

void Camera::SetPlanCam() {
	double coords[3];
	coords[0] = this->focal * this->orientation[0] + this->Coords(0);
	coords[1] = this->focal * this->orientation[1] + this->Coords(1);
	coords[2] = this->focal * this->orientation[2] + this->Coords(2);
	double equation[4];
	equation[0] = this->orientation[0];
	equation[1] = this->orientation[1];
	equation[2] = this->orientation[2];
	equation[3] = - (coords[0] * this->orientation[0] + coords[1] * this->orientation[1] + coords[2] * this->orientation[2]);
	this->planCam.SetCoords(coords);
	this->planCam.SetEquation(equation);
}

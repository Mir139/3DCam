#include "Camera.h"

using namespace std;

Camera::Camera() {
    this->coords = {0, 0, 0};
    this->focal = 1;
	SetPlanCam();
}

Camera::Camera(double x, double y, double z) {
    this->coords = {x, y, z};
    this->focal = 1;
    this->repere.SetOrigin(x, y, z);
	SetPlanCam();
}

Camera::Camera(std::vector<double> coords) {
    this->coords = coords;
    this->focal = 1;
    this->repere.SetOrigin(coords);
	SetPlanCam();
}

Camera::~Camera() {
}

void Camera::SetCoords(std::vector<double> coords) {
    if(coords.size() == 3) {
        this->coords = coords;
        this->repere.SetOrigin(coords);
        SetPlanCam();
    }
}

void Camera::SetCoords(double x, double y, double z) {
    this->coords = {x, y, z};
    this->repere.SetOrigin(x, y, z);
    SetPlanCam();
}

const std::vector<double> Camera::Orientation() const {
    return this->repere.Orientation();
}

double Camera::Orientation(int n) const {
	if(n >= 0 && n <= 2) {
        return this->repere.Orientation(n);
	}
	else {
		return 0;
	}
}

void Camera::SetOrientation(std::vector<double> orientation) {
    if(orientation.size() == 3) {
        this->repere.SetOrientation(orientation);
		SetPlanCam();
	}
}

void Camera::SetOrientation(double y, double q, double j) {
    this->repere.SetOrientation(y, q, j);
    SetPlanCam();
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
    /*
    std::vector<double> coords(3);
    coords[0] = this->focal * this->repere.Matrix(0,0) + this->Coords(0);
    coords[1] = this->focal * this->repere.Matrix(0,1) + this->Coords(1);
    coords[2] = this->focal * this->repere.Matrix(0,2) + this->Coords(2);
    std::vector<double> equation(4);
    equation[0] = this->repere.Matrix(0,0);
    equation[1] = this->repere.Matrix(0,1);
    equation[2] = this->repere.Matrix(0,2);
    equation[3] = - (coords[0] * this->repere.Matrix(0,0) + coords[1] * this->repere.Matrix(0,1) + coords[2] * this->repere.Matrix(0,2));
    this->planCam.SetCoords(coords);
    this->planCam.SetEquation(equation);
    */

    std::vector<double> coords(3);
    coords[0] = this->focal;
    std::vector<double> equation(4);
    equation[0] = 1;
    equation[3] = - this->focal;
    this->planCam.SetCoords(coords);
    this->planCam.SetEquation(equation);
}

Point Camera::Projection(std::vector<double> vectCamPoint) {
    Point newPoint;
    newPoint = this->planCam.Pojection(this->coords, vectCamPoint);
    return newPoint;
}

Point Camera::BaseChange(Point myPoint) {
    Point tmpPoint(myPoint.Coords(0) - this->planCam.Coords(0), myPoint.Coords(1) - this->planCam.Coords(1), myPoint.Coords(2) - this->planCam.Coords(2));
    std::vector<double> newCoords(3);

    for(unsigned int i = 0 ; i < 3 ; i++) {
        newCoords[i] = this->repere.Matrix(0,i) * tmpPoint.Coords(0) + this->repere.Matrix(1,i) * tmpPoint.Coords(1) + this->repere.Matrix(2,i) * tmpPoint.Coords(2);
    }
/*
    newCoords[0] = 0 * tmpPoint.Coords(0) + 0 * tmpPoint.Coords(1) + (-1) * tmpPoint.Coords(2);// 1 ou -1
    newCoords[1] = 0 * tmpPoint.Coords(0) + 1 * tmpPoint.Coords(1) + 0 * tmpPoint.Coords(2);
    newCoords[2] = 1 * tmpPoint.Coords(0) + 0 * tmpPoint.Coords(1) + 0 * tmpPoint.Coords(2); // -1 ou 1
*/
    Point newPoint(newCoords);
    return newPoint;
}

PlanCam Camera::GetPlanCam() const {
    return this->planCam;
}

Repere Camera::GetRepere() const {
    return this->repere;
}

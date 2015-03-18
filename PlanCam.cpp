#include "PlanCam.h"

using namespace std;

PlanCam::PlanCam() : Point() {
    this->equation.resize(4);
}

PlanCam::PlanCam(double x, double y, double z) : Point(x, y, z) {
    this->equation.resize(4);
}

PlanCam::PlanCam(std::vector<double> coords) : Point(coords) {
    this->equation.resize(4);
}

PlanCam::~PlanCam() {
}

std::vector<double> PlanCam::Equation() const {
    return this->equation;
}

double PlanCam::Equation(int n) const {
	if(n >= 0 && n <= 3) {
		return this->equation[n];
	}
	else { return 0; }
}

void PlanCam::SetEquation(std::vector<double> equation) {
    if(equation.size() == 4) {
        this->equation = equation;
	}
}

Point PlanCam::Pojection(Point centreCamera, std::vector<double> vectCamPoint) const {
/*
	double coordsPoint[3] = {myPoint.Coords()[0], myPoint.Coords()[1], myPoint.Coords()[2]};
	double distance = this->equation[0] * coordsPoint[0] + this->equation[1] * coordsPoint[1] + this->equation[2] * coordsPoint[2];
	double newCoords[3];
	Point newPoint(coordsPoint[0] - distance * this->equation[0], coordsPoint[1] - distance * this->equation[1], coordsPoint[2] - distance * this->equation[2]);
	return newPoint;
*/

    Point newPoint;
    double t = -(this->equation[0] * centreCamera.Coords()[0] + this->equation[1] * centreCamera.Coords()[1] + this->equation[2] * centreCamera.Coords()[2] + this->equation[3]) / (this->equation[0] * vectCamPoint[0] + this->equation[1] * vectCamPoint[1] + this->equation[2] * vectCamPoint[2] + this->equation[3]);
    newPoint = Point(centreCamera.Coords()[0] + vectCamPoint[0] * t, centreCamera.Coords()[1] + vectCamPoint[1] * t, centreCamera.Coords()[2] + vectCamPoint[2] * t);
    return newPoint;
}

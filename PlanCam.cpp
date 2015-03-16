#include "PlanCam.h"

using namespace std;

PlanCam::PlanCam() : Point() {
}

PlanCam::PlanCam(double x, double y, double z) : Point(x, y, z) {
}

PlanCam::PlanCam(double * coords) : Point(coords) {
}

PlanCam::~PlanCam() {
}

const double * PlanCam::Equation() const {
	return this->equation;
}

double PlanCam::Equation(int n) const {
	if(n >= 0 && n <= 3) {
		return this->equation[n];
	}
	else { return 0; }
}

void PlanCam::SetEquation(double * equation) {
	if(sizeof(equation) == 4) {
		this->equation[0] = equation[0];
		this->equation[1] = equation[1];
		this->equation[2] = equation[2];
		this->equation[3] = equation[3];
	}
}

Point PlanCam::Pojection(Point centreCamera, Point myPoint) const {
/*
	double coordsPoint[3] = {myPoint.Coords()[0], myPoint.Coords()[1], myPoint.Coords()[2]};
	double distance = this->equation[0] * coordsPoint[0] + this->equation[1] * coordsPoint[1] + this->equation[2] * coordsPoint[2];
	double newCoords[3];
	Point newPoint(coordsPoint[0] - distance * this->equation[0], coordsPoint[1] - distance * this->equation[1], coordsPoint[2] - distance * this->equation[2]);
	return newPoint;
*/

	double vectCamPoint[3] = {myPoint.Coords(0) - centreCamera.Coords(0), myPoint.Coords(1) - centreCamera.Coords(1), myPoint.Coords(2) - centreCamera.Coords(2)};
	double vectCamPlan[3] = {this->Coords(0) - centreCamera.Coords(0), this->Coords(1) - centreCamera.Coords(1), this->Coords(2) - centreCamera.Coords(2)};
	if(vectCamPoint[0] * vectCamPlan[0] + vectCamPoint[1] * vectCamPlan[1] + vectCamPoint[2] * vectCamPlan[2] > 0) {
		double t = -(this->equation[0] * centreCamera.Coords()[0] + this->equation[1] * centreCamera.Coords()[1] + this->equation[2] * centreCamera.Coords()[2] + this->equation[3]) / (this->equation[0] * vectCamPoint[0] + this->equation[1] * vectCamPoint[1] + this->equation[2] * vectCamPoint[2] + this->equation[3]);
		Point newPoint(centreCamera.Coords()[0] + vectCamPoint[0] * t, centreCamera.Coords()[1] + vectCamPoint[1] * t, centreCamera.Coords()[2] + vectCamPoint[2] * t);
		return newPoint;
	}
}

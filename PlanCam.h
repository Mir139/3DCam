#ifndef PLANCAM_H
#define PLANCAM_H

#include "Point.h"

class PlanCam : public Point {
public:
	PlanCam();
	PlanCam(double x, double y, double z);
	PlanCam(double * coords);
	~PlanCam();
	const double * Equation() const;
	double Equation(int n) const;
	void SetEquation(double * equation);
	Point Pojection(Point centreCamera, Point myPoint) const;
	
private:
	double equation[4];
};

#endif

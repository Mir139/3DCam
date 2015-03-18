#ifndef PLANCAM_H
#define PLANCAM_H

#include "Point.h"

class PlanCam : public Point {
public:
	PlanCam();
	PlanCam(double x, double y, double z);
    PlanCam(std::vector<double> coords);
	~PlanCam();
    std::vector<double> Equation() const;
	double Equation(int n) const;
    void SetEquation(std::vector<double> equation);
    Point Pojection(Point centreCamera, std::vector<double> vectCamPoint) const;
	
private:
    std::vector<double> equation;
};

#endif

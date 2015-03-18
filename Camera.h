#ifndef CAMERA_H
#define CAMERA_H

#include "Point.h"
#include "PlanCam.h"
#include "repere.h"

class Camera : public Point {
public:
	Camera();
	Camera(double x, double y, double z);
    Camera(std::vector<double> coords);
	~Camera();
    const std::vector<double> Orientation() const;
	double Orientation(int n) const;
    void SetOrientation(std::vector<double> orientation);
    void SetOrientation(double y, double q, double j);
	double Focal() const;
	void SetFocal(double focal);
	void SetPlanCam();
    Point Projection(std::vector<double> vectCamPoint);
    Point BaseChange(Point myPoint);
    PlanCam GetPlanCam() const;
	
private:
	double focal;
	PlanCam planCam;
    Repere repere;
};

#endif

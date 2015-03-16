#ifndef CAMERA_H
#define CAMERA_H

#include "Point.h"
#include "PlanCam.h"

class Camera : public Point {
public:
	Camera();
	Camera(double x, double y, double z);
	Camera(double * coords);
	~Camera();
	const double * Orientation() const;
	double Orientation(int n) const;
	void SetOrientation(double * orientation);
	double Focal() const;
	void SetFocal(double focal);
	void SetPlanCam();
	
private:
	double orientation[3];
	double focal;
	PlanCam planCam;
};

#endif

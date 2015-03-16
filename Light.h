#ifndef LIGHT_H
#define LIGHT_H

#include <string>
#include "Point.h"

class Light : public Point {
public:
	Light();
	Light(double x, double y, double z);
	Light(double * coords);
	const double * Orientation() const;
	double Orientation(int n) const;
	void SetOrientation(double * orientation);
	std::string Type() const;
	void SetType(std::string type);
private:
	double orientation[3];
	std::string type;
};

#endif

#ifndef LIGHT_H
#define LIGHT_H

#include <string>
#include "Point.h"

class Light : public Point {
public:
	Light();
	Light(double x, double y, double z);
    Light(std::vector<double> coords);
    const std::vector<double> Orientation() const;
	double Orientation(int n) const;
    void SetOrientation(std::vector<double> orientation);
	std::string Type() const;
	void SetType(std::string type);
private:
    std::vector<double> orientation;
	std::string type;
};

#endif
